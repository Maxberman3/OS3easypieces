#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd = open("fork4_output.txt", O_WRONLY | O_CREAT);
  int retval=fork();
  int sz1;
  int sz2;
  if (retval<0){
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (retval==0){
    for(int i=0;i<5;i++){
      sz1=write(fd,"child writing\n",strlen("child writing\n"));
    }
  }
  else {
    wait(NULL);
    for(int i=0;i<5;i++){
      sz2=write(fd,"parent writing\n",strlen("parent writing\n"));
    }
  }
  close(fd);
  return 0;
}
