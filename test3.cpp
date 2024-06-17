#include <stdio.h>
#include <stdint.h>

// Function to read System Control Register
uint64_t read_sctlr() {
    uint64_t value;
    asm volatile("mrs %0, sctlr_el1" : "=r" (value));
    return value;
}

// Function to read Hyp Configuration Register
uint64_t read_hcr() {
    uint64_t value;
    asm volatile("mrs %0, hcr_el2" : "=r" (value));
    return value;
}

// Function to read Main ID Register
uint64_t read_midr_el1() {
    uint64_t value;
    asm volatile("mrs %0, midr_el1" : "=r" (value));
    return value;
}

// Function to read AArch64 Processor Feature Register 0
uint64_t read_id_aa64pfr0_el1() {
    uint64_t value;
    asm volatile("mrs %0, id_aa64pfr0_el1" : "=r" (value));
    return value;
}

// Function to read AArch64 Memory Model Feature Register 0
uint64_t read_id_aa64mmfr0_el1() {
    uint64_t value;
    asm volatile("mrs %0, id_aa64mmfr0_el1" : "=r" (value));
    return value;
}

// Function to read Counter Frequency Register
uint64_t read_cntfrq() {
    uint64_t value;
    asm volatile("mrs %0, cntfrq_el0" : "=r" (value));
    return value;
}

int main() {
    // Print the values of the registers
    printf("SCTLR: 0x%lx\n", read_sctlr());
    printf("HCR: 0x%lx\n", read_hcr());
    printf("MIDR_EL1: 0x%lx\n", read_midr_el1());
    printf("ID_AA64PFR0_EL1: 0x%lx\n", read_id_aa64pfr0_el1());
    printf("ID_AA64MMFR0_EL1: 0x%lx\n", read_id_aa64mmfr0_el1());
    printf("CNTFRQ: 0x%lx\n", read_cntfrq());

    return 0;
}
