AUTOMAKE_OPTIONS = 1.14 gnits

ACLOCAL_AMFLAGS = -I m4 --install

DISTCLEANFILES = *~ autoscan.log .DS_Store ./configure.scan \
                 ./doc/stress.1 ./src/stress.1
MAINTAINERCLEANFILES = install-sh mkinstalldirs missing \
                       Log.cvs depcomp configure.scan

EXTRA_DIST = ChangeLog .last-cl-gen Makefile.spec README.md \
             ./doc/stress.1 ./src/stress.1

SUBDIRS = . src doc test build-aux m4

VERSION = @VERSION@
PACKAGE = @PACKAGE@

AUTOSCAN = @AUTOSCAN@

## Used to be generated via CVS, but we are now using git:
ChangeLog: $(srcdir)/build-aux/gitlog-to-changelog $(srcdir)/.last-cl-gen
	$(MAKE) .last-cl-gen
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

## FIXME: I think I might have broken it by splitting it up like this...
.last-cl-gen: NEWS $(srcdir)/.git/COMMIT_EDITMSG
	if test -d $(srcdir)/.git; then    \
	  git rev-list -n 1 HEAD | tee $@; \
	fi

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

check-local: configure.scan
	@test -x src/stress || true
.PHONY: check-local

build-aux/compile: build-aux/Makefile m4/libtool.m4 m4/ltoptions.m4 m4/ltsugar.m4 m4/ltversion.m4 m4/lt~obsolete.m4
	$(MAKE) -C build-aux compile
