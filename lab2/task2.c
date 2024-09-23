#include <stdio.h>

int main (){
        float temp;
        char ch;
        printf("Input temperature: ");
        scanf("%f%c", &temp, &ch);

        if (ch == 'c' || ch == 'C'){
                float result1 = (temp*1.8)+32;
                printf("Output temperature: %.1ff\n", result1);
        } else if (ch == 'f' || ch == 'F'){
                float result2 = (temp-32)/1.8;
                printf("Output temperature: %.1fc\n", result2);
        } else {
                printf("Output error\n");
        }
}
