#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *keyword = "trak";
int exit_code = 0;

pid_t pid, ppid;
int status = 0;

void kill_interrupt(int signo) {
  exit(exit_code);
}

int main() {
  // interrupt handlers
  signal(SIGTERM, kill_interrupt);
  signal(SIGINT, kill_interrupt);

  // keep track of parent ID for formatting
  ppid = getpid();

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      // create a chain of processes
      pid = fork();

      // if we are child, set our exit code and continue
      if (pid == 0) {
        exit_code = (keyword[i] >> j) & 1;
        continue;
      }

      // if we are the parent, wait for the child and print its exit code
      waitpid(pid, &status, 0);
      printf("%d%s", WEXITSTATUS(status), getpid() == ppid ? "\n" : "");
      exit(exit_code);
    }
  }

  // keep the child process in an infinite loop until it is killed
  while (1);

  return -1;
}
