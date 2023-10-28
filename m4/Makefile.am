ACLOCAL_AMFLAGS = -I. --install

## these macros come from packages outside the standard autotools ones,
## and users might not necessarily have them:
EXTRA_DIST = ax_spec_file.m4 ax_spec_package_version.m4 pkg.m4
## (pkg.m4 is borderline)

DISTCLEANFILES = .DS_Store

uninstall-hook:
	-if test -n "$(DESTDIR)" && test -d "$(DESTDIR)"; then \
	  find "$(DESTDIR)" -name .DS_Store -delete; fi
.PHONY: uninstall-hook
