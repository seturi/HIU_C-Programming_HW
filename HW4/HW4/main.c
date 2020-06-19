#include <stdio.h>

/*
함수이름: get_nearest_number
기능: 인자로 받은 배열 list에서 target과 가장 근접하는 요소를 찾아 출력한다.
인자: int list[] 입력받은 정수로 이루어진 배열
	  int length 배열의 길이
	  int target 근접한지 판단할 기준인 특정 숫자
반환: 없음
작성날짜: 2020/06/19
작성자: 김순욱
*/
void get_nearest_number(int list[], int length, int target) 
{
	int differenceList[10];						// target과 list 배열의 요소의 차를 순서대로 저장할 배열 크기를 10으로 선언
	int minDif;									// target과 차이가 가장 작은 숫자를 저장할 변수 선언

	for (int i = 0; i < length; i++) {			// length만큼 반복문을 돌며 differenceList에 target과 list의 요소의 차(절댓값)를 저장
		if (target > list[i]) {					// target이 list의 i번째 요소보다 큰 경우
			differenceList[i] = target - list[i];
		}
		else {									// target이 list의 i번째 요소보다 작거나 같은 경우
			differenceList[i] = list[i] - target;
		}
	}

	minDif = differenceList[0];					// 우선 differenceList의 첫 번째 요소의 값을 minDif에 저장

	for (int i = 0; i < length; i++) {
		if (minDif > differenceList[i]) {		// minDif에 저장되어있는 값보다 differenceList의 i번째 요소가 더 작은 경우
			minDif = differenceList[i];			// minDif의 값을 이 요소의 값으로 다시 저장한다.
		}
	}

	printf("가장 근접한 정수 : ");
	for (int i = 0; i < length; i++) {
		if (differenceList[i] == minDif) {		// differenceList의 i번째 요소가 minDif에 저장되어있는 값과 같은 경우
			printf("%d ", list[i]);				// list의 i번째 요소가 target과 가장 근접하므로 이를 출력
		}
	}
}


/*
	main 함수
작성날짜: 2020/06/19
작성자: 김순욱
*/
int main() 
{
	int length, target;							// 배열에 입력값이 들어있는 개수를 저장할 length와 배열의 요소와 특정 숫자 target 선언
	int list[10];								// 크기가 10인 배열 선언

	/*
		2이상 10이하의 정수를 입력받아 length에 저장
		이때 범위에서 벗어나는 경우, 다시 입력받음.
	*/
	printf("2이상 10이하의 정수를 입력하시오 : ");
	while (1) {									// 범위에 맞는 수를 입력받을 때까지 반복문을 수행한다.
		scanf("%d", &length);
		if (length < 2 || length > 10) {		// 범위에서 벗어나는 경우 다시 입력받는다.
			printf("2이상 10이하의 정수가 아닙니다. 다시 입력해주세요.");
		}
		else {									// 범위에 맞는 경우 반복문을 빠져나간다.
			break;
		}
	}
	
	/* length만큼 정수를 입력받아 list에 저장 */
	printf("%d개의 정수값을 입력하시오 : ", length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &list[i]);
	}

	/* 특정 숫자를 입력받아 target에 저장 */
	printf("특정 숫자를 입력하시오 : ");
	scanf("%d", &target);

	get_nearest_number(list, length, target);	// get_nearest_number 함수에 list, length, target을 인자로 넘겨 target과 가장 근접한 숫자 출력

	return 0;
}