#!/bin/bash

export PS1="\
\[$reset\]\[$cyan\]<-\$(printf %03d \$?)\[$grey\] $(tty | sed -e 's|/dev/||') \
LV\$SHLVL \[$red\]\u \[$blue\]in \[$green\]\w \[$orange\]::\[$reset\] \
"
function fp() { # full prompt
  PS1=${PS1//\\W/\\w}
}
function hp() {
  PS1=${PS1//\\w/\\W}
}
export -f fp hp
# <-000 LV1 User in ~ !
