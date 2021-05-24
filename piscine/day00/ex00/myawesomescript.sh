#!/bin/bash
#if $# != 1 then echo "error" && return -1
curl -l $1 2>>/dev/null | grep "href=" | cut -f 2 -d \"
