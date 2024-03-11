#!/bin/sh

if [ -n "$1" ]; then
	git remote add both "$1"
	git add . && git commit -m "remote added" && git push && git push -f both
else
  echo "Parameter not supplied."
fi