#include <unistd.h>
#include <internal/syscall.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    /**
	 * Make the appropriate system call
	 */
	return syscall(__NR_nanosleep, req, rem);
}
