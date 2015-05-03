extern "C"
{
	#include <sys/types.h>
	#include <sys/systm.h>
	#include <sys/param.h>
	#include <sys/malloc.h>
	#include <sys/kernel.h>
}

extern "C" void *__cxa_begin_catch( void *e ) noexcept;

#include <stdlib.h>
namespace cxxruntime
{
	MALLOC_DECLARE( cxxruntime_pool );
}

namespace std
{
	using size_t= ::size_t;

	void terminate() __attribute__(( __noreturn__ ));
}


void *operator new( const std::size_t s )
{
	return malloc( s, cxxruntime::cxxruntime_pool, M_WAITOK );
}



void operator delete( void *const p )
{
	return free( p, cxxruntime::cxxruntime_pool );
}



namespace std
{
	void
	terminate()
	{
		panic( "Kernel panic from C++ runtime's `std::terminate`." );
	}
}

namespace cpp_runtime
{
	void *catch_impl( void *e ) noexcept;
	void *catch_impl_end( void *e ) noexcept;
}

extern "C" void *
disabled__cxa_begin_catch( void *e ) noexcept
{
	return cpp_runtime::catch_impl( e );
}
extern "C" void *
disabled__cxa_end_catch( void *e ) noexcept
{
	return cpp_runtime::catch_impl_end( e );
}

//namespace __cxxabiv1
//{
	//class __class_type_info
	//{
	//};
//}


namespace cxxruntime
{
	MALLOC_DEFINE( cxxruntime_pool, "C++ pool", "Pool for C++ runtime behavior" );

	void *
	malloc( std::size_t s )
	{
		return ::malloc( s, cxxruntime_pool, M_WAITOK );
	}

	void *
	realloc( void *p, std::size_t s )
	{
		return ::realloc( p, s, cxxruntime_pool, M_WAITOK );
	}

	void
	free( void *p )
	{
		return ::free( p, cxxruntime_pool );
	}

	void *
	calloc( const std::size_t number, const std::size_t size )
	{
		return ::malloc( number * size, cxxruntime_pool, M_WAITOK | M_ZERO );
	}
}

extern "C" void *
cxxruntime_malloc( const size_t s )
{
	return cxxruntime::malloc( s );
}

extern "C" void *
cxxruntime_realloc( void *p, size_t s )
{
	return cxxruntime::realloc( p, s );
}

extern "C" void
cxxruntime_free( void *p )
{
	return cxxruntime::free( p );
}

extern "C" char *
cxxruntime_strdup( const char *s )
{
	return strdup( s, cxxruntime::cxxruntime_pool );
}

extern "C" void
abort()
{
	panic( "C++ Runtime: abort" );
}

#if 0

 typedef enum
{
	_URC_OK = 0,                /* operation completed successfully */
	_URC_FOREIGN_EXCEPTION_CAUGHT = 1,
    _URC_END_OF_STACK = 5,
	_URC_HANDLER_FOUND = 6,
	_URC_INSTALL_CONTEXT = 7,
	_URC_CONTINUE_UNWIND = 8,
	_URC_FAILURE = 9,            /* unspecified failure of some kind */
	_URC_FATAL_PHASE1_ERROR = _URC_FAILURE
} _Unwind_Reason_Code;

struct _Unwind_Exception;
struct _Unwind_Context;
typedef uint32_t _Unwind_State;

extern "C" _Unwind_Reason_Code __gxx_personality_v0(_Unwind_State state,
                         struct _Unwind_Exception *exceptionObject,
                         struct _Unwind_Context *context){abort();}
#endif
