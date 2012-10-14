#include "php.h"
#include "phpext_obj.h"

zend_class_entry *class_reference;

// Register class methods.
static function_entry phpextobj_methods[] = {
	PHP_ME(Phpextobj, method_one, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpextobj, method_two, NULL, ZEND_ACC_PUBLIC)
	{NULL, NULL, NULL}
};

// Initialise object
void phpext_init_object(TSRMLS_D) 
{
	zend_class_entry  ce;

	// Create class entry and assign its methods.
	INIT_CLASS_ENTRY(ce, "Phpextobj", phpextobj_methods);
	ce.create_object = object_constructor;
	class_reference = zend_register_internal_class(&ce TSRMLS_CC);

	// Create class properties.
	zend_declare_property_bool(class_reference, "property_one", strlen("property_one"), 1, ZEND_ACC_PUBLIC TSRMLS_CC);
}

// Object constructor.
zend_object_value object_constructor(zend_class_entry *class_type TSRMLS_DC)
{
	zend_object_value retval;
	phpextobj_internal *intern;
	zval *tmp;

	// Allocate struct (from header) that defines class internal structure.
	intern = (phpextobj_internal*)emalloc(sizeof(phpextobj_internal));
	memset(intern, 0, sizeof(phpextobj_internal));

	// table for class properties
	zend_object_std_init(&intern->std, class_type TSRMLS_CC);
	zend_hash_copy(intern->std.properties,
		&class_type->default_properties,
		(copy_ctor_func_t) zval_add_ref,
		(void *) &tmp,
		sizeof(zval *));

	// assign object destructor
	retval.handle = zend_objects_store_put(intern, (zend_objects_store_dtor_t) zend_objects_destroy_object, object_destructor, NULL TSRMLS_CC);
	retval.handlers = zend_get_std_object_handlers();
	return retval;
}

// Called when object goes out of scope.
void object_destructor(void *object TSRMLS_DC)
{
	phpextobj_internal *intern = (phpextobj_internal*)object;
	efree(intern);
}

// First class method.
// Simply return a string.
PHP_METHOD(Phpextobj, method_one)
{
	// Second parameter: 1 to duplicate memory used, 0 to use provided. 0 causes exit if a cosntant is used.
	RETURN_STRING("Here is a string.", 1);
}

// Second class method.
// Returns an integer.
PHP_METHOD(Phpextobj, method_two)
{
	RETURN_DOUBLE(42);
}
