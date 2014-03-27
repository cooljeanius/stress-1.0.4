AUTOMAKE_OPTIONS = 1.13.1 gnits

ACLOCAL_AMFLAGS = -I m4 --install

DISTCLEANFILES = *~ autoscan.log .DS_Store
MAINTAINERCLEANFILES = install-sh mkinstalldirs missing Makefile.in \
                       aclocal.m4 configure COPYING Log.cvs ChangeLog \
                       depcomp configure.scan

EXTRA_DIST = ChangeLog

SUBDIRS = . src doc test build-aux m4

VERSION = @VERSION@
PACKAGE = @PACKAGE@

RCS2LOG = @RCS2LOG@
CVSBIN = @CVSBIN@
AUTOSCAN = @AUTOSCAN@

## TODO: remove the assumption about who the author is:
## (tabs are required by format required for rcs2log's '-u' flag)
ChangeLog: Log.cvs
	$(RCS2LOG) -u "apw	Amos Waterland	apw@rossby.metr.ou.edu"  \
		-c -i 4 -l 75 t 4 -v -L $^ |  \
		sed 's,/home/apw/cvsroot/stress/src/,,g' |  \
		fmt -w 75 > $@

Log.cvs: NEWS
	$(CVSBIN) log > $@ || date > $@

docs:
	$(MAKE) -C doc

tests:
	$(MAKE) -C test

configure.scan: src/stress.c
	$(AUTOSCAN)

distclean-local:
	-rm -rf autom4te.cache || rmdir autom4te.cache
