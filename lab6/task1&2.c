#include <stdio.h>

#include <stdlib.h>

#include <time.h>

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

// удаляем из массива последнюю группу элементов, 
// которая подходит под условие знакочередующегося ряда

void delete(int arr[N]){
    for (int i = N-1; i > N/2; i--){ // идём слева на право по элементам массива
        if (arr[i] * arr[i-1] < 0){ // если знаки элементов чередуются
            arr[i] = arr[i-1] = 0; // то они зануляются
        }
    }
    printf("\n");
}

// максимальный и минимальный элементы массива

void extrem(int arr[N]){
    int max = arr[0];
    int min = arr[0];
    for (int j = 0; j < N; j++){
        if (max < arr[j]){
            max = arr[j];
        }
    }
    for (int j= 0; j < N; j++){
        if (min > arr[j]){
            min = arr[j];
        }
    }
    printf("%d %d\n", max, min);
}

int main(){

    int a[N];
    int b[N];
    int c[N];
    int new_c[N];

    srand(time(NULL)); //чтобы каждый запуск массивы заполнялись разными числами
    rand_array(a);  
    rand_array(b);  

    print_array(N, a);
    print_array(N, b);

    for (int i = 0; i < N; i++){ //складываем значения массивов
        c[i] = a[i] + b[i];
    }
    
    print_array(N, c);

    maximum(a);

    minus(b);

    average(c);

    extrem(c); // макс и мин элементы до удаления

    delete(c);
    for (int i = 0; i < N; i++){ // кладём элементы обработанного массива в новый массив
        new_c[i] = c[i];
    }
    print_array(N, new_c);

    extrem(new_c); // макс и мин элементы после удаления
}

// поскольку программа заполняет массивы рандомными числами, 
// для проверки корректной работы последних функций может понадобиться запустить программу энное количество раз...
