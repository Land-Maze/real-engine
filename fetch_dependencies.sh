#!/bin/sh

set -e

SCRIPT_DIR="$(cd -- "$(dirname -- "$0")" && pwd)"
EXTERNAL_DIR="$SCRIPT_DIR/External"

GLAD_URL="https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D3.3&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=core&loader=on"

mkdir -p "$EXTERNAL_DIR"

IMGUI_DIR="$EXTERNAL_DIR/imgui"
if [ ! -d "$IMGUI_DIR" ]; then
    echo "[*] Fetching Dear ImGui..."
    git clone --depth 1 https://github.com/ocornut/imgui.git "$IMGUI_DIR"
else
    echo "[=] ImGui already present."
fi

echo "[+] Dependencies fetched."
