dnl Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([stress],[1.0.4],[apw@rossby.metr.ou.edu])
AC_CONFIG_SRCDIR([src/stress.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE
AM_SANITY_CHECK
dnl AX_* macros require the autoconf-archive package
AX_SPEC_PACKAGE_AND_VERSION([Makefile.spec])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_GCC_TRADITIONAL
AC_PROG_RANLIB
PKG_PROG_PKG_CONFIG
LT_INIT
LTVERSION_VERSION

dnl Checks for libraries.
AC_CHECK_LIB([m],[sqrt])
AC_CHECK_LIB([gen],[basename])

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([ctype.h errno.h libgen.h math.h stdio.h stdlib.h string.h signal.h time.h unistd.h sys/wait.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_CHECK_FUNCS([alarm sqrt strerror])

dnl Options that alter compile and link.
AC_ARG_ENABLE([static],
               AS_HELP_STRING([--enable-static],[build static library @<:@default=no@:>@]),
               [static=$enableval],
               [static=no])

if test "$static" = yes; then
        # if we're using gcc, add `-static' to LDFLAGS
        if test -n "$GCC" || test "$ac_cv_c_compiler_gnu" = "yes"; then
                STATIC_LD="-static"
                LDFLAGS="$LDFLAGS -static"
        fi
fi

AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile test/Makefile])
AC_OUTPUT
