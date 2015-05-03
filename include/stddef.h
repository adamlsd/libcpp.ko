#ifdef __cplusplus
extern "C"
{
#endif
	#include <sys/types.h>
	#include <sys/stddef.h>
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#undef NULL
#define NULL (nullptr)
#else
#endif

#ifdef __cplusplus
namespace std
{
	using size_t= ::size_t;
	using ptrdiff_t= ::ptrdiff_t;
}
#endif
