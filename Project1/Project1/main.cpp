/****************************************************************************
*
*
*	Author				Date			Version
*	
*****************************************************************************/

#include <Windows.h> 
#include <stdio.h>
#include <string.h>
#define HAVE_STRUCT_TIMESPEC  // for win32 only. Because TIMESPEC is re-defined inside pthread.h
#include <pthread.h>


           

int main(void)
{
    pthread_t thread_id;
    printf("In main: creating a thread \n");
    pthread_create(&thread_id, NULL, thread1, NULL);
    Sleep(5000); // Blocks 5 seconds
    printf("Main: returns! \n");

}  


