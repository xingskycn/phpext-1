// Include PHP API
#include "php.h"
// The module header.
#include "phpext.h"
// The object header.
#include "phpext_obj.h"

zend_module_entry phpext_module_entry = {
	STANDARD_MODULE_HEADER,
 	PHP_EXTENSION_NAME,
 	NULL,
 	PHP_MINIT(phpext),
	NULL,
	NULL,
	NULL,
	NULL,
     	PHP_EXTENSION_VERSION, 
     	STANDARD_MODULE_PROPERTIES
 };

// Initialise the object included in this module:
PHP_MINIT_FUNCTION(phpext) 
{
	phpext_init_object(TSRMLS_C);
}

// Install the module.
ZEND_GET_MODULE(phpext);
