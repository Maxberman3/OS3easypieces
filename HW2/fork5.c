#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int retval=fork();
  if (retval<0){
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if(retval==0){
    close(STDOUT_FILENO);
    open("./fork5.output",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
    execl("/bin/ls", "ls", "-a", "..", NULL);
  }
  else{
    int wc = wait(NULL);
  }
  return 0;
}
