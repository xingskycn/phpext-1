<?php

echo "Now testing the PHP extension...\n";

$object = new Phpextobj();

// Should echo "Here is a string."
echo "Echoing output from method_one - ".$object->method_one()."\n";

// Should echo "1"
echo "Echoing class property - ".$object->property_one."\n";

// Should echo "42"
echo "Echoing output from method_two - ".$object->method_two()."\n";
