#!/bin/sh

set -e

SCRIPT_DIR="$(cd -- "$(dirname -- "$0")" && pwd)"
TARGET="$1"

if [ -z "$TARGET" ]; then
    echo "Usage: ./package.sh <target>"
    echo "Example targets: linux, windows"
    exit 1
fi

BUILD_DIR="$SCRIPT_DIR/build-$TARGET"
OUTPUT_DIR="$SCRIPT_DIR/package/$TARGET"
EXEC_NAME="Sandbox"
TOOLCHAIN_FILE="$SCRIPT_DIR/cmake/toolchains/mingw.cmake"

mkdir -p "$BUILD_DIR" "$OUTPUT_DIR"

echo "[*] Packaging for $TARGET..."

case "$TARGET" in
    linux)
        cmake -B"$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release -S "$SCRIPT_DIR"
        cmake --build "$BUILD_DIR" --config Release
        cp "$BUILD_DIR/bin/$EXEC_NAME" "$OUTPUT_DIR/"
        ;;
    windows)
        # cmake -B"$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release -S "$SCRIPT_DIR" -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE"
        # cmake --build "$BUILD_DIR" --config Release
        # cp "$BUILD_DIR/bin/$EXEC_NAME.exe" "$OUTPUT_DIR/"
        # if [ -d "$BUILD_DIR/bin" ]; then
        #     cp "$BUILD_DIR/bin/*.dll" "$OUTPUT_DIR/"
        # fi
        echo "[!] Windows packaging is not implemented yet."
        exit 1
        ;;
    *)
        echo "[!] Unknown target: $TARGET"
        exit 1
        ;;
esac

echo "[+] Packaged binary available at: $OUTPUT_DIR/"
