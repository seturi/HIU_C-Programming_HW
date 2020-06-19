#include <stdio.h>

/*
�Լ��̸�: get_nearest_number
���: ���ڷ� ���� �迭 list���� target�� ���� �����ϴ� ��Ҹ� ã�� ����Ѵ�.
����: int list[] �Է¹��� ������ �̷���� �迭
	  int length �迭�� ����
	  int target �������� �Ǵ��� ������ Ư�� ����
��ȯ: ����
�ۼ���¥: 2020/06/19
�ۼ���: �����
*/
void get_nearest_number(int list[], int length, int target) 
{
	int differenceList[10];						// target�� list �迭�� ����� ���� ������� ������ �迭 ũ�⸦ 10���� ����
	int minDif;									// target�� ���̰� ���� ���� ���ڸ� ������ ���� ����

	for (int i = 0; i < length; i++) {			// length��ŭ �ݺ����� ���� differenceList�� target�� list�� ����� ��(����)�� ����
		if (target > list[i]) {					// target�� list�� i��° ��Һ��� ū ���
			differenceList[i] = target - list[i];
		}
		else {									// target�� list�� i��° ��Һ��� �۰ų� ���� ���
			differenceList[i] = list[i] - target;
		}
	}

	minDif = differenceList[0];					// �켱 differenceList�� ù ��° ����� ���� minDif�� ����

	for (int i = 0; i < length; i++) {
		if (minDif > differenceList[i]) {		// minDif�� ����Ǿ��ִ� ������ differenceList�� i��° ��Ұ� �� ���� ���
			minDif = differenceList[i];			// minDif�� ���� �� ����� ������ �ٽ� �����Ѵ�.
		}
	}

	printf("���� ������ ���� : ");
	for (int i = 0; i < length; i++) {
		if (differenceList[i] == minDif) {		// differenceList�� i��° ��Ұ� minDif�� ����Ǿ��ִ� ���� ���� ���
			printf("%d ", list[i]);				// list�� i��° ��Ұ� target�� ���� �����ϹǷ� �̸� ���
		}
	}
}


/*
	main �Լ�
�ۼ���¥: 2020/06/19
�ۼ���: �����
*/
int main() 
{
	int length, target;							// �迭�� �Է°��� ����ִ� ������ ������ length�� �迭�� ��ҿ� Ư�� ���� target ����
	int list[10];								// ũ�Ⱑ 10�� �迭 ����

	/*
		2�̻� 10������ ������ �Է¹޾� length�� ����
		�̶� �������� ����� ���, �ٽ� �Է¹���.
	*/
	printf("2�̻� 10������ ������ �Է��Ͻÿ� : ");
	while (1) {									// ������ �´� ���� �Է¹��� ������ �ݺ����� �����Ѵ�.
		scanf("%d", &length);
		if (length < 2 || length > 10) {		// �������� ����� ��� �ٽ� �Է¹޴´�.
			printf("2�̻� 10������ ������ �ƴմϴ�. �ٽ� �Է����ּ���.");
		}
		else {									// ������ �´� ��� �ݺ����� ����������.
			break;
		}
	}
	
	/* length��ŭ ������ �Է¹޾� list�� ���� */
	printf("%d���� �������� �Է��Ͻÿ� : ", length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &list[i]);
	}

	/* Ư�� ���ڸ� �Է¹޾� target�� ���� */
	printf("Ư�� ���ڸ� �Է��Ͻÿ� : ");
	scanf("%d", &target);

	get_nearest_number(list, length, target);	// get_nearest_number �Լ��� list, length, target�� ���ڷ� �Ѱ� target�� ���� ������ ���� ���

	return 0;
}