#include <stdio.h>

int main() {

	//вычисление простого числа

	int i, a;

	printf("Число: ");
	scanf("%d", &a);

	for (i = 2; i < a; i++){
		if (a % i == 0) break;
	}

	if (i == a){
		printf("Good\n");
	}
	else {
		printf("Not good\n");
	}
}
