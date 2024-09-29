#include <stdio.h>

int main(){

	int s, n, a;

	printf("Число: ");
	scanf("%d", &a);

	for (s = 0, n = 2; n < a; n++){
		if (a % n == 0){
			s++;
		}
	}

	if (s == 0){
		printf("Good\n");
	}

	else{
		printf("Not good\n");
	}
}
