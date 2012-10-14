#ifndef PHPEXT_OBJ_H
#define PHPEXT_OBJ_H

// Initialise object
void phpext_init_object(TSRMLS_D);

// Internal class properties.
typedef struct 
{
	zend_object std;
	int internal_property;
} phpextobj_internal;

zend_object_value object_constructor(zend_class_entry *class_type TSRMLS_DC);

// Destroy object when out of scope
void object_destructor(void *object TSRMLS_DC);

// First class method.
PHP_METHOD(Phpextobj, method_one);

// Second class method.
PHP_METHOD(Phpextobj, method_two);

#endif // PHPEXT_OBJ_H
