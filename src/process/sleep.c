#include <unistd.h>
#include <internal/syscall.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    /**
     * Nanosleep function has a syscall so it's
     * easier to call it without any nanoseconds
     */
	struct timespec ts;
    ts.tv_sec = seconds;
    ts.tv_nsec = 0;

	return nanosleep(&ts, NULL);
}
