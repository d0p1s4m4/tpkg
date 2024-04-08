AC_INIT([tpkg], [1.0], [https://github.com/d0p1s4m4/tpkg/issues])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_LANG(C)
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_RANLIB
AM_PROG_AR
AM_PROG_CC_C_O

PKG_CHECK_MODULES([ZLIB], [zlib])

AC_ARG_ENABLE(dev,
	AS_HELP_STRING(--enable-dev, [shortened version for "--enable-debug --enable-ubsan --enable-asan" (default: no)]))
AC_ARG_ENABLE(debug,
	AS_HELP_STRING(--enable-debug, [whether to include debug symbols (default is no)]))
AC_ARG_ENABLE(ubsan,
	AS_HELP_STRING(--enable-ubsan, [enable undefined behavior sanitizer]))
AC_ARG_ENABLE(asan,
	AS_HELP_STRING(--enable-asan, [enable address sanitizer]))
AC_ARG_ENABLE(verify,
	AS_HELP_STRING(--disable-verify, [don't build tpkg_verify]))

AC_ARG_WITH([openssl],
	[AS_HELP_STRING([--with-openssl=DIR],
		[Root openssl directory (e.g. /usr/local)])],
	[
		AS_IF([test "x$withval" = "x" || ! test -d "$withval"],
		     	    AC_MSG_ERROR([Invalid  --with-openssl directory]))
		AC_MSG_CHECKING([for $withval/include/openssl/ssl.h])
		AS_IF([test -f "$withval/include/openssl/ssl.h"], [
			    AC_MSG_RESULT([yes])
		], [
			    AC_MSG_RESULT([no])
			    AC_MSG_ERROR([Could not find openssl])
		])])

AC_CHECK_INCLUDES_DEFAULT
AC_C_CONST

AS_IF([test "x$enable_dev" = "xyes"], [
	    CFLAGS="$CFLAGS -Werror -Wall -Wextra"
	    enable_debug=yes
	    enable_ubsan=yes
	    enable_asan=yes
])

# +-----------------------------+
# | DEBUG build                 |
# +-----------------------------+
AS_IF([test "x$enable_debug" = "xyes"], [
	changequote({,})
	CFLAGS=`echo "$CFLAGS" | $SED -e 's/-O[0-9s]*//g'`
	CFLAGS=`echo "$CFLAGS" | $SED -e 's/-g[0-9]*//g'`
	changequote([,])

	CFLAGS="$CFLAGS -g -ggdb -O0"
], [
	CFLAGS="$CFLAGS -DNDEBUG"
])

# +-----------------------------+
# | UBSan                       |
# +-----------------------------+

AS_IF([test "x$enable_ubsan" = "xyes"], [
   AX_CHECK_COMPILE_FLAG([-fsanitize=undefined],
   [
	CFLAGS="$CFLAGS -fsanitize=undefined"
   ],
   [
	AC_MSG_ERROR([ubsan isn't supported])
   ])
])

# +------------------------------+
# | Asan                         |
# +------------------------------+

AS_IF([test "x$enable_asan" = "xyes"], [
   AX_CHECK_COMPILE_FLAG([-fsanitize=address],
   [
	CFLAGS="$CFLAGS -fsanitize=address"
   ],
   [
	AC_MSG_ERROR([asan isn't supported])
   ])
])

AC_CONFIG_FILES([
	Makefile
	lib/Makefile
	src/Makefile])
AC_OUTPUT

AC_MSG_RESULT([
	C Compiler:          $CC
	Debug:               ${enable_debug:-no}
	Address Sanitizer:   ${enable_asan:-no}
	Undefined Sanitizer: ${enable_ubsan:-no}

	Compiler Flags:      ${CFLAGS}
	Linker Flags:        ${LDFLAGS} ${LIBS}
])
