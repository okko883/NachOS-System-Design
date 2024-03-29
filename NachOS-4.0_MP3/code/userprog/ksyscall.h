/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"


void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}
//HW1-1: PrintInt
void SysPrintInt(int num)
{
	kernel->interrupt->PrintInt(num);
}

//HW1-2: Open, Write, Read & Close File
OpenFileId SysOpen(char *name)
{
	return kernel->interrupt->Open(name);
}

int SysWrite(char *buffer, int size, OpenFileId id)
{
	return kernel->interrupt->Write(buffer, size, id);
}

int SysRead(char *buffer, int size, OpenFileId id)
{
	return kernel->interrupt->Read(buffer, size, id);
}

int SysClose(OpenFileId id)
{
	return kernel->interrupt->Close(id);	
}




#endif /* ! __USERPROG_KSYSCALL_H__ */
