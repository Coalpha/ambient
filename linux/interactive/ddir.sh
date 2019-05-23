#!/bin/bash

function ddir {
  if [[ "$1" == "set" ]]; then
    pwd > ~/.ddir
    echo "Wrote $pink$PWD$reset to $orange~/.ddir$reset"
  elif [[ "$1" == "no" ]]; then
    rm ~/.ddir
    echo "Deleted $orange~/.ddir$reset"
  elif [[ "$1" == "go" ]]; then
    if [ -r ~/.ddir ]; then
      cd "$(<~/.ddir)"
      return 0;
    else
      return 1;
    fi
  else
    echo "ddir (set | no | go)$reset"
    return 1;
  fi
}

if $login; then
  ddir go
fi
