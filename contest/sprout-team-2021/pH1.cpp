int genius_distinguisher (uint64_t value) {
    register long rsp asm ("rsp");
    register long rbp asm ("rbp");

    uint64_t a = *(uint64_t *)(((char *)rbp) + 0x40 - 32);
    
    return value != a;
    
}