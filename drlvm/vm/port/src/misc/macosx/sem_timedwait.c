#include <mach/mach_init.h>
#include <mach/task.h>
#include <mach/semaphore.h>
#include "sem_timedwait.h"

int sem_timedwait(sem_t sem, const struct timespec abs_timeout) {
  mach_timespec_t mach_delay = { abs_timeout.tv_sec, abs_timeout.tv_nsec };
  return semaphore_timedwait(sem, mach_delay);
}
