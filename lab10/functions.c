#include "functions.h"

void determine_quadrant(point p){
    if (p.x > 0 && p.y > 0){
        printf("Точка (%d, %d) находится в первом координатном углу.\n", p.x, p.y);
    }
    else if (p.x < 0 && p.y > 0){
        printf("Точка (%d, %d) находится во втором координатном углу.\n", p.x, p.y);
    }
    else if (p.x < 0 && p.y < 0){
        printf("Точка (%d, %d) находится в третьем координатном углу.\n", p.x, p.y);
    }
    else if (p.x > 0 && p.y < 0){
        printf("Точка (%d, %d) находится в четвертом координатном углу.\n", p.x, p.y);
    }
    else if (p.x == 0 && p.y == 0){
        printf("Точка (%d, %d) находится в начале координат.\n", p.x, p.y);
    }
}