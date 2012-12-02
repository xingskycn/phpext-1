// Include PHP API
#include "php.h"
// The module header.
#include "phpext.h"

static function_entry phpext_functions[] = {
    PHP_FE(my_function, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry phpext_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_EXTENSION_NAME,
    phpext_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_EXTENSION_VERSION,
    STANDARD_MODULE_PROPERTIES
};

PHP_FUNCTION(my_function)
{
    RETURN_STRING("Hello World", 1);
}

ZEND_GET_MODULE(phpext);
