// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/**
	 * Make the appropriate system call and declare the error
	 * type in errno according to the returned value
	 */
	int ret = syscall(__NR_ftruncate, fd, length);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
