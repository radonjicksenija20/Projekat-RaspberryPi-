#!/bin/bash
gcc -o light light.c -lwiringPi -lwiringPiDev
./light
php g1.php > g1.png
midori light.html