extern "C"
{
	#include <sys/types.h>
	#include <sys/systm.h>
}

namespace cpp_runtime
{
	void *catch_impl( void *e ) noexcept
	{
		panic( "Catch not implemented." );
	}

	void *catch_impl_end( void *e ) noexcept
	{
		panic( "Catch not implemented." );
	}
}
