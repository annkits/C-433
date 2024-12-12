#include <stdio.h>
#define SQR(x) (x) * (x) //y + 1 * y + 1 = 5 + 1 * 5 + 1 = 5 + 5 + 1

int main(){
    int y = 5;
    int z = SQR(y+1);
    printf("z = %d\n", z);
    return 0;
}