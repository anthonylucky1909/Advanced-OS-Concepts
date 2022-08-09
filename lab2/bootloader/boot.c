#include "boot.h"

#define SECTSIZE 512
void *Memcpy(void *dst,void *src,unsigned len){
	int i = 0;
	for(i = 0; i < len; i++){
		*((unsigned char *)(dst+i)) = *((unsigned char *)(src+i));
	}
	return dst;
}

void *Memset(void *dst,unsigned char ch,unsigned len){
	int i = 0;
	for(i = 0; i < len; i++){
		*((unsigned char *)(dst+i)) = ch;
	}
	return dst;
}
void bootMain(void)
{
	int i = 0;
	int phoff = 0x34;
	int offset =0x1000;
	unsigned int elf = 0x10000;
	void (*kMainEntry)(void);
	kMainEntry = (void(*)(void))0x10000;
	struct ProgramHeader *thisph = 0x0;
	for (i = 0; i < 200; i++) 
	{
		readSect((void*)(elf + i*512), 1+i);
	}

	// TODO: 填写kMainEntry、phoff、offset...... 然后加载Kernel（可以参考NEMU的某次lab）
	kMainEntry = (void(*)(void))((struct ELFHeader *)elf)->entry;
	phoff = ((struct ELFHeader *)elf)->phoff;
	offset = ((struct ELFHeader *)elf)->phnum;
	thisph = ((struct ProgramHeader *)(elf + phoff));
	for(i = 0; i < offset; i++)
	{
		if(thisph->type == 0x1)
		{
			Memcpy((void *)thisph->vaddr, ((void *)elf+thisph->off), thisph->filesz);
			Memset((void *)thisph->vaddr+thisph->filesz, 0, thisph->memsz-thisph->filesz);
		}
		thisph++;
	}
	kMainEntry();
}
void waitDisk(void) { // waiting for disk
	while((inByte(0x1F7) & 0xC0) != 0x40);
}

void readSect(void *dst, int offset) { // reading a sector of disk
	int i;
	waitDisk();
	outByte(0x1F2, 1);
	outByte(0x1F3, offset);
	outByte(0x1F4, offset >> 8);
	outByte(0x1F5, offset >> 16);
	outByte(0x1F6, (offset >> 24) | 0xE0);
	outByte(0x1F7, 0x20);

	waitDisk();
	for (i = 0; i < SECTSIZE / 4; i ++) {
		((int *)dst)[i] = inLong(0x1F0);
	}
}
