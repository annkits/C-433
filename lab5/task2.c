#include <stdio.h>

int main(){

    int a;
    printf("Введите число: ");
    scanf("%d", &a);

//при вычитании 1 из степени двойки в двоичной записи все биты после ведущей 1 становятся единицами, а сама ведущая 1 становится 0

    if (a > 0 && (a & (a-1)) == 0){
        printf("%d является степенью двойки\n", a);
    }
    else{
        printf("%d не является степенью двойки\n", a);
    }
}