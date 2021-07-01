#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int genius_distinguisher(uint64_t value);

int main(){ 
    volatile uint64_t b; // available values are 0 and 1
    volatile uint64_t x0;
    volatile uint64_t x1;
    volatile uint64_t secret;

    scanf("%lu%lu%lu", &b, &x0, &secret);
    x1 = x0 + 1;

    if (b == genius_distinguisher(b ? x1 : x0))
        printf("win: %lu\n", secret);
    else
        printf("lose ><\n");

    return 0;
}

int genius_distinguisher (uint64_t value) {
    register long rsp asm ("rsp");
    register long rbp asm ("rbp");

    uint16_t a = *(uint64_t *)(((char *)rbp) - 640 );
    for(int i=0;i<1000;i+=4){
        printf("func1, a = %lu, i = %d\n", *(uint64_t *)(((char *)rbp) - i), i );
    }

    return value == a;
    
}