#include <stdio.h>

int main(){

	//тест на простое число

	int a, n;

	printf("Число: ");
	scanf("%d", &a);

	for (n = 2; n < a; n++){

		if (a % n == 0) break;
	}


	if (n == a){
		printf("Good\n");
	}

	else {
		printf("Not good\n");
	}

}
