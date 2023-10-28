info_TEXINFOS = stress.texi
man_MANS = stress.1
EXTRA_DIST = $(man_MANS) stress.html ../src/stress.1

DISTCLEANFILES = .DS_Store ../src/stress.1 share/info/dir
MAINTAINERCLEANFILES = mdate-sh texinfo.tex stress.html stress.info.html $(man_MANS)

AM_DISTCHECK_DVI_TARGET = pdf

stress.1: ../src/stress
	$(HELP2MAN) -n 'tool to impose load on and stress test systems' ../src/stress > $@

stress.info.html: stress.texi
	$(MAKEINFO) --no-split --html --output=$@ $<

../src/stress:
	$(MAKE) -C ..

uninstall-hook:
	-if test -d $(DESTDIR)$(infodir) && test -w $(DESTDIR)$(infodir); then \
	  if test -e $(DESTDIR)$(infodir)/dir && test -z "`ls $(DESTDIR)$(infodir)/*.info 2>/dev/null`"; then \
	    rm -f $(DESTDIR)$(infodir)/dir; \
	  fi; \
	  find $(DESTDIR)$(infodir) -name .DS_Store -delete; \
	fi
.PHONY: uninstall-hook
