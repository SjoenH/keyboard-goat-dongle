#!/bin/bash

wget -O /tmp/goat.jpg https://wallpapercave.com/wp/wp9348729.jpg && \
osascript -e 'tell application "System Events" to set picture of current desktop to "/tmp/goat.jpg"'