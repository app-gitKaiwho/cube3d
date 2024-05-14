#!/bin/bash

for mapfile in ./maps/*; do
	echo -n "Testing $mapfile :"
    ./cub3d "$mapfile"
	echo $?
    wait $!
done