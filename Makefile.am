ACLOCAL_AMFLAGS = -I m4 --install

DISTCLEANFILES = *~ autoscan.log .DS_Store
MAINTAINERCLEANFILES = install-sh mkinstalldirs missing Makefile.in \
                       aclocal.m4 configure COPYING Log.cvs ChangeLog \
                       depcomp configure.scan

EXTRA_DIST = ChangeLog

SUBDIRS = . src doc test build-aux m4

VERSION = @VERSION@
PACKAGE = @PACKAGE@

ChangeLog: Log.cvs
	rcs2log -u "apw	Amos Waterland	apw@rossby.metr.ou.edu" -L $^ | \
		sed 's,/home/apw/cvsroot/stress/src/,,g' | fmt -w 78 > $@

Log.cvs:
	cvs log > $@

docs:
	$(MAKE) -C doc

tests:
	$(MAKE) -C test

configure.scan:
	autoscan

distclean-local:
	-rm -rf autom4te.cache || rmdir autom4te.cache
