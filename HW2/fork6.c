#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  char* msg="hello world";
  char inbuf[strlen(msg)];
  int fd[2],nbytes;
  int retval=fork();
  if(pipe(fd)<0){
    fprintf(stderr, "%s\n","Pipe failed");
  }
  if (retval<0){
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (retval==0){
    write(fd[1],msg,strlen(msg));
    close(fd[1]);
    wait(NULL);
  }
  else{
    close(fd[1]);
    while ((nbytes = read(fd[0], inbuf, strlen(msg))) > 0){
            printf("% s\n", inbuf);
          }
        if (nbytes != 0){
            exit(2);
          }
        printf("Finished reading\n");
      }
  return 0;
}
