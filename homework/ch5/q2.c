#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  close(STDOUT_FILENO);
  open("./q2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("This is coming from child w/ pid=%d\n", (int) getpid());
  } else {
    printf("This is coming from parent w/ pid=%d\n", (int) getpid());
  }
  return 0;
}
