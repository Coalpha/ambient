#!/bin/bash

# Check for interactive bash and that we haven't already been sourced.
if ! $interactive || [ -z $bash_completion ]; then
  return 0
fi

bash_completion=/usr/share/bash-completion/bash_completion
if shopt -q progcomp && [ -r bash_completion ]; then
  source $bash_completion
fi
