// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/**
	 * Make the appropriate system call and declare the error type in
	 * errno according to the returned value (every error case is treated) 
	 */
	off_t ret = syscall(__NR_lseek, fd, offset, whence);

    if (ret < 0) {
		if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END)
			errno = EINVAL;

		else if (fd < 0)
			errno = EBADF;

		return -1;
	}

    return ret;
}
