#!/usr/bin/env bash

VALGRIND_PATH=$(which valgrind)

VALGRIND_FLAGS='--leak-check=full --track-origins=yes'

echo $VALGRIND_PATH

env | cut -d '=' -f1 > env_names.txt

while read ENV; do unset $ENV; done < env_names.txt

function clear_tmp() {
    /bin/rm -f env_names.txt 2>/dev/null
}

clear_tmp
$VALGRIND_PATH $VALGRIND_FLAGS .././21sh

exit 0