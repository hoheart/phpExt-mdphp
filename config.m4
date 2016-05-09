dnl config.m4 for extension mdphp

PHP_ARG_ENABLE(mdphp, [whether to enable "mdphp" support], [ --enable-mdphp   Enable mdphp support])

if test "$PHP_MDPHP" != "no"; then
	PHP_SUBST(MDPHP_SHARED_LIBADD)
	
	srcFiles="mdphp.c \
		php_wrapper.c \
        src/App.c \
        src/ClassLoader.c"
	PHP_NEW_EXTENSION(mdphp, $srcFiles, $ext_shared)
fi