#!/bin/bash

# Aliases are for one liners that aren't that complicated
# They're also only meant for the user (me) to use

alias ls="exa"
alias lsa="exa -la"
alias lsd="exa -la --tree"

# moving around
alias r="ranger"
alias cd="cd -P" # means that it follows symlinks and hardlinks, I think
alias ..="cd .." #
alias bc="cd -"

# root
alias apt="sudo apt"
alias sul="su -l"

alias ytdl="youtube-dl"
alias scdl="youtube-dl --embed-thumbnail"

# gcc
gccargs="-Wall -Wextra -pedantic -g3"
alias gcc="gcc $gccargs -std=c11"
alias g++="g++ $gccargs"

alias less="less -R" # color support
alias busywork="       \
  sudo apt-get clean   \
  && apt update -y     \
  && apt upgrade -y    \
  && apt autoremove -y \
"
