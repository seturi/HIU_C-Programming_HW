#include <stdio.h>

/*
함수이름: find_not_sorted
기능: 배열에서 이전의 정렬된 요소와 현재 인덱스의 요소와 비교하여 정렬되지 않은 요소를 출력한다.
      정렬된 요소가 나올 때까지 반복해 그 인덱스를 반환한다.
인자: int array[] 배열
      int index 배열의 현재 인덱스
반환: 정렬된 요소의 인덱스
작성날짜: 2020/06/03
작성자: 김순욱
*/
int find_not_sorted(int array[], int index)
{
    int front = array[index - 1];                           // 이전의 정렬된 요소를 변수로 선언한다.

    while (front < array[index]) {                          // 정렬된 요소가 나오기 전까지 정렬되지않은 요소(이전 요소보다 크기가 큰 경우)를 출력하고 인덱스를 1씩 늘린다.
        printf("정렬되지 않은 값: %d\n", array[index++]);
    }

    return index;                                           // 정렬된 요소의 인덱스 반환
}

/*
함수이름: sorted_merge
기능: 인자로 받은 첫번째 두번째 배열의 원소들을 비교해 내림차순으로 정렬하고, 세번째 배열에 복사하고 배열3의 길이를 반환한다.
인자: int A[], int B[] 비교, 복사할 배열1, 2
      int C[] 복사 대상 배열3
반환: 배열3의 길이
작성날짜: 2020/06/03
작성자: 김순욱
*/
int sorted_merge(int A[], int B[], int C[], int input_num)
{
    int idxA = 0, idxB = 0, idxC = 0;               // 각 배열의 현재 인덱스를 지정할 변수 선언, 0으로 초기화

    while (idxA < input_num && idxB < input_num) {  // A 또는 B 중에서 어느 하나가 먼저 끝에 도달할 때 까지
        if (A[idxA] > B[idxB]) {                    // A의 idxA번째 요소가 B의 idxB번째 요소보다 큰 경우
            C[idxC++] = A[idxA++];                  // A 요소를 C의 idxC번째 요소에 복사하고 idxA와 idxC를 1 늘린다.
            idxA = find_not_sorted(A, idxA);        // A에서 정렬되지않은 요소를 출력하고, 정렬된 요소의 인덱스를 idxA에 저장한다..
        }
        else if (A[idxA] < B[idxB]) {               // B의 idxB번째 요소가 A의 idxA번째 요소보다 큰 경우
            C[idxC++] = B[idxB++];                  // B 요소를 C의 idxC번째 요소에 복사하고 idxB와 idxC를 1 늘린다.
            idxB = find_not_sorted(B, idxB);        // A에서 정렬되지않은 요소를 출력하고, 정렬된 요소의 인덱스를 idxB에 저장한다.
        }
        else {                                      // A의 idxA번째 요소와 B의 idxB번째 요소의 크기가 같은 경우
            C[idxC++] = A[idxA++];                  // A 요소를 C의 idxC번째 요소에 복사하고 idxA와 idxC를 1 늘린다.
            C[idxC++] = B[idxB++];                  // B 요소를 C의 idxC번째 요소에 복사하고 idxB와 idxC를 1 늘린다.
            
            /* A와 B에서 정렬되지않은 요소를 출력하고, 정렬된 요소의 인덱스를 각각 idxA, idxB에 저장한다. */
            idxA = find_not_sorted(A, idxA);
            idxB = find_not_sorted(B, idxB);
        }
    }

    /* B가 먼저 끝에 도달한 경우 A의 나머지 정렬된 요소들을 C에 복사한다. A에서 정렬되지 않은 요소를 출력하고, 정렬된 요소의 인덱스를 idxA에 저장한다. */
    while (idxA < input_num) {
        C[idxC++] = A[idxA++];
        idxA = find_not_sorted(A, idxA);
    }
    /*  A가 먼저 끝에 도달한 경우 B의 나머지 정렬된 요소들을 C에 복사한다. B에서 정렬되지 않은 요소를 출력하고, 정렬된 요소의 인덱스를 idxB에 저장한다. */
    while (idxB < input_num) {
        C[idxC++] = B[idxB++];
        idxB = find_not_sorted(B, idxB);
    }
    
    return idxC;          //  C 배열의 길이 값과 같은 idxC의 값을 반환한다.
 }

/*
    main 함수
작성날짜: 2020/06/02
작성자: 김순욱
*/
int main()
{
    /* 복사할 배열 A, B를 크기 10으로, 복사대상 배열 C를 크기 20으로 선언  */
    int A[10];
    int B[10];
    int C[20];
    int inputNum;               // A, B 배열에 들어갈 정수의 수를 입력받아 저장할 변수 선언
    int lenC;                   // C 배열의 길이를 저장할 변수 선언

    /* A, B 배열에 입력할 정수의 수(2~10)를 입력한다. */
    printf("2이상 10이하의 정수를 입력하시오 : ");
    scanf("%d", &inputNum);

    /* A, B 배열에 각각 inputNum만큼의 내림차순으로 정렬된 정수를 입력받는다. */
    printf("A[]를 위한 정렬된 %d개의 값을 입력하시오 : ", inputNum);
    for (int i = 0; i < inputNum; i++) {
        scanf("%d", &A[i]);
    }
    printf("B[]를 위한 정렬된 %d개의 값을 입력하시오 : ", inputNum);
    for (int i = 0; i < inputNum; i++) {
        scanf("%d", &B[i]);
    }

   lenC = sorted_merge(A, B, C, inputNum);          // sorted_merge 함수를 호출해 A, B의 정렬된 요소를 C에 복사하고 개수를 lenC에 저장한다.

    printf("C[] : ");
    for (int i = 0; i < lenC; i++) {                // lenC만큼 반복문을 돌며 C 배열의 요소를 출력한다.
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}

