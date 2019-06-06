#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int x=1;
  int retval=fork();
  if (retval<0){
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if(retval==0){
    x=2;
    printf("%s%d\n","This is the child, x is equal to ",x);
  }
  else{
    x=2;
    printf("%s%d\n","This is the parent, x is equal to ",x);
  }
  return 0;
}
