<?php
use Framework\App;

$r = new \ReflectionClass('Framework\App');
print_r($r . '');

$app = App::Instance('aa');
echo "\n";
print_r( $app ) ;

