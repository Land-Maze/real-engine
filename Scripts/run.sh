#!/bin/sh

set -e

SCRIPT_DIR="$(cd -- "$(dirname -- "$0")" && pwd)"
EXEC="$SCRIPT_DIR/build/bin/Sandbox"

if [ ! -x "$EXEC" ]; then
    echo "[!] Executable not found. Run ./build.sh first."
    exit 1
fi

echo "[*] Running Sandbox..."
"$EXEC"
