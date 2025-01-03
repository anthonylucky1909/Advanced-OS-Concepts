# Operating System Design & Implementation: Advanced Concepts

# Project Overview

This repository contains a series of lab experiments focused on the design and implementation of low-level system software. The experiments involve building bootloaders, kernels, and user applications. The project structure includes various tools and scripts used to generate and configure system components. The main focus is on understanding system bootstrapping, kernel development, and creating user-level applications in a simulated or real embedded environment.

---

## Directory Structure

### **lab1**
Contains the first lab experiment files:

- **app**: Application files for the lab experiment.
- **Makefile**: Build file to compile and link the application.
- **bootloader**: Bootloader source files.
  - **boot.c**: Bootloader C code.
  - **boot.h**: Header for bootloader functions.
  - **start.s**: Assembly code for bootloader startup.
- **utils**: Utilities for the bootloader and application.
  - **genboot.pl**: Script to generate bootloader configurations.
  - **Makefile**: Build file for utilities.

### **lab2**
Files for the second lab experiment:

- **app**: Application source files.
  - **Makefile**: Build file for the app.
  - **main.c**: Main C file for the application.
- **bootloader**: Bootloader source files.
  - **boot.c**: Bootloader C file.
  - **boot.h**: Bootloader header file.
  - **start.S**: Assembly code for bootloader.
- **kernel**: Kernel source files.
  - **include**: Kernel include files.
  - **lib**: Kernel libraries and headers.
  - **Makefile**: Kernel build configuration.
  - **main.c**: Main kernel file.
  - **syscall.c**: System call implementation.
  - **types.h**: Type definitions.
- **utils**: Utility scripts.
  - **Makefile**: Build file for utilities.

### **lab3**
Contains files for the third lab experiment:

- **app**: Application source files.
  - **Makefile**: Build file for the application.
  - **main.c**: Main application file.
- **app_print**: Files related to app printing functionality.
  - **Makefile**: Build file for app_print.
  - **main.c**: Main file for app_print.
- **bootloader**: Bootloader source files.
  - **boot.c**: Bootloader C file.
  - **boot.h**: Bootloader header file.
  - **start.S**: Bootloader assembly code.
- **kernel**: Kernel source files.
  - **include**: Kernel include files.
  - **lib**: Kernel libraries.
  - **Makefile**: Kernel build file.
  - **syscall.c**: System call implementation.
  - **types.h**: Type definitions.
- **utils**: Utility scripts for lab 3.
  - **genApp.pl**: Script to generate app configurations.
  - **genBoot.pl**: Script to generate bootloader configurations.
  - **genKernel.pl**: Script to generate kernel configurations.
  - **Makefile**: Build file for utils.

### **lab4**
Contains files for the fourth lab experiment:

- **app**: Application files.
  - **Makefile**: Build file for the application.
  - **main.c**: Main application source code.
- **test**: Testing files for the lab experiment.
  - **app**: Test application files.
- **bootloader**: Bootloader source files.
- **kernel**: Kernel source files.
  - **lib**: Kernel libraries.
  - **utils**: Utility files for the kernel and bootloader.
- **Makefile**: Main build file for lab4.

---

## Key Components

- **Bootloader**: A small program responsible for loading the main operating system or application from storage to memory and executing it.
- **Kernel**: The core part of the operating system that manages resources, communication between hardware and software, and system calls.
- **Application**: User-level programs that interact with the kernel and perform specific tasks.
- **System Utilities**: Helper scripts and files to generate or configure parts of the system, such as the bootloader and kernel.

---

## Usage

1. **Build the System**: Each lab directory contains a `Makefile`. Run `make` to build the respective components (bootloader, kernel, app).
2. **Run the System**: Once the components are built, they can be tested on a simulated environment or loaded onto a hardware platform.

---

## Additional Information

This project focuses on understanding low-level programming and the architecture of embedded systems. It includes practical exercises in system bootstrapping, kernel design, application development, and the interactions between these components.

---

## License

This project is licensed under the [MIT License](LICENSE).
