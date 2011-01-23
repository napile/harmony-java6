#include <semaphore.h>
#include <time.h>

int sem_timedwait(sem_t sem, const struct timespec abs_timeout);
