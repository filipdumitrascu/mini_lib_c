// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <internal/syscall.h>

void *malloc(size_t size)
{
    return mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE |
                MAP_ANONYMOUS, -1, 0);
}

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);

    if (ptr)
        memset(ptr, 0, nmemb * size);

    return ptr;
}

void free(void *ptr)
{
    if (!ptr)
        return;

    syscall(__NR_munmap, ptr, mem_list_num_items);
}

void *realloc(void *ptr, size_t size)
{
	void *new_ptr = malloc(size);

    if (!new_ptr)
        return NULL;

    memcpy(new_ptr, ptr, size);
    free(ptr);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return realloc(ptr, nmemb * size);
}
