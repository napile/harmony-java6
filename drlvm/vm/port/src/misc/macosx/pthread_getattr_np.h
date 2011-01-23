#ifndef COMPAT_PTHREAD_GETATTR_NP_H_INCLUDED
#define COMPAT_PTHREAD_GETATTR_NP_H_INCLUDED

#ifndef HAVE_PTHREAD_GETATTR_NP
#include <pthread.h>

int pthread_getattr_np(pthread_t thread_id, pthread_attr_t *attr);

#endif /* !defined(HAVE_PTHREAD_GETATTR_NP) */

#endif /* !defined(COMPAT_PTHREAD_GETATTR_NP_H_INCLUDED) */
