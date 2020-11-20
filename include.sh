#!/usr/bin/env bash

MOD_NPCTITLESTOKENS_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/" && pwd )"

source "$MOD_NPCTITLESTOKENS_ROOT/conf/conf.sh.dist"

if [ -f "$MOD_NPCTITLESTOKENS_ROOT/conf/conf.sh" ]; then
    source "$MOD_NPCTITLESTOKENS_ROOT/conf/conf.sh"
fi 