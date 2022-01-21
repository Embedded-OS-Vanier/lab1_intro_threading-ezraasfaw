/****************************************************************************
*   Lab1: Introduction to multi-threading
*****************************************************************************
*	Author				Date			Version
*	Ezra-Fikru Asfaw    1/21/2020       1.0         Work on creating thread 1 and 
                                                    thread 2 that work simultaneously 
                                                    while following their dedicated time.
*****************************************************************************/

#include <Windows.h> 
#include <stdio.h>
#include <string.h>
#define HAVE_STRUCT_TIMESPEC  // for win32 only. Because TIMESPEC is re-defined inside pthread.h
#include <pthread.h>


void* thread1(void* threadid) {
    //while(1){
    for (int i = 0; i < 10; i++) {
        printf("Hello from thread1\n"); 
        Sleep(500); // wait for half a secondes
    }
    //}
    printf("Thread1: terminating!\n");
    return NULL;
}

void* thread2(void* threadid2) {
    for (int i = 0; i < 10; i++) {
        printf("Hello from thread2\n");
        Sleep(1000); // wait for 1 secondes
    }
    printf("Thread2: terminating!\n");
    return NULL;
}

int main(void)
{
    pthread_t thread_id, thread_id2;
    printf("In main: creating a thread \n");
    pthread_create(&thread_id, NULL, thread1, NULL);
    pthread_create(&thread_id2, NULL, thread2, NULL);
    //Sleep(5000); // Blocks 5 seconds
    //pthread_exit(NULL);
    pthread_join(thread_id, NULL); // waits for thread1 to terminate
    pthread_join(thread_id2, NULL); // waits for thread2 to terminate
    printf("Main: returns!\n");

}  


