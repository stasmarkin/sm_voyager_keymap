#!/bin/bash
while :
do
  rm -rf img.svg
	keymap draw keymap.yaml > img.svg
	echo "Updated img.svg. Press Ctrl+C to stop."
	sleep 1
done