#include <stdio.h>

int main(){

        int count, count_2, letter=65, letter_2;
        printf("Число: ");
        scanf("%d", &count);

        count_2 = count;

        for (int i = 0; i < count; i++){
                letter_2 = letter;
                for (int j = 0; j < count_2; j++){
                        printf("%c", letter_2);
                        letter_2++;
                }
                letter++;
                count_2--;
                printf("\n");
        }
}
