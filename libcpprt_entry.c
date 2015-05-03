#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

static void load_mod( struct module *module, void *arg );
static void unload_mod( struct module *module, void *arg );

static int
event_handler( struct module *module, int event, void *arg )
{
	switch( event )
	{
		case MOD_LOAD:   load_mod( module, arg ); break;
		case MOD_UNLOAD: unload_mod( module, arg ); break;
		default: return EOPNOTSUPP;
	}

	return 0;
}

void libcpprt_entry();
void libcpprt_close();

static void
load_mod()
{
	uprintf( "Hello -- C-language\n" );
	libcpprt_entry();
}

static void
unload_mod()
{
	uprintf( "Goodbye -- C-language\n" );
	libcpprt_close();
}


// module
// MODULE_DEPEND
static moduledata_t cpprt_conf =
{
	"cpprt",
	event_handler,
	NULL
};

//MODULE_DEPEND( cpprt, kernel, 10, 100, 10 );
//DECLARE_MODULE( cpprt, cpprt_conf, SI_SUB_KLD, SI_ORDER_ANY );
/*#define	DECLARE_MODULE_WITH_MAXVER(name, data, sub, order, maxver)	\ */
MODULE_DEPEND( cpprt, kernel, 100000, __FreeBSD_version, MODULE_KERNEL_MAXVER );
MODULE_METADATA( _md_cpprt, MDT_MODULE, &cpprt_conf, "cpprt" );
SYSINIT( cpprtmodule, SI_SUB_KLD, SI_ORDER_ANY, module_register_init, &cpprt_conf );
