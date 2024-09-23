#include <stdio.h>

int main(){

        float x, y;
        printf("Введите координаты точки (x, y): ");
        scanf("%f %f", &x,&y);

        if  (y <= 1 && x <= 1 && y >= -x) {
                printf("Да\n");
        } else {
                printf("Нет\n");
        }

}
