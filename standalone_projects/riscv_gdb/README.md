# README

## env

using docker image from

https://github.com/gglin001/Dockerfiles/blob/master/riscv/Dockerfile

## test

### without cmake

```bash
riscv64-unknown-elf-c++ -g -O0 hello.cpp

# or
clang++ --gcc-toolchain=$RISCV \
    --target=riscv64 -march=rv64gc \
    -g  -O0 hello.cpp

spike pk a.out

qemu-riscv64 -g 1234 a.out

riscv64-unknown-elf-gdb a.out
# (gdb) target remote :1234
# (gdb) l
# (gdb) b main
# (gdb) c
# (gdb) bt

```

### debug with vscode

- build with cmake extension

- set `LaunchTarget` to target

- debug with vscode

qemu-riscv64 -g 1234 build/hello

F5
