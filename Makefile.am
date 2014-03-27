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

## Used to be generated via CVS, but we are now using git:
ChangeLog: $(srcdir)/build-aux/gitlog-to-changelog $(srcdir)/.last-cl-gen
	if test -d $(srcdir)/.git; then                  \
	  $(srcdir)/build-aux/gitlog-to-changelog        \
	      --format='%s%n%n%b%n' --no-cluster         \
	      --strip-tab --strip-cherry-pick            \
	      -- $$(cat $(srcdir)/.last-cl-gen)..        \
	    | fmt -w 75 -t 4 > ChangeLog.tmp             \
	  && (echo; cat $(srcdir)/ChangeLog | tab2space) \
	  >> ChangeLog.tmp                               \
	  && mv -f ChangeLog.tmp $(srcdir)/ChangeLog     \
	  && rm -f ChangeLog.tmp;                        \
	fi

.last-cl-gen: Log.cvs
	if test -d $(srcdir)/.git; then      \
	  if test ! -e $@ -a -e $<; then     \
	    git mv -v $< $@;                 \
	  else                               \
	    git rev-list -n 1 HEAD | tee $@; \
	  fi;                                \
	fi

Log.cvs: NEWS
	date > $@

docs:
	$(MAKE) -C doc

tests:
	$(MAKE) -C test

configure.scan: src/stress.c
	$(AUTOSCAN)

distclean-local:
	-rm -rf autom4te.cache || rmdir autom4te.cache
