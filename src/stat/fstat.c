// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/**
	 * Make the appropriate system call and declare the error
	 * type in errno according to the returned value
	 */
	int ret = syscall(__NR_fstat, fd, st);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
