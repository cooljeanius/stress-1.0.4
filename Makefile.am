AUTOMAKE_OPTIONS = 1.11 gnits

ACLOCAL_AMFLAGS = -I m4 --install

DISTCLEANFILES = *~ autoscan.log .DS_Store ./configure.scan \
                 ./doc/stress.1 ./src/stress.1
MAINTAINERCLEANFILES = install-sh mkinstalldirs missing \
                       Log.cvs depcomp configure.scan

EXTRA_DIST = ChangeLog .last-cl-gen Makefile.spec README.md \
             ./doc/stress.1 ./src/stress.1 ./build-aux/gitlog-to-changelog

SUBDIRS = . src doc test build-aux m4

VERSION = @VERSION@
PACKAGE = @PACKAGE@

AUTOSCAN = @AUTOSCAN@

AM_DISTCHECK_DVI_TARGET = docs

## Used to be generated via CVS, but we are now using git:
ChangeLog: $(srcdir)/build-aux/gitlog-to-changelog $(srcdir)/.last-cl-gen
	-if test -d $(srcdir)/.git && test -x "`which git`"; then \
	  $(srcdir)/build-aux/gitlog-to-changelog             \
	      --format='%s%n%n%b%n' --no-cluster              \
	      --strip-tab --strip-cherry-pick                 \
	      -- $$(cat $(srcdir)/.last-cl-gen)..             \
	    >> ChangeLog.tmp                                  \
	  && (echo; cat $(srcdir)/ChangeLog) >> ChangeLog.tmp \
	  && mv -fv ChangeLog.tmp $(srcdir)/ChangeLog         \
	  && rm -fv ChangeLog.tmp;                            \
	else                                                  \
	  touch ChangeLog;                                    \
	fi

## I think because I split this up from the above target, this now gets
## regenerated first instead of second, which means that we need the
## second-most recent revision to compare against, NOT the most recent one
## (hence the pipe through `tail`):
.last-cl-gen: NEWS
	if test -d $(srcdir)/.git; then    \
	  git rev-list -n 2 HEAD | tail -n 1 | tee $@; \
	fi

update-ChangeLog:
	touch NEWS && $(MAKE) ChangeLog
.PHONY: update-ChangeLog

docs:
	$(MAKE) -C doc
.PHONY: docs

./doc/stress.1: docs
	$(MAKE) -C doc stress.1

./src/stress.1: docs
	$(MAKE) -C src stress.1

tests:
	$(MAKE) -C test
.PHONY: tests

configure.scan: src/stress.c
	$(AUTOSCAN) || touch configure.scan

distclean-local:
	-rm -rf autom4te.cache || rmdir autom4te.cache
.PHONY: distclean-local

maintainerclean-local:
	-rm -rf $(PACKAGE)-$(VERSION) || rmdir $(PACKAGE)-$(VERSION)
.PHONY: maintainerclean-local

check-local: configure.scan build-aux/test-driver
	@test -x src/stress || true
.PHONY: check-local

build-aux/compile: build-aux/Makefile m4/libtool.m4 m4/ltoptions.m4 m4/ltsugar.m4 m4/ltversion.m4 m4/lt~obsolete.m4 aclocal.m4 configure.ac
	-$(MAKE) -C build-aux compile

build-aux/test-driver: build-aux/Makefile m4/libtool.m4 m4/ltoptions.m4 m4/ltsugar.m4 m4/ltversion.m4 m4/lt~obsolete.m4 aclocal.m4 configure.ac
	-$(MAKE) -C build-aux test-driver
