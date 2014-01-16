#!/bin/bash

logger()
{
	echo -e "\033[0;36m$@\033[0m"
}

logger "Cleaning build area..."
make distclean

logger "Deleting compressed manpages..."
rm doc/*.gz

logger "Deleting compressed template..."
rm template/main.tpl
