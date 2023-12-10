#!/bin/bash -xe

if [ "$(uname)" == "Darwin" ]; then
	sudo cp ../build/src/ggl /usr/local/bin/
	exit 0
else
	echo "Unknown OS: $(uname)"
	echo "Exiting..."
	exit 1
fi
