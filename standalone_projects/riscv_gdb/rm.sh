qemu-riscv64 -g 1234 build/hello
riscv64-unknown-elf-gdb
# (gdb) target remote :1234

riscv64-unknown-elf-c++ \
    -### \
    hello.cpp

riscv64-unknown-elf-c++ -g -S hello.cpp -o hello_gcc.s

clang++ \
    --sysroot=$RISCV/riscv64-unknown-elf \
    --gcc-toolchain=$RISCV \
    --target=riscv64 -march=rv64gc \
    -g -S -o hello_clang.s \
    hello.cpp

# -### \

spike pk a.out
