#!/bin/sh

set -e

SCRIPT_DIR="$(cd -- "$(dirname -- "$0")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/build"

echo "[*] Building in $BUILD_DIR ..."
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake "$SCRIPT_DIR"
cmake --build .

echo "[+] Build completed."
