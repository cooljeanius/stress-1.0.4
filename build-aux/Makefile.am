ACLOCAL_AMFLAGS = -I../m4 --install

## These are all installed by autoreconf-ing:
MAINTAINERCLEANFILES = compile mdate-sh missing test-driver texinfo.tex

compile install-sh: $(top_srcdir)/Makefile.am $(top_srcdir)/configure.ac $(top_srcdir)/aclocal.m4 ltmain.sh $(top_srcdir)/m4/libtool.m4 $(top_srcdir)/m4/ltoptions.m4 $(top_srcdir)/m4/ltsugar.m4 $(top_srcdir)/m4/ltversion.m4 $(top_srcdir)/m4/lt~obsolete.m4
	cd $(top_srcdir) && $(AUTOMAKE) --add-missing --copy --force-missing

EXTRA_DIST = install-sh
