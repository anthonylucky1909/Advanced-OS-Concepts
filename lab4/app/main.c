#include "lib.h"
#include "types.h"
#define N 5
sem_t fk[5];
int time[5];
void philosopher(int i)
{
	while(time[i]--)
	{
		printf("%d is thinking \n",i);
		if(i %2==0)
		{
			sem_wait(&fk[i]);
			sem_wait(&fk[(i+1%N)]);
		}
		else 
		{
			sem_wait(&fk[(i+1)%N]);
			sem_wait(&fk[i]);
		}
		printf("%d is eating\n",i);
		sleep(60);
		sem_post(&fk[i]);
		sem_post(&fk[(i+1)%N]);
		printf("%d end!\n",i);
	}
	return;
}


int uEntry(void) 
{

	// 测试scanf	
	int dec = 0;
	int hex = 0;
	char str[6];
	char cha = 0;
	int ret = 0;
	while(1){
		printf("Input:\" Test %%c Test %%6s %%d %%x\"\n");
		ret = scanf(" Test %c Test %6s %d %x", &cha, str, &dec, &hex);
		printf("Ret: %d; %c, %s, %d, %x.\n", ret, cha, str, dec, hex);
		//break;	
		if (ret == 4)
			break;
	}
	
	// 测试信号量
	int i = 4;
	sem_t sem;
	printf("Father Process: Semaphore Initializing.\n");
	ret = sem_init(&sem, 0);
	if (ret == -1) {
		printf("Father Process: Semaphore Initializing Failed.\n");
		exit();
	}

	ret = fork();
	if (ret == 0) {
		while( i != 0) {
			i --;
			printf("Child Process: Semaphore Waiting.\n");
			sem_wait(&sem);
			printf("Child Process: In Critical Area.\n");
		}
		printf("Child Process: Semaphore Destroying.\n");
		sem_destroy(&sem);
		exit();
	}
	else if (ret != -1) {
		while( i != 0) {
			i --;
			printf("Father Process: Sleeping.\n");
			sleep(128);
			printf("Father Process: Semaphore Posting.\n");
			sem_post(&sem);
		}
		printf("Father Process: Semaphore Destroying.\n");
		sem_destroy(&sem);
		exit();
	}

	// For lab4.3
	// TODO: You need to design and test the philosopher problem.
	// Note that you can create your own functions.
	// Requirements are demonstrated in the guide.
	
	//哲学家
	int temp =0;
	printf("%d",temp);
	for(int i =0;i <5;i++)
	{
		time[i]=5;
		temp=sem_init(&fk[i],1);
		if(temp==-1)
		{
			printf("Semaphore %d Init Fail\n",i);
			exit();
		}
	}
	temp =fork();
	if(temp==0)
	{
		philosopher(2);
		exit();
	}
	temp=fork();
	if(temp==0)
	{
		philosopher(3);
		exit();
	}
	//生产者消费者问题

	//读者写者问题
	

	exit(0);
	return 0;
}
