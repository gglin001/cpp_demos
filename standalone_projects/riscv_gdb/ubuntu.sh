# https://wiki.ubuntu.com/RISC-V

apt install opensbi u-boot-qemu -y

# wget https://cdimage.ubuntu.com/releases/22.04/release/ubuntu-22.04-live-server-riscv64.img.gz
# gzip -d ubuntu-22.04-live-server-riscv64.img.gz
# qemu-img resize -f raw ubuntu-22.04-live-server-riscv64.img +5G
# qemu-system-riscv64 \
#     -machine virt -nographic -m 8048 -smp 4 \
#     -bios /usr/lib/riscv64-linux-gnu/opensbi/generic/fw_jump.elf \
#     -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf \
#     -device virtio-net-device,netdev=eth0 -netdev user,id=eth0 \
#     -drive file=ubuntu-22.04-live-server-riscv64.img,format=raw,if=virtio

wget https://cdimage.ubuntu.com/releases/22.04/release/ubuntu-22.04-preinstalled-server-riscv64+unmatched.img.xz
xz -dk ubuntu-22.04-preinstalled-server-riscv64+unmatched.img.xz
qemu-img resize -f raw ubuntu-22.04-preinstalled-server-riscv64+unmatched.img +5G

qemu-system-riscv64 \
    -machine virt -nographic -m 8048 -smp 4 \
    -bios /usr/lib/riscv64-linux-gnu/opensbi/generic/fw_jump.elf \
    -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf \
    -device virtio-net-device,netdev=eth0 -netdev user,id=eth0,hostfwd=tcp::2222-:22 \
    -drive file=ubuntu-22.04-preinstalled-server-riscv64+unmatched.img,format=raw,if=virtio
# ssh -p 2222 ubuntu@localhost
scp -P 2222 build/hello ubuntu@localhost:~/

# qemu-system-riscv64 \
#     --enable-kvm \
#     -machine virt -nographic -m 8048 -smp 4 \
#     -bios /usr/lib/riscv64-linux-gnu/opensbi/generic/fw_jump.elf \
#     -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf \
#     -device virtio-net-device,netdev=eth0 -netdev user,id=eth0,hostfwd=tcp::2222-:22 \
#     -drive file=ubuntu-22.04-preinstalled-server-riscv64+unmatched.img,format=raw,if=virtio
