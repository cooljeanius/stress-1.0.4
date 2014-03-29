info_TEXINFOS = stress.texi
man_MANS = stress.1
EXTRA_DIST = $(man_MANS) stress.html ../src/stress.1

DISTCLEANFILES = .DS_Store ../src/stress.1
MAINTAINERCLEANFILES = mdate-sh texinfo.tex stress.html stress.info.html $(man_MANS)

stress.1: ../src/stress
	$(HELP2MAN) -n 'tool to impose load on and stress test systems' ../src/stress > $@

stress.info.html: stress.texi
	$(MAKEINFO) --no-split --html --output=$@ $<

../src/stress:
	$(MAKE) -C ..
