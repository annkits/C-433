//Сформировать матрицу Си путем вычеркивания строки и столбца матрицы А,
//на пересечнии которых находится минимальный элемент матрицы А.
//Определить количество нулей в сформированной матрице и поменять местами первую и последнюю строки матрицы

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для выделения памяти для матрицы
double** allocate_matrix(int n) {
    double** matrix = (double**)malloc(n * sizeof(double*));  // Выделяем память для массива указателей на строки. Каждый элемент будет указывать на строку из n элементов
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));  // Выделяем память для столбцов
    }
    return matrix; // Возвращем указатель на массив указателей
}

// Функция для освобождения памяти матрицы
void free_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);  // Освобождаем память для строк
    }
    free(matrix);  // Освобождаем память для массива указателей
}

// Функция для заполнения матрицы рандомными числами
void rand_matrix(double** matrix, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
        matrix[i][j] = (rand()%100) - 50;
        }
    }
}

//Функция для ввода матрицы с клавиатуры
void read_matrix(double** matrix, int n){
    printf("Введите элементы матрицы %dx%d", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

// Функция для вывода массива
void print_matrix(double** matrix, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
        printf("%8.0f ", matrix[i][j]);
        }
    printf("\n");
    }
}

//Функция для определения минимального элемента матрицы
double find_min(double** matrix, int n, int* min_row, int* min_col){
    double minimum = matrix[0][0];
    *min_row = 0;
    *min_col = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] < minimum){
                minimum = matrix[i][j];
                *min_row = i;
                *min_col = j;
            }
        }
    }
    printf("Минимальный элемент матрицы: %8.0f.\n", minimum);
}

// Функция для создания новой матрицы с вычеркнутой строкой и столбцом
double** create_reduced_matrix(double** matrix, int n, int min_row, int min_col){
    double** new_matrix = allocate_matrix(n - 1);

    int new_i = 0;
    for (int i = 0; i < n; i++){
        if (i == min_row)
        continue;

        int new_j = 0;
        for (int j = 0; j < n; j++){
            if (j == min_col) 
            continue;

            new_matrix[new_i][new_j] = matrix[i][j];
            new_j++;
        }
        new_i++;
    }
    return new_matrix;
}

//функция для подсчета нулей
int count_zeros(double** matrix, int n){
    int zero_count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == 0){
                zero_count++;
            }
        }
    }
    return zero_count;
}


//функция смены местами первой и последней строки
void swap_rows(double** matrix, int n){
    for (int j = 0; j < n; j++){
        double temp = matrix[0][j];
        matrix[0][j] = matrix[n-1][j];
        matrix[n - 1][j] = temp;
    }
}

int main(){
    srand(time(NULL));

    int n;
    char answer;

    printf("Введите размер матрицы: ");
    scanf("%d", &n);

    // Проверка корректности ввода
    if (n < 2) {
        printf("Размер матрицы должен быть не меньше 2.\n");
        return 1;
    }

     // Выделяем память для матрицы
    double** A = allocate_matrix(n);

    printf("Матрицу следует заполнить рандомными числами? (y/n): ");
    scanf(" %c", &answer);

    if (answer == 'y' || answer == 'Y'){
        rand_matrix(A, n);
    }
    else{
        read_matrix(A, n);
    }

    printf("Исходная матрица:\n");
    print_matrix(A, n);

    int min_row, min_col;
    find_min(A, n, &min_row, &min_col);

    printf("Минимальный элемент находится в строке %d, столбце %d.\n", min_row+1, min_col+1);

    double** C = create_reduced_matrix(A, n, min_row, min_col);

    printf("Матрица после вычеркивания строки и столбца: \n");
    print_matrix(C, n-1);

    int zero_count = count_zeros(C, n-1);
    printf("Количество нулей в новой матрице: %d\n", zero_count);

    swap_rows(C, n-1);

    printf("Матрица после перестановки первой и последней строки:\n");
    print_matrix(C, n-1);

    free_matrix(A, n);
    free_matrix(C, n-1);

    return 0;
}