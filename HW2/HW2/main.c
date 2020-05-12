#include <stdio.h>

/* 
���� Ȧ���� ������ ¦���� ������ ������ odd, even ������
Ȧ���� �հ� ¦���� ���� ������ ������ �������� ����
�̶�, multiEven ������ 1�� �ʱ�ȭ�ϰ�
�ٸ� �������� �ڵ����� 0���� �ʱ�ȭ
*/
int odd, even, sumOdd, multiEven = 1;

/*
�Լ� �̸� : PrintForInput
��� : �Է¹��� Ȧ��
���� : int odd : ���� Ȧ��
��ȯ�� : �� ������ ��
�ۼ� ��¥ : 2020/05/06
�ۼ��� : �����
*/
void PrintForInput(int odd) {
	int i, j;						// ���� ù ��°, �� ��° �ݺ����� �ݺ�Ƚ���� ��Ÿ���� ���� ����
	int midPoint = odd / 2;			// ����� ��µǴ� ������ �ε���(0 ~ odd - 1) ��ȣ

	/*
	��� �ٿ� ��µ� ���� 1�� ��µǰ�,
	�̺��� ���� ���� �� �ǳ��� ���� �ϳ��� ������ ���.
	�̺��� ū ���� �� �ǳ��� ���� �ϳ��� �߰��� ���
	*/
	for (i = 0; i < odd; i++) {
		if (i <= midPoint) {		// i�� midPoint���� ������ ���̰ų� ���� ���
			for (j = 0; j < i; j++) {
				printf(" ");
			}
			for (j = 0; j < odd - 2 * i; j++) {
				printf("%d", i + 1);
			}
		}
		else {						// i�� ����� ��µ� ������ ������ ���� ���
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
�Լ� �̸� : OddEvenCheck
��� : ���ڷ� ���޵� ������ Ȧ������ ¦������ �Ǵ��Ѵ�.
Ȧ���� ��� odd�� ���� 1 �ø��� sumOdd�� ������ ���Ѵ�.
¦���� ��� even�� ���� 1 �ø��� multiEven�� ������ ���Ѵ�.
���� : int num: ����
��ȯ�� : ����
�ۼ� ��¥ : 2020/05/06
�ۼ��� : �����
*/
void OddEvenCheck(int num) {

	if (num % 2 == 0) {		// num�� 2�� ���� �������� 0�� ���, �� num�� ¦���� ���
		even++;
		multiEven *= num;
	}
	else {					// num�� Ȧ���� ���
		odd++;
		sumOdd += num;
	}
}

/*
�Լ� �̸� : PrintOddAndEven
��� : Ȧ���� ¦���� ��, Ȧ���� �հ� ¦���� ���� ����Ѵ�.
���� : ����
��ȯ�� : ����
�ۼ� ��¥ : 2020/05/06
�ۼ��� : �����
*/
void PrintOddAndEven() {
	printf("-> Ȧ��: %d��, ¦��: %d��\n", odd, even);
	printf("-> Ȧ���� ��: %d, ¦���� ��: %d", sumOdd, multiEven);
}

/*
�Լ� �̸� : main�Լ�
�ۼ� ��¥ : 2020/05/06
�ۼ��� : �����
*/
int main() {

	int inputOdd, num;		// ���� Ȧ���� �Է¹޾� ������ inputOdd�� inputOdd��ŭ ������ �ϳ��� �Է¹��� num ������ ����

	/*���� Ȧ���� �Է¹޾� inputOdd�� ����*/
	printf("���� Ȧ�� �ϳ��� �Է��Ͻÿ�: ");
	scanf("%d", &inputOdd);

	printf("\n");
	PrintForInput(inputOdd);	// PrintForInput �Լ��� ȣ���� ���ڷ� inputOdd�� ���� ������ ���

	printf("���� %d���� �Է��Ͻÿ�: ", inputOdd);

	/*
	������ �Է¹��� ���� Ȧ����ŭ �ݺ����� ���� num������ ������ �Է¹ް�,
	OddEvenCheck �Լ��� ȣ���Ͽ� ���ڷ� ������ Ȧ��, ¦�� �Ǵ�
	*/
	for (int i = 0; i < inputOdd; i++) {
		scanf("%d", &num);
		OddEvenCheck(num);
	}

	PrintOddAndEven();	// PrintOddAndEven �Լ��� ȣ���� �������� odd, even, sumOdd, multiEven�� ����Ǿ��ִ� ���� �̿��� ���

	return 0;
}