//алгоритм Крамера для решение СЛАУ NxN, где N может быть любым

#include <stdio.h>
#include <stdlib.h>

// Функция для выделения памяти для квадратной матрицы размером n x n
double** allocateMatrix(int n) {
    double** matrix = (double**)malloc(n * sizeof(double*));  // Выделяем память для массива указателей на строки. Каждый элемент будет указывать на строку из n элементов
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));  // Выделяем память для столбцов
    }
    return matrix; // Возвращем указатель на массив указателей
}

// Функция для освобождения памяти матрицы
void freeMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);  // Освобождаем память для строк
    }
    free(matrix);  // Освобождаем память для массива указателей
}

// Функция для вычисления определителя методом разложения по строке
double determinant(double** matrix, int n) {
    if (n == 1) {
        return matrix[0][0];  // Определитель матрицы 1x1 — её единственный элемент
    }
    if (n == 2) {
        // Определитель матрицы 2x2: ad - bc
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0;  // Инициализация определителя
    for (int p = 0; p < n; p++) {
        // Создаем минор (матрицу меньшего размера)
        double** minor = allocateMatrix(n - 1);

        // Формируем минор, исключая 0-ю строку и p-й столбец
        for (int i = 1; i < n; i++) {  // Начинаем со второй строки
            int col = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;  // Пропускаем столбец p
                minor[i - 1][col] = matrix[i][j];
                col++;
            }
        }

        // Рекурсивно вычисляем определитель минора
        double minorDet = determinant(minor, n - 1);

        // Считаем вклад текущего элемента в определитель
        det += matrix[0][p] * minorDet * (p % 2 == 0 ? 1 : -1);

        // Освобождаем память, выделенную для минора
        freeMatrix(minor, n - 1);
    }

    return det;  // Возвращаем определитель
}

void replace_column(double** dest, double** source, double* column, int col_index, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dest[i][j] = (j == col_index) ? column[i] : source[i][j]; // Если это нужный столбец, берем значения из column, иначе копируем из source
        }
    }
}

int main() {
    int n;

    // Ввод размера матрицы
    printf("Введите размер матрицы: ");
    scanf("%d", &n);

    // Проверка корректности ввода
    if (n < 1) {
        printf("Размер матрицы должен быть больше 0.\n");
        return 1;
    }

    // Выделяем память для матрицы
    double** A = allocateMatrix(n); // Матрица коэффициентов A
    double* B = (double*)malloc(n * sizeof(double)); //Столбец свободных членов

    // Ввод элементов матрицы
    printf("Введите элементы матрицы (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Введите элементы столбца свободных членов B: \n");
    for (int i = 0; i < n; i++){
        scanf("%lf", &B[i]);
    }

    // Вычисляем определитель
    double detA = determinant(A, n);
    if (detA == 0){
        printf("Определитель матрицы A равено 0. Система не имеет единственного решения.\n");
        freeMatrix(A, n);
        free(B);
        return 1;
    }

double** temp_matrix = allocateMatrix(n); //Вспомогательная матрица
double* X = (double*)malloc(n * sizeof(double)); //Вектор решений

for (int i = 0; i < n; i++){
    replace_column(temp_matrix, A, B, i, n); // Заменяем i-й столбец матрицы на столбец B
    double detAi = determinant(temp_matrix, n); //Вычисляем определитель новой матрицы
    X[i] = detAi / detA; //Вычисляем значение i-й переменной
}

printf("Решение системы: \n");
for (int i = 0; i < n; i++){
    printf("X[%d] = %.2lf\n", i+1, X[i]);
}

    // Освобождаем память
    freeMatrix(A, n);
    freeMatrix(temp_matrix, n);
    free(B);
    free(X);

    return 0;
}
