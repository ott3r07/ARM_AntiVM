#include <iostream>
#include <cstdint>
#include <iomanip> 

// MIDR_EL1 값을 읽는 함수
uint64_t read_midr_el1() {
    uint64_t value;
    asm("mrs %0, MIDR_EL1" : "=r" (value));  // "mrs" 명령어로 MIDR_EL1에서 값을 읽어옴
    return value;
}

int main() {
    uint64_t midr = read_midr_el1();  
    std::cout << "MIDR_EL1: 0x" 
              << std::setfill('0') << std::setw(16) 
              << std::hex << midr << std::endl;
    return 0;
}

qemu-system-aarch64 -machine virt -cpu cortex-a72 -smp 6 -m 4G \
    -kernel Image -append "root=/dev/vda2 rootfstype=ext4 rw panic=0 console=ttyAMA0" \
    -drive format=raw,file=2023-05-03-raspios-bullseye-arm64.img,if=none,id=hd0,cache=writeback \
    -device virtio-blk,drive=hd0,bootindex=0 \
    -netdev user,id=mynet,hostfwd=tcp::2222-:22 \
    -device virtio-net-pci,netdev=mynet \
    -monitor telnet:127.0.0.1:5555,server,nowait