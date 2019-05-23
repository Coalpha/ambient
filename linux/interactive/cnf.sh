#!/bin/bash

# if the command-not-found package is installed, use it
command_not_found_handle() {
  if  [ -x /usr/lib/command-not-found ]; then
    /usr/lib/command-not-found -- "$1"
    return $?
  else
    return 61
  fi
}
