#include <stdio.h>

int main(){

        //Вычисление суммы цифр числа

        int a, n, s, k;

        printf("Число: ");
        scanf("%d", &a);

        for (n = a, s = 0; n != 0; n = n/10){
                k = n % 10;
                s = s + k;
        }

        printf("Полученное число: %d\n", s);

}
