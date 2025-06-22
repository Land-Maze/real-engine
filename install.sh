#!/bin/sh

set -e

SCRIPT_DIR="$(cd -- "$(dirname -- "$0")" && pwd)"

echo "[*] Detecting distro..."

if command -v pacman >/dev/null 2>&1; then
    DISTRO="arch"
elif command -v apt >/dev/null 2>&1; then
    DISTRO="debian"
else
    echo "[!] Unsupported Linux distribution. Only Arch and Debian-based systems are supported."
    exit 1
fi

echo "[*] Installing dependencies for $DISTRO..."

if [ "$DISTRO" = "arch" ]; then
    sudo pacman -Sy --needed --noconfirm \
        base-devel \
        cmake \
        ninja \
        git \
        glfw-x11 \
        glm \
        libxrandr \
        libxinerama \
        libxcursor \
        libxi \
        xorg-server-devel \
        libglvnd \
        mingw-w64-gcc

elif [ "$DISTRO" = "debian" ]; then
    sudo apt update
    sudo apt install -y \
        build-essential \
        cmake \
        ninja-build \
        git \
        libglfw3-dev \
        libglm-dev \
        libxrandr-dev \
        libxinerama-dev \
        libxcursor-dev \
        libxi-dev \
        libgl1-mesa-dev \
        mingw-w64
fi

echo "[+] Dependencies installed successfully."
