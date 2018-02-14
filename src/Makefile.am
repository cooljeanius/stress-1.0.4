VERSION = \"@VERSION@\"
PACKAGE = \"@PACKAGE@\"

AM_WARNFLAGS = -Wall -Wimplicit -Wmissing-field-initializers -Wmissing-prototypes -Wreturn-type -Wmissing-braces -Wparentheses -Wswitch -Wunused-function -Wunused-label -Wunused-parameter -Wunused-variable -Wimplicit
AM_OPTFLAGS = -ggdb -O0
AM_CFLAGS = -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -DPACKAGE=${PACKAGE} -DVERSION=${VERSION} $(AM_WARNFLAGS) $(AM_OPTFLAGS)

bin_PROGRAMS = stress
stress_SOURCES = stress.c stress.h
stress_MANS = stress.1

EXTRA_DIST = $(stress_MANS) ../doc/stress.1
DISTCLEANFILES = .DS_Store ../doc/stress.1
MAINTAINERCLEANFILES = $(stress_MANS)

stress.1: ../doc/stress.1
	$(MAKE) -C ../doc stress.1
	test -e ../doc/stress.1 && cp -v ../doc/stress.1 .

distclean-local:
	rm -rf *.dSYM || rmdir *.dSYM

if BUILD_STATICLIB
lib_LIBRARIES = libstress.a
libstress_a_SOURCES = stress.c stress.h
include_HEADERS = stress.h
endif
## (end BUILD_STATICLIB)
