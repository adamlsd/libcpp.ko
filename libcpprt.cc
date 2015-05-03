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
try
{
	uprintf( "Hello\n" );
	tester= new TestingImpl();

	tester->core();
}
catch( ... )
{
}


void
libcpprt_close()
try
{
	uprintf( "Goodbye\n" );
	tester->core();
	delete tester;
}
catch( ... )
{
}
