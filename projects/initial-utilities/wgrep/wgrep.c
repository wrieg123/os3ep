#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  } else if (argc == 2) {
      char* line = NULL;
      size_t len = 0;
      ssize_t read;

      while((read = getline(&line, &len, stdin)) != -1) {
        if (strstr(line, argv[1]) != NULL) {
          printf("%s",line);
        }
      }
  } else {
    for (int i = 2; i < argc; i++) {
      FILE *fp = fopen(argv[i], "r");

      if (fp == NULL) {
        printf("wgrep: cannot open file\n");
        exit(1);
      }

      char* line = NULL;
      size_t len = 0;
      ssize_t read;
    
      while((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, argv[1]) != NULL) {
          printf("%s",line);
        }
      }

      fclose(fp);
      if(line) free(line);
    }
  }

  return 0;
}
