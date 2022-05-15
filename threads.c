// #include "types.h"
// #include "stat.h"
// #include "user.h"

// int x = 0;

// int main(int argc, char *argv[]){
//     void* stack = malloc(2 * 4096);
//     printf(1, "Stack is at %p\n", stack);
//     //int tid = fork();
//     int tid = thread_create((void*)stack);
//     if(tid < 0){
//         printf(2, "error!\n");
//     }
//     else if(tid == 0){
//         for(;;){
//             x++;
//             sleep(100);
//         }
//     }
//     else{
//         for(;;){
//             printf(1, "x = %d\n", x);
//             sleep(100);
//         }
//     }
//     exit();
// }