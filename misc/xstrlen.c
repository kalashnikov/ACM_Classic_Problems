#include <stdio.h>
#define hasNulByte(x) ((x - 0x01010101) & ~x & 0x80808080)
#define SW (sizeof (int) / sizeof (char))

int xstrlen (const char *s) {
const char *p;
int d;

    p = s - 1;
    do {
        p++;
        if ((((int) p) & (SW - 1)) == 0) {
            do {
                d  = *((int *) p);
                p += SW;
            } while (!hasNulByte (d));
            p -= SW;
        }
    } while (*p != 0);
    return p - s;
}

int main(int argc, char** argv){
    if (argc==1) return 1;    
    printf("len:%d\n",xstrlen(argv[1]));
    return 0;
}
