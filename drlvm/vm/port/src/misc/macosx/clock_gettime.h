#ifndef COMPAT_CLOCK_GETTIME_H_INCLUDED
#define COMPAT_CLOCK_GETTIME_H_INCLUDED

#ifndef HAVE_CLOCK_GETTIME
typedef enum {
	CLOCK_MONOTONIC,
	CLOCK_REALTIME,
} clockid_t;

int clock_gettime(clockid_t clk_id, struct timespec *tp);
#endif

#endif
