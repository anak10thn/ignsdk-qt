#!/bin/bash

logger()
{
	echo -e "\033[0;36m$@\033[0m"
}

logger "Generating Makefile..."
qmake ign.pro

logger "Compiling ignsdk..."
make

logger "Compressing manual pages..."
pushd doc/
gzip -c ignsdk.1 > ignsdk.1.gz
gzip -c ignsdk-app-builder.1 > ignsdk-app-builder.1.gz
gzip -c ignsdk-app-creator.1 > ignsdk-app-creator.1.gz
popd

logger "Compressing default template..."
pushd template/
tar cvjf main.tpl index.html ignsdk.json menu/ icons/
popd
