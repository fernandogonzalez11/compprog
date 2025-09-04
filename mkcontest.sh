#!/bin/bash

COMPPROG_DIR=~/Documents/compprog
DATE=$(date "+%Y%m%d")

cd $COMPPROG_DIR

read -p "directory (contests/): " -e CDIR

if [ -z "$CDIR" ]; then
    CDIR='contests'
fi

read -p "platform (codeforces): " PLATFORM

if [ -z "$PLATFORM" ]; then
    PLATFORM='codeforces'
fi

read -p "date (today): " DATE_INP

if [ -n "$DATE_INP" ]; then
    DATE=$DATE_INP
fi

FULLDIR=$CDIR/$PLATFORM-$DATE

read -p "exercises (5): " EXERCISES

if [ -z "$EXERCISES" ]; then
    EXERCISES=5
fi

echo "-----"
echo "placing $EXERCISES exercises in $FULLDIR"
echo "press Enter if ok"
read _


mkdir -p $FULLDIR

cp templates/template.cpp $FULLDIR
cd $FULLDIR

for i in $(seq 1 "$EXERCISES"); do
    F=$(printf "\\$(printf %o $(($i+96))).cpp")
    cp template.cpp $F
done

code .
