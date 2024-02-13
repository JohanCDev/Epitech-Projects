#!/bin/bash

WARNS=`cat doc/warnings.txt | grep "/.*.[h,c]pp:[0-9]*: warning" | wc -l`
RED='\033[0;31m'
NC='\033[0m'
GREEN='\033[0;32m'

if [ $WARNS -ne 0 ]; then
    echo -e "${RED}${WARNS} documentation warnings !${NC}"
    exit 1
else
    echo -e "${GREEN} No documentation warning.${NC}"
fi
