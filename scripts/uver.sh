#!/bin/bash
echo "UpdateVer For Tonyhax International"

if [ -z "$1" ] || [ -z "$2" ]; then
	echo -e "\nError: at least 2 arguments are required.\n\nUsage:\nuver <old version> <new version>\n\n<old version> is the current version in the variable.mk files, i.e. 1.0.8.\n\n<new version> is the new version you want to update the variable.mk files to use, i.e. 1.0.9.\n"
	exit 1
fi
cd "$(dirname "$0")"
find ../variables.mk* -type f -exec sed -i 's/'TONYHAX_VERSION=v"${1}"-international'/'TONYHAX_VERSION=v"${2}"-international'/' {} \;
