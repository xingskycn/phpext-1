PHP_ARG_ENABLE(phpext, whether to enable phpext, [ --enable-phpext Enable phpext support])

if test "$PHP_PHPEXT" = "yes"; then
   AC_DEFINE(HAVE_PHPEXT, 1, [Whether you have phpext])
   PHP_NEW_EXTENSION(phpext, phpext.c phpext_obj.c, $ext_shared)
fi
