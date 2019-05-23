#!/bin/bash

# add the wsl bins
PATH+=":$wslfiles/box:$wslfiles/shims"

export C="/mnt/c"
export windir="$C/Windows"
export system32="$windir/System32"
# export userprofile=$(cmdrc echo %userprofile% | w2px)
