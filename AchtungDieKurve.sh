#!/usr/bin/env bash
# This file should be placed at the top level of your project
# i.e. it should be in the same folder as the "src" folder (containing .cpp files)
# and the "include" folder (containing .h files)

# Stop upon error
set -e
git remote add origin https://github.com/Harsku/AchtungDieKurve.git
git push -u origin master

g++ src/*.cpp -Wall -Wextra -std=c++14 -I include -o AchtungDieKurve -lSDL2main -lSDL2 -I /opt/local/include -L /opt/local/lib

./AchtungDieKurve
