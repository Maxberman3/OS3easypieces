#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  /* code */
  if(argc !=2){
    return 1;
  }
  struct stat fileStat;
  if(stat(argv[1],&fileStat)<0){
    return 1;
  }
  printf("Information for %s\n",argv[1]);
  printf("---------------------------\n");
  printf("File Size: \t\t%d bytes\n",fileStat.st_size);
  printf("Number of Links: \t%d\n",fileStat.st_nlink);
  printf("File inode: \t\t%d\n",fileStat.st_ino);
  return 0;
}
