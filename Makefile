KMOD = libcpprt
SRCS = libcpprt_entry.c libcpprt.cc
RUNTIME_SOURCES = c++_runtime.cc c++_exceptions_runtime.cc

.PATH: ${.CURDIR}/runtime
#RUNTIME_SOURCES+= typeinfo.cc libelftc_dem_gnu3.c dynamic_cast.cc
#RUNTIME_SOURCES+= exception.cc

SRCS+= $(RUNTIME_SOURCES)

CXXFLAGS+= -I. -Iinclude -std=c++11 -fno-rtti -fno-exceptions
CFLAGS+= -I. -Iinclude

.include <bsd.kmod.mk>
