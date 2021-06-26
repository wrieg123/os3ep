#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
  int x = 50;
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    x += 1;
    printf("x=%d in child | pid: %d\n", x, (int) getpid());
  } else {
    x -= 1;
    printf("x=%d in parent | pid: %d\n", x, (int) getpid());
  }
  return 0;
}
