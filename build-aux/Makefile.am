ACLOCAL_AMFLAGS = -I../m4 --install

## These are all installed by autoreconf-ing:
MAINTAINERCLEANFILES = compile mdate-sh missing test-driver texinfo.tex

compile install-sh test-driver: $(top_srcdir)/Makefile.am $(top_srcdir)/configure.ac $(top_srcdir)/aclocal.m4 ltmain.sh $(top_srcdir)/m4/libtool.m4 $(top_srcdir)/m4/ltoptions.m4 $(top_srcdir)/m4/ltsugar.m4 $(top_srcdir)/m4/ltversion.m4 $(top_srcdir)/m4/lt~obsolete.m4 $(top_srcdir)/aclocal.m4
	-(cd $(top_srcdir) && $(ACLOCAL) --force --warnings=all -I m4 --install 2>&1 && $(AUTOMAKE) --add-missing --copy --force-missing 2>&1) || (cd .. && aclocal --force --warnings=all -I m4 --install 2>&1 && automake --add-missing --copy --force-missing 2>&1)

EXTRA_DIST = install-sh gitlog-to-changelog

DISTCLEANFILES = .DS_Store

uninstall-hook:
	-if test -n "$(DESTDIR)" && test -d "$(DESTDIR)"; then \
	  find "$(DESTDIR)" -name .DS_Store -delete; fi
.PHONY: uninstall-hook
