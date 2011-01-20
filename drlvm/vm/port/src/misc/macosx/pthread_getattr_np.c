#ifndef HAVE_PTHREAD_GETATTR_NP

#include <sys/types.h>
#include <string.h>
#include <sched.h>
#include <time.h>
#include <_types.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/errno.h>

int pthread_getattr_np(pthread_t thread_id, pthread_attr_t *attr) {
  return 0;
}

#endif /* !defined(HAVE_PTHREAD_GETATTR_NP) */
