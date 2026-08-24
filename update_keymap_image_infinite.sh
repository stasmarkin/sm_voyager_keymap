#!/bin/bash
while :
do
  rm -rf img.svg
	uvx --from keymap-drawer keymap draw keymap.yaml > img.svg
	echo "Updated img.svg. Press Ctrl+C to stop."
	sleep 1
done
