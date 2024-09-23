#include <stdio.h>

int main (){

        int a;
        int b = 400;
        printf("Enter a year: ");
        scanf("%d", &a);
        int result = (int) a % 400;

        if (result == 0){
                printf("YES");
        } else if (a % 100 == 0){
                printf("NO");
        } else if (a % 4 == 0) {
                printf("YES");
        } else {
                printf("NO");
        }
}
