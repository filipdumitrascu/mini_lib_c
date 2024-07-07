// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/**
	 * Make the appropriate system call and declare the error
	 * type in errno according to the returned value
	 */
	int ret = syscall(__NR_stat, path, buf);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
