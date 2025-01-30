# sos

> Simple OS

## Installation

Tools

```bash
brew install llvm lld qemu
```

Add LLVM to your `PATH`:

```bash
export PATH="$PATH:$(brew --prefix)/opt/llvm/bin"
which llvm-objcopy
/opt/homebrew/opt/llvm/bin/llvm-objcopy
```

MacOS users might need to install and configure riscv by hand:

```bash
git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain
./configure --prefix=/opt/riscv --enable-multilib
```

Once done add the following to your `.zshrc`:

```
export PATH="$PATH:/opt/riscv/bin"
```

## Run

```
chmod +x ./run.sh
./run.sh
```

## Build

C Compile and build

```
/opt/homebrew/opt/llvm/bin/clang -std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf kernel.c
```

# TODO 

* fix crappy formatter settings :) 

