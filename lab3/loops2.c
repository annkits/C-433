#include <stdio.h>

int main(){

	//степени двойки

	int s, i, n;

	printf("Число: ");
	scanf("%d", &n);

	for (s = 1, i = 0; i <= n; i++){

		s = s*2;
	}

	printf("Полученное число: %d\n", s);

}
