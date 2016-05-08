<?php
use Framework\App;

$app = new \ReflectionClass('Framework\App');
print_r($app . '');

$cls = new \ReflectionClass('Framework\App\ClassLoader');
print_r($cls . '');

$app = App::Instance('/home/devops/che001');
$app->registerAutoloader();
print_r( $app );

