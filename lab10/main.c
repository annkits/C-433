#include "functions.h"

int main(){
    int n;
    printf("Введите количество точек: ");
    scanf("%d", &n);

    point points[n];
    for (int i = 0; i < n; i++){
        printf("Введите координаты точки %d (x y): ", i+1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    for (int i = 0; i < n; i++){
        determine_quadrant(points[i]);
    }

    return 0;
}
