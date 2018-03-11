#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int num, char* argc[]){

  if(argc[1] != NULL){
    num = atoi(argc[1]);
    pid_t pid;
    pid = fork();

    if (pid < 0){
      perror("Error calling fork().");
      return -1;
    }

    else if (pid == 0){
      printf("\nChild Process\n Collatz: ");
      while(num != 1) {
        if (num % 2 == 0 ) {
          printf("%d ", num);
          num /= 2;
        }
        else {
          printf("%d ", num);
          num = (3*num) + 1;
        }
      }
      printf("%d", 1); 
    }

    else{
      wait(NULL);
      printf("\nChild process has finished. This is the FATHER process\n");
    }
  }
  else{ 
    printf("No arguments were added when the program was called");
  }

  return 0;
}
