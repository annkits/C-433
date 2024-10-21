#include <stdio.h>

#include <stdlib.h>

#define N 6

// заполняем массив рандомными числами

void rand_array(int arr[N]) {
    for (int i = 0; i < N; i++){
        arr[i] = (rand()%100) - 50; // 0-99
    }    
}

// выводим массив

void print_array(int a, int array[a]){
    for (int i = 0; i < a; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

// выводим максимальное реальное значение массива

void maximum(int arr[N]){
    int d = arr[0];
    for (int j = 0; j < N; j = j + 2){
        if (d < arr[j]){
            d = arr[j];
        }
    }
    printf("%d\n", d);
}

// выводим количество мнимых значений массива, которые меньше нуля

void minus(int arr[N]){
    int cnt = 0;
    for (int j = 1; j < N; j = j + 2){
        if (arr[j] < 0){
            cnt += 1;
        }
    }
    printf("%d\n", cnt);
}

// выводим среднее арифметическое всех элементов массива

void average(int arr[N]){
    int s = 0;
    double avg;
    for (int j = 0; j < N; j++){
        s += arr[j];
        avg = (double)s / N;
    }
    printf("%f\n", avg);
}

int main(){

    int a[N];
    int b[N];
    int c[N];

    rand_array(a);  
    rand_array(b);  

    print_array(N, a);
    print_array(N, b);

    for (int i = 0; i < N; i++){
        c[i] = a[i] + b[i];
    }
    
    print_array(N, c);

    maximum(a);

    minus(b);

    average(c);
}
