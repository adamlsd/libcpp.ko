#include <sys/types.h>
#include <sys/systm.h>

#ifdef __cplusplus
#define __extern_C extern "C"
#else
#define __extern_C extern
#endif

enum FILE{ stdin, stdout, stderr };

#define fprintf( file, format, ... ) printf( format, ## __VA_ARGS__ )
