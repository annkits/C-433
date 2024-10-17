#include <stdio.h>

int main(){

    int a;

    printf("Введите число: ");
    scanf("%x", &a);

    int b = a & 0xFF; //младший байт // cc
    int c = (a >> 8) & 0xFF; //предпоследний байт // bb
    a = (a & 0xFFFF0000) | (b << 8); //зануляем два последних байта и меняем

    // aaccbb

    a = a | c;

    printf("%x\n", a);
}
