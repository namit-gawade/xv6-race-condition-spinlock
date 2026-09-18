#include "types.h"
#include "stat.h"
#include "user.h"

#define NPROCS 4
#define NINCS 1000

int
main(void)
{
  int i;
  int j;
  int pid;

  printf(1, "Starting race condition test...\n");

  for(i = 0; i < NPROCS; i++){
    pid = fork();

    if(pid == 0){
      for(j = 0; j < NINCS; j++)
        increment_counter();

      exit();
    }
  }

  for(i = 0; i < NPROCS; i++)
    wait();

  printf(1, "Expected counter value: %d\n", NPROCS * NINCS);
  printf(1, "Actual counter value: %d\n", get_counter());

  exit();
}
