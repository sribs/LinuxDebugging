# LinuxDebugging
Welcome to the world of demystifying the complete Linux Operating System through debugging. We will be travelling a long journey in demystifying the Linux Operating system by means of Linux Process and Kernel level debugging while encountering several scenarios.
We will be looking at various tracing, debugging and profiling tools to analyze and appreciate the working and behaviour of Linux Operating System.

# Audience
Before you have a look at the complete guide, I would recommend a good understanding the following concepts:
1. Fundamentals of Computer Architecture and Operating System.
2. Linux Administration and basic performance analysis.
3. C/C++ programming (No full fledged development experience is reuqired. Source reading capability is all what we would need)

# Introduction
Linux is a fully functional, open-source, community driven operating system. It was first developed in 1991 by Linux Torvalds on 8086 Microprocessor. SInce then, it has become one of the major operating systems in use today, bringing to the PC all the power and flexibility of a Unix workstation as well as a complete set of Internet applications and a fully functional desktop interface.
As I speak more about linux, it drives me crazy about demystifying as to how this complex operating system really works. Hence, I have decided to initiate my knowledge sharing to all of my readers and hope I can get a knowledge return indeed.
I would consider exploring Linux is to experience its behaviour completely!. Hence, I would be debugging the Linux Operating System to know more about it. 

Broadly, I would considering demystifying Linux into 2 categories:
1. Understanding the behavior of the Operating System in User Space
2. Understanding the behavior of the Operating system in Kernel Space

## Demystifying Linux Userspace
Userspace is where the applications run on the operating system. They use of various libraries and frameworks while communicating with the Kernel of the operating system to satisfy their requirements. However, it is worth to understand how important it is to understand behind the scenes of a running process and that is something I'm hoping to convey to you in A [this](https://github.com/sribs/LinuxDebugging/blob/master/Userspace/README.md) guide.

## Demystifying Linux Kernelspace.
Kernel space is a part of the system memory where the Kernel of the Operating System resides. It is the heart of the operating system and it is responsible for providing services for the processes to efficiently make use of the resources available. It is also possible that services that the kernel provide may cause the system to crash! (Excellent example that I could think of is the device driver !!). We will try exploiting and understand the behavior of the [kernel](https://github.com/sribs/LinuxDebugging/blob/master/Kernelspace/README.md) within the operating system.

## Tools Used
1. Linux Debugging in the User space : GDB, valgrind, helgrind, cachegrind, blktrace and strace
2. Linux Debugging in the Kernel soace : Crash, GDB
