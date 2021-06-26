#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("This is child w/ pid=%d\n", (int) getpid());
  } else {
    wait(NULL); // this isn't correct but whatever
    printf("This is parent w/ pid=%d\n", (int) getpid());
  }
  return 0;
}
