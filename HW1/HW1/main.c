/*
5������ ����� �ݺ����� 
���ǹ��� ���� ����ϴ�
main �Լ�

�ۼ� ��¥ : 2020/04/23
�ۼ��� : �����
*/

#include <stdio.h>

int main(void)
{
	int inputOdd;									// ����� ���� ���� �ǹ��ϴ� ���� Ȧ���� �Է¹޾� ������ ���� ����
	int i, j;										// ���� ù ��°, �� ��° �ݺ����� �ݺ�Ƚ���� ��Ÿ���� ���� ����
	
	/*
	���� Ȧ���� �Է¹޾� ������ ����
	*/
	printf("���� Ȧ�� �ϳ��� �Է��Ͻÿ�: ");
	scanf("%d", &inputOdd);

	printf("\n");

	/*
	ù ��°�� ��� 
	- 0 ~ inputOdd - 1 ���� ���� ���� �����Ͽ� ���� �ٲ�� �� �������� ���� �ϳ��� ���̸� �������� ä�� ���
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
	�� ��°�� ��� 
	- 0 ~ inputOdd - 1 ���� ���� ������ �����Ͽ� ���� �ٲ�� �� ������ ���� �ϳ��� ���̸� �������� ä�� ���
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
	�� ��°�� ��� 
	- n��° �ٿ��� ���� n - 1�� ���
	Ȧ�� ��°�� ��(m)�� 2m - 1 ���� m�� ���� ����, 
	¦�� ��°�� ��(n)�� n ���� �ش� ������ ������ �����Ͽ� ���
	*/

	for (i = 0; i < inputOdd; i++) {
		if (i % 2 == 0) {								// i�� 0 �Ǵ� ¦���� ���
			for (j = 0; j < i + 1; j++) {
				printf("%d", i);
			}
			for (j = 1; j < inputOdd - i; j++) {
				printf(" ");
			}
			printf("\n");
		}
		else {											// i�� Ȧ���� ���
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
	�� ��°�� ��� 
	- n��° �ٿ��� ���� n - 1�� ���
	ù �ٰ� ������ ���� �ش� ������ inputOdd �� ����ϰ�,
	������ ���� �ش� �ٿ��� ó���� ������ ���� ��µǴ� ĭ���� �ش� ������, �� �ܴ� �������� ���
	*/

	for (i = 0; i < inputOdd; i++) {
		if (i == 0 || i == inputOdd - 1) {				// i�� ù ��° �Ǵ� �������� ��µ� ���� ���
			for (j = 0; j < inputOdd; j++) {
				printf("%d", i);
			}
			printf("\n");
		}
		else {
			for (j = 0; j < inputOdd; j++) {
				if (j == 0 || j == inputOdd - 1) {		// i�� ù ��° �Ǵ� �������� ��µ� ���� ���
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
	�ټ� ��°�� ���
	- n��° �ٿ��� ���� n - 1�� ���
	��� �ٿ� ��µ� ���� inputOdd �� ����ϰ�,
	�̺��� ���� ���� ��� �����Ͽ� ���� �ٲ�� �� �ǳ��� ���� �߰��� ���,
	�̺��� ū ���� ��� �����Ͽ� ���� �ٲ�� �� �ǳ��� ���� ������ ���
	*/

	for (i = 0; i < inputOdd; i++) {
		if (i < inputOdd / 2) {							// i�� ��� �ٿ� ��µ� ������ ���� ���
			for (j = 0; j < inputOdd / 2 - i; j++) {
				printf(" ");
			}
			for (j = 0; j < 2 *i + 1; j++) {
				printf("%d", i);
			}
		}
		else if (i > inputOdd / 2) {					// i�� ��� �ٿ� ��µ� ������ ū ���
			for (j = 0; j < i - inputOdd / 2; j++) {
				printf(" ");
			}
			for (j = 0; j < 2 * (inputOdd - i - 1) + 1; j++) {
				printf("%d", i);
			}
		}
		else {											// i�� ��� �ٿ� ��µ� ���� ���
			for (j = 0; j < inputOdd; j++) {
				printf("%d", i);
			}
		}
		printf("\n");
	}

	printf("\n");

	return 0;
}