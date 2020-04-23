/*
5가지의 결과를 반복문과 
조건문을 통해 출력하는
main 함수

작성 날짜 : 2020/04/23
작성자 : 김순욱
*/

#include <stdio.h>

int main(void)
{
	int inputOdd;									// 출력할 줄의 수를 의미하는 양의 홀수를 입력받아 저장할 변수 선언
	int i, j;										// 각각 첫 번째, 두 번째 반복문의 반복횟수를 나타내는 변수 선언
	
	/*
	양의 홀수를 입력받아 변수에 저장
	*/
	printf("양의 홀수 하나를 입력하시오: ");
	scanf("%d", &inputOdd);

	printf("\n");

	/*
	첫 번째의 경우 
	- 0 ~ inputOdd - 1 까지 수를 왼쪽 정렬하여 줄이 바뀌면 맨 오른쪽의 수를 하나씩 줄이며 공백으로 채워 출력
	*/

	for(i = 0; i < inputOdd; i++) {
		for(j = 0; j < inputOdd - i; j++) {
			printf("%d", j);
		}
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf("\n");
	}

	printf("\n");

	/*
	두 번째의 경우 
	- 0 ~ inputOdd - 1 까지 수를 오른쪽 정렬하여 줄이 바뀌면 맨 왼쪽의 수를 하나씩 줄이며 공백으로 채워 출력
	*/

	for (i = 0; i < inputOdd; i++) {
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = i; j < inputOdd; j++) {
			printf("%d", j);
		}
		
		printf("\n");
	}

	printf("\n");

	/*
	세 번째의 경우 
	- n번째 줄에서 정수 n - 1을 출력
	홀수 번째의 줄(m)은 2m - 1 개의 m을 왼쪽 정렬, 
	짝수 번째의 줄(n)은 n 개의 해당 정수를 오른쪽 정렬하여 출력
	*/

	for (i = 0; i < inputOdd; i++) {
		if (i % 2 == 0) {								// i가 0 또는 짝수인 경우
			for (j = 0; j < i + 1; j++) {
				printf("%d", i);
			}
			for (j = 1; j < inputOdd - i; j++) {
				printf(" ");
			}
			printf("\n");
		}
		else {											// i가 홀수인 경우
			for (j = 1; j < inputOdd - i; j++) {
				printf(" ");
			}
			for (j = 0; j < i + 1; j++) {
				printf("%d", i);
			}
			printf("\n");
		}
	}

	printf("\n");

	/*
	네 번째의 경우 
	- n번째 줄에서 정수 n - 1을 출력
	첫 줄과 마지막 줄은 해당 정수를 inputOdd 개 출력하고,
	나머지 줄은 해당 줄에서 처음과 마지막 수가 출력되는 칸에는 해당 정수를, 그 외는 공백으로 출력
	*/

	for (i = 0; i < inputOdd; i++) {
		if (i == 0 || i == inputOdd - 1) {				// i가 첫 번째 또는 마지막에 출력될 수인 경우
			for (j = 0; j < inputOdd; j++) {
				printf("%d", i);
			}
			printf("\n");
		}
		else {
			for (j = 0; j < inputOdd; j++) {
				if (j == 0 || j == inputOdd - 1) {		// i가 첫 번째 또는 마지막에 출력될 수인 경우
					printf("%d", i);
				}
				else {
					printf(" ");
				}
				
			}
			printf("\n");
		}
	}

	printf("\n");

	/*
	다섯 번째의 경우
	- n번째 줄에서 정수 n - 1을 출력
	가운데 줄에 출력될 수는 inputOdd 개 출력하고,
	이보다 작은 수는 가운데 정렬하여 줄이 바뀌며 양 맨끝에 수를 추가해 출력,
	이보다 큰 수는 가운데 정렬하여 줄이 바뀌며 양 맨끝에 수를 제외해 출력
	*/

	for (i = 0; i < inputOdd; i++) {
		if (i < inputOdd / 2) {							// i가 가운데 줄에 출력될 수보다 작은 경우
			for (j = 0; j < inputOdd / 2 - i; j++) {
				printf(" ");
			}
			for (j = 0; j < 2 *i + 1; j++) {
				printf("%d", i);
			}
		}
		else if (i > inputOdd / 2) {					// i가 가운데 줄에 출력될 수보다 큰 경우
			for (j = 0; j < i - inputOdd / 2; j++) {
				printf(" ");
			}
			for (j = 0; j < 2 * (inputOdd - i - 1) + 1; j++) {
				printf("%d", i);
			}
		}
		else {											// i가 가운데 줄에 출력될 수인 경우
			for (j = 0; j < inputOdd; j++) {
				printf("%d", i);
			}
		}
		printf("\n");
	}

	printf("\n");

	return 0;
}