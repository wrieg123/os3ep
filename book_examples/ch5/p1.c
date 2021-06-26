#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) {
    //fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // child (new proc)
    printf("hello, I am child (pid:%d)\n", (int) getpid());
  } else {
    printf("hello, I am parent of %d (pid:%d)\n", rc, getpid());
  }

  return 0;
}
