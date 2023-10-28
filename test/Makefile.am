TESTS = check_version_return_code check_usage_return_code
EXTRA_DIST = $(TESTS)

uninstall-hook:
	-if test -n "$(DESTDIR)" && test -d "$(DESTDIR)"; then \
	  find "$(DESTDIR)" -name .DS_Store -delete; fi
.PHONY: uninstall-hook
