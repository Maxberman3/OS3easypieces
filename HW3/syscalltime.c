#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  struct timeval start,interim,end;
  double a,b,c,diff,avgtime;
  a=gettimeofday(&start,NULL);
  for(int i=0;i<999999;i++){
    c=gettimeofday(&interim,NULL);
  }
  b=gettimeofday(&end,NULL);
  diff=end.tv_usec-start.tv_usec;
  avgtime=diff/1000000;

  printf("%s%f\n","The average time for a sys call is: ",avgtime);
  return 0;
}
