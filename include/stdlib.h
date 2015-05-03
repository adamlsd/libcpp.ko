#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif
#include <sys/libkern.h>
#include <sys/malloc.h>

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace cxxruntime
{

	extern void *malloc( std::size_t );
	extern void *realloc(void *, std::size_t);
	extern void free(void *);

	extern void *calloc( std::size_t, std::size_t );
}
#define __extern_c extern "C"
#else
#define __extern_c extern
#endif

__extern_c void *cxxruntime_malloc(size_t);

__extern_c void *cxxruntime_realloc(void *, size_t);
__extern_c void cxxruntime_free(void *);

__extern_c char *cxxruntime_strdup(const char *);
__extern_c void abort() __attribute__(( __noreturn__ ));
