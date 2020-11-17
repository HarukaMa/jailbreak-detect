#include <stdlib.h>

uint32_t test() {
    char* filename = "/var/lib/dpkg/status";
    volatile uint32_t result = -1;
    volatile uint64_t nzcv = 0;
#if __arm64__
    asm volatile (
                  "mov x0, %[file] \n"
                  "mov x1, 0 \n"
                  "mov x16, #5 \n"
                  "svc #42 \n"
                  "mov %w[res], w0 \n"
                  "mrs %[c], nzcv"
                  : [res] "=r"(result), [c] "=r"(nzcv)
                  : [file] "r"(filename)
                  : "x0", "x1", "x16", "memory", "cc"
                  );
#endif
    uint32_t cc = (nzcv >> 29) & 1;
    return result | (cc << 31);
}
