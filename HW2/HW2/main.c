#include <stdio.h>

/* 
각각 홀수의 개수와 짝수의 개수를 저장할 odd, even 변수와
홀수의 합과 짝수의 곱을 저장할 변수를 전역으로 선언
이때, multiEven 변수는 1로 초기화하고
다른 변수들은 자동으로 0으로 초기화
*/
int odd, even, sumOdd, multiEven = 1;

/*
함수 이름 : PrintForInput
기능 : 입력받은 홀수
인자 : int odd : 양의 홀수
반환값 : 두 정수의 합
작성 날짜 : 2020/05/06
작성자 : 김순욱
*/
void PrintForInput(int odd) {
	int i, j;						// 각각 첫 번째, 두 번째 반복문의 반복횟수를 나타내는 변수 선언
	int midPoint = odd / 2;			// 가운데에 출력되는 정수의 인덱스(0 ~ odd - 1) 번호

	/*
	가운데 줄에 출력될 수는 1개 출력되고,
	이보다 작은 수는 양 맨끝에 수를 하나씩 제외해 출력.
	이보다 큰 수는 양 맨끝에 수를 하나씩 추가해 출력
	*/
	for (i = 0; i < odd; i++) {
		if (i <= midPoint) {		// i가 midPoint보다 순서가 앞이거나 같은 경우
			for (j = 0; j < i; j++) {
				printf(" ");
			}
			for (j = 0; j < odd - 2 * i; j++) {
				printf("%d", i + 1);
			}
		}
		else {						// i가 가운데에 출력될 수보다 순서가 뒤인 경우
			for (j = 0; j < odd - i - 1; j++) {
				printf(" ");
			}
			for (j = 0; j < 2 * (i + 1) - odd; j++) {
				printf("%d", i + 1);
			}
		}
		printf("\n");
	}
	printf("\n");
}

/*
함수 이름 : OddEvenCheck
기능 : 인자로 전달된 정수가 홀수인지 짝수인지 판단한다.
홀수인 경우 odd의 값을 1 늘리고 sumOdd에 정수를 더한다.
짝수인 경우 even의 값을 1 늘리고 multiEven에 정수를 곱한다.
인자 : int num: 정수
반환값 : 없음
작성 날짜 : 2020/05/06
작성자 : 김순욱
*/
void OddEvenCheck(int num) {

	if (num % 2 == 0) {		// num을 2로 나눈 나머지가 0인 경우, 즉 num이 짝수인 경우
		even++;
		multiEven *= num;
	}
	else {					// num이 홀수인 경우
		odd++;
		sumOdd += num;
	}
}

/*
함수 이름 : PrintOddAndEven
기능 : 홀수와 짝수의 수, 홀수의 합과 짝수의 곱을 출력한다.
인자 : 없음
반환값 : 없음
작성 날짜 : 2020/05/06
작성자 : 김순욱
*/
void PrintOddAndEven() {
	printf("-> 홀수: %d개, 짝수: %d개\n", odd, even);
	printf("-> 홀수의 합: %d, 짝수의 곱: %d", sumOdd, multiEven);
}

/*
함수 이름 : main함수
작성 날짜 : 2020/05/06
작성자 : 김순욱
*/
int main() {

	int inputOdd, num;		// 양의 홀수를 입력받아 저장할 inputOdd와 inputOdd만큼 정수를 하나씩 입력받을 num 변수를 선언

	/*양의 홀수를 입력받아 inputOdd에 저장*/
	printf("양의 홀수 하나를 입력하시오: ");
	scanf("%d", &inputOdd);

	printf("\n");
	PrintForInput(inputOdd);	// PrintForInput 함수를 호출해 인자로 inputOdd의 값을 전달해 출력

	printf("정수 %d개를 입력하시오: ", inputOdd);

	/*
	이전에 입력받은 양의 홀수만큼 반복문을 돌며 num변수에 정수를 입력받고,
	OddEvenCheck 함수를 호출하여 인자로 전달해 홀수, 짝수 판단
	*/
	for (int i = 0; i < inputOdd; i++) {
		scanf("%d", &num);
		OddEvenCheck(num);
	}

	PrintOddAndEven();	// PrintOddAndEven 함수를 호출해 전역변수 odd, even, sumOdd, multiEven에 저장되어있는 값을 이용해 출력

	return 0;
}