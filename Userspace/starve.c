#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

pthread_mutex_t lock;
  
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
void *myThreadFun(void *vargp) 
{ 
    int i=0;
    while(1)
    {
//        sleep(0.01); 
        pthread_mutex_lock(&lock);
        short *p = (short *)malloc(sizeof(short));
        pthread_mutex_unlock(&lock); 
        i++;
    } 
} 
   
int main() 
{ 
    pthread_t thread_id[8]; 
    printf("Before Thread\n"); 
    pthread_create(&thread_id[0], NULL, myThreadFun, NULL);
    pthread_create(&thread_id[1], NULL, myThreadFun, NULL);
    pthread_create(&thread_id[2], NULL, myThreadFun, NULL);
    pthread_create(&thread_id[3], NULL, myThreadFun, NULL);
    pthread_create(&thread_id[4], NULL, myThreadFun, NULL);
    pthread_create(&thread_id[5], NULL, myThreadFun, NULL);
    pthread_create(&thread_id[6], NULL, myThreadFun, NULL);
    pthread_create(&thread_id[7], NULL, myThreadFun, NULL);
    pthread_create(&thread_id[8], NULL, myThreadFun, NULL);
    pthread_create(&thread_id[9], NULL, myThreadFun, NULL);
    pthread_join(thread_id[0], NULL); 
    pthread_join(thread_id[1], NULL); 
    pthread_join(thread_id[2], NULL); 
    pthread_join(thread_id[3], NULL); 
    pthread_join(thread_id[4], NULL); 
    pthread_join(thread_id[5], NULL); 
    pthread_join(thread_id[6], NULL);
    pthread_join(thread_id[7], NULL); 
    pthread_join(thread_id[8], NULL); 
    pthread_join(thread_id[9], NULL);  
    printf("After Thread\n"); 
    exit(0); 
}
