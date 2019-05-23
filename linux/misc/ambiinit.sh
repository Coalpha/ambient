#!/bin/bash

cd "$(dirname "$0")"
gcc ambiinit.c -O2 -s -DNDEBUG -march=native -mtune=native -o ambiinit
cp ambiinit /usr/bin/ambiinit
