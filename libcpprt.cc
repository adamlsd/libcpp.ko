extern "C"
{
	#include <sys/param.h>
	#include <sys/module.h>
	#include <sys/kernel.h>
	#include <sys/systm.h>

	void libcpprt_entry();
	void libcpprt_close();
}

class Testing
{
	public:
		explicit inline Testing() {}
		virtual ~Testing() {}

		virtual void core() const= 0;
};

Testing *tester= nullptr;

class TestingImpl : public Testing
{
	public:
		virtual void
		core() const override
		{
			uprintf( "In impl." );
		}
};

void
libcpprt_entry()
{
	uprintf( "Hello\n" );
	if( 1 ) tester= new TestingImpl();
}


void
libcpprt_close()
{
	uprintf( "Goodbye\n" );
	if( 1 ) delete tester;
}
