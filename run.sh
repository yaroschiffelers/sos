#!/usr/bin/env bash
#
# Boot OpenSBI
#
# @author Yaro Schiffelers - 2025

set -euo pipefail errtrace
IFS=$'\n\t'

# QEMU file path
# If you use MacOS and can't find the path. Run: ls $(brew --prefix)/bin/qemu-system-riscv32
QEMU=qemu-system-riscv32

__usage="
Usage: $(basename $0) [OPTIONS]

Press Ctrl+A then C to switch to the QEMU debug console (QEMU monitor).
You can exit QEMU by q command in the monitor.

Ctrl+A has several features besides switching to the QEMU monitor (C key). 
For example, pressing the X key will immediately exit QEMU.

C-a h    print this help
C-a x    exit emulator
C-a s    save disk data back to file (if -snapshot)
C-a t    toggle console timestamps
C-a b    send break (magic sysrq)
C-a c    switch between console and monitor
C-a C-a  sends C-a
---------------------------------------------------------------------------
"

printf "$__usage"

# Start QEMU
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot
