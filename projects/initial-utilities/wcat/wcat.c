#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
  if (argc <= 1) {
    exit(0);
  }
  
  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }
    char line[256];
    while(fgets(line, sizeof(line), fp)) {
      printf("%s", line);
    }

    fclose(fp);     
  }

  return 0;
}
