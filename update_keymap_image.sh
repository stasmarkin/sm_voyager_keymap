#!/bin/bash
set -euo pipefail

# keymap-drawer is not installed globally — uvx fetches and caches it on demand.
uvx --from keymap-drawer keymap draw keymap.yaml > img.svg
