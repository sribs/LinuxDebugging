#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

pthread_mutex_t read_mutex;
pthread_mutex_t write_mutex;
pthread_mutex_t lock;

void * writing(void *temp) {
    char *ret;
    FILE *file1;
    char *str;
    pthread_mutex_lock(&write_mutex);
    sleep(5);
    pthread_mutex_lock(&read_mutex);
        str=(char *)malloc(10*sizeof(char));
        file1=fopen("temp","w");
        scanf("%s",str);
        fprintf(file1,"%s",str);
        fclose(file1);
    pthread_mutex_unlock(&read_mutex);
    pthread_mutex_unlock(&write_mutex);
    return ret;
}


void * reading(void *temp) {
    char *ret;
    FILE *file1;
    char *str;
    pthread_mutex_lock(&read_mutex);
    sleep(5);
    pthread_mutex_lock(&write_mutex);
        printf("\n Opening file \n");
        file1=fopen("temp","r");
        str=(char *)malloc(10*sizeof(char));
        fscanf(file1,"%s",str);
        printf("\n Message from file is %s \n",str);

        fclose(file1);

    pthread_mutex_unlock(&write_mutex);
    pthread_mutex_unlock(&read_mutex);
    return ret;
}


void starve_memory(void *vargp) 
{ 
    int i=0;
    while(1)
    {
        sleep(0.01); 
        pthread_mutex_lock(&lock);
        short *p = (short *)malloc(sizeof(short));
        pthread_mutex_unlock(&lock); 
        i++;
    } 
} 

void starve_cpu()
{
    int i=0;
    while(1)
    {
         
        pthread_mutex_lock(&lock);
        //printf("Generating CPU \n");
        pthread_mutex_unlock(&lock); 
        i++;
    } 
}

void generate_null_pointer()
{
    int a, b, c; // some integers
    int *pi;     // a pointer to an integer

    a = 5;
    pi = &a; // pi points to a
    b = *pi; // b is now 5
    pi = NULL;
    c = *pi; // this is a NULL pointer dereference
}

void starve_io()
{
    FILE *fp; fp = open("iofile","r");
        while(1){
            fseek(fp,0,SEEK_END);
            rewind(fp);
        }
}

void seg_fault_exer1() { 

    char* name = malloc(strlen("Hello World")) ; 
    name = strcpy(name,"Hello super World"); 
    printf("%s \n", name); 
} 

void seg_fault_exer2() {
    int* ptr = malloc(4); 
    free(ptr); 
    scanf("%d",*ptr);  
}

void seg_fault_exer3(int*** array){

    int** arrayint = (int**)malloc(2*100*sizeof(int*)); 
    for (int i=0;i<100;i++) 
       arrayint[i] = (*array)[i]; 
    free(*array); 
    array = &arrayint;  
} 

void seg_fault_exer4() {
    
    int i=0,n=1000; 
    char name[32]; 
    char* A[n]; 
    FILE* infile = fopen("temp","r"); 
    while (fscanf(infile,"%s", name) > 0) 
        strcpy(A[i++],name); 
/*shift all elements to right by 1*/ 
    for (int j=i; j>0; j--)   
         A[i+1] = A[i] ;  
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        return "Not suitable arguments";
    }
    printf("%c",argv[1][0]);
    switch (argv[1][0])
    {
        case '1':
            { 
                pthread_t thread_id[8]; 
                pthread_create(&thread_id[0], NULL, starve_cpu, NULL);
                pthread_create(&thread_id[1], NULL, starve_cpu, NULL);
                pthread_create(&thread_id[2], NULL, starve_cpu, NULL);
                pthread_create(&thread_id[3], NULL, starve_cpu, NULL);
                pthread_create(&thread_id[4], NULL, starve_cpu, NULL);
                pthread_create(&thread_id[5], NULL, starve_cpu, NULL);
                pthread_create(&thread_id[6], NULL, starve_cpu, NULL);
                pthread_create(&thread_id[7], NULL, starve_cpu, NULL);
                pthread_create(&thread_id[8], NULL, starve_cpu, NULL);
                pthread_create(&thread_id[9], NULL, starve_cpu, NULL);
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
            }
            break;
        
        case '2':
        {
            pthread_t thread_id[8]; 
            pthread_create(&thread_id[0], NULL, starve_memory, NULL);
            pthread_create(&thread_id[1], NULL, starve_memory, NULL);
            pthread_create(&thread_id[2], NULL, starve_memory, NULL);
            pthread_create(&thread_id[3], NULL, starve_memory, NULL);
            pthread_create(&thread_id[4], NULL, starve_memory, NULL);
            pthread_create(&thread_id[5], NULL, starve_memory, NULL);
            pthread_create(&thread_id[6], NULL, starve_memory, NULL);
            pthread_create(&thread_id[7], NULL, starve_memory, NULL);
            pthread_create(&thread_id[8], NULL, starve_memory, NULL);
            pthread_create(&thread_id[9], NULL, starve_memory, NULL);
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
            break;
        }
        case '3':
            /*{ 
                pthread_t thread_id[8]; 
                pthread_create(&thread_id[0], NULL, starve_io, NULL);
                pthread_create(&thread_id[1], NULL, starve_io, NULL);
                pthread_create(&thread_id[2], NULL, starve_io, NULL);
                pthread_create(&thread_id[3], NULL, starve_io, NULL);
                pthread_create(&thread_id[4], NULL, starve_io, NULL);
                pthread_create(&thread_id[5], NULL, starve_io, NULL);
                pthread_create(&thread_id[6], NULL, starve_io, NULL);
                pthread_create(&thread_id[7], NULL, starve_io, NULL);
                pthread_create(&thread_id[8], NULL, starve_io, NULL);
                pthread_create(&thread_id[9], NULL, starve_io, NULL);
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
                exit(0); 
            }*/
            starve_io();
            break;

        case '4':
            generate_null_pointer();
            break;

        case '5':
        {
            int** A; 
            seg_fault_exer3(&A);
            break;
        }

        case '6':
            seg_fault_exer1();
            break;

        case '7':
            seg_fault_exer2();
            break;

        case '8':
            seg_fault_exer4();
            break;

        case '9':
        {
            pthread_t thread_id,thread_id1;
            pthread_attr_t attr;
            int ret; void *res;
            ret=pthread_create(&thread_id,NULL,&writing,NULL);
            ret=pthread_create(&thread_id1,NULL,&reading,NULL);
            printf("\n Created thread");
            pthread_join(thread_id,&res);
            pthread_join(thread_id1,&res);
            break;
        }

        default:
            printf("No such options exists");
            break;
    }

}