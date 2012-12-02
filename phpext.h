#ifndef PHPEXT_H
#define PHPEXT_H

#define PHP_EXTENSION_NAME "PHP Extension"
#define PHP_EXTENSION_VERSION "1.00"

PHP_FUNCTION(my_function);

extern zend_module_entry phpext_module_entry;

#endif // PHPEXT_H
