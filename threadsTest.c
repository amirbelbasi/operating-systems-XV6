#include "types.h"
#include "stat.h"
#include "user.h"

#define PAGESIZE 4096

int
thread_creator(void (*fn) (void *), void *arg)
{


    void *fptr = malloc(2 * PAGESIZE);
    void *stack;

    if(fptr == 0)
    return -1;

    int mod = (uint)fptr % PAGESIZE;


    if(mod == 0)
        stack = fptr;
    else
        stack = fptr + (PAGESIZE - mod);

    int thread_id = thread_create((void*)stack);


    if(thread_id < 0)
        printf(1, "thread create failed\n");
    

    else if(thread_id == 0){

        (fn)(arg);

        free(stack);
        exit(); //child won't make it out of this function
    }
    return thread_id;

}

void childPrint(void* args){
    printf(1, "11111111111111111111111111%d\n", *(int*)args);
}

int main(void){
    int argument = 0x0F01; //3841
    int thread_id = thread_creator(&childPrint, (void*)&argument);
    if(thread_id < 0)
    {
        printf(1, "000000000000000000000000\n");
        exit();
    }
    
    //join();
    printf(1, "thread_id is: %d\n", thread_id);
    exit();
}