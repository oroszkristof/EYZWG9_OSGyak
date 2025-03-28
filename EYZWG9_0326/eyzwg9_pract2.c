#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int parancs;
    parancs = system("dir");
    printf("Letezo parancs (dir) visszateresi erteke: %d\n", parancs);
    parancs = system("dr");
    printf("Nem letezo parancs (dr) visszateresi erteke: %d\n", parancs);
    return 0;
}
