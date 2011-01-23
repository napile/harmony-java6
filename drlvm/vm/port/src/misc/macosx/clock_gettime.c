#ifndef HAVE_CLOCK_GETTIME

#include <sys/time.h>
#include <errno.h>
#include <time.h>
#include "clock_gettime.h"

int clock_gettime(clockid_t clk_id, struct timespec *tp) {
	struct timeval tv;

	switch (clk_id) {
	case CLOCK_MONOTONIC:
	case CLOCK_REALTIME:
		if (gettimeofday(&tv, NULL) != 0)
			return -1;
		tp->tv_sec = tv.tv_sec;
		tp->tv_nsec = tv.tv_usec * 1000;
		return 0;
	default:
		errno = EINVAL;
		return -1;
	}
}

#endif
