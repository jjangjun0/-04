#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 6

int main(void)
{

	// 1. 2���� �迭 ����� ���ÿ� �ʱ�ȭ
	int my_lotto[M][N] = {
		{ 1, 2, 3, 4, 5, 6 },
		{ 10, 15, 25, 35, 40, 42 },
		{ 1, 9, 11, 22, 23, 25 },
		{ 9, 28, 31, 34, 35, 36 },
		{ 1, 9, 23, 28, 33, 35 }
	};

	// 2. Ű���� �Է����� �ζ� ��ȣ 6���� ���ʽ� ��ȣ 1���� �޴´�
	int lotto_num[N];
	int bonus_num;
	printf("������ �ζ� ��ȣ�� �Է��ϼ��� -> ");

	int n;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &n);
		lotto_num[i] = n;
	}

	printf("���ʽ� ��ȣ�� �Է��ϼ��� -> ");
	scanf_s("%d", &n);
	bonus_num = n;


	//for (int i = 0; i < N; i++) printf("lotto_num[%d] = %d\n", i, lotto_num[i]);
	//printf("%d", bonus_num);


	// 3. ���

	printf("\n");
	printf("ȫ�浿���� �ζ� ��÷ ����� ������ �����ϴ�.\n");
	printf("\n");
	int x, y;

	int check_LottoNum[M] = { 0 };		// �� ������ Ȯ���ϴ� �迭
	int lotto_result[M][N] = { 0 };		// �ζ� ��ȣ ��ġ Ȯ���ϴ� �迭
	int check_bonus = 0;				// ���ʽ� ��ȣ Ȯ���ϴ� �迭

	for (x = 0; x < M; x++) {
		printf("%d��Ʈ ��ȣ", x + 1);

		printf("<");
		for (y = 0; y < N; y++) {
			printf("%d", my_lotto[x][y]);
			if (y != 5)
				printf(" ");
		}
		printf(">");


		// �ζ� ��÷ ��� ���
		printf(" -> ");
		//for(int i=0;i<6;i++) printf("%d ", lotto_result[x][i]);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (my_lotto[x][i] == lotto_num[j]) {	// �ζ� ��ȣ 6�ڸ� Ȯ��
					lotto_result[x][i] = 1;
					check_LottoNum[x] += 1;
				}
			}
		}

		if (check_LottoNum[x] == 5) {					// 5���� ��ġ���� �� ���ʽ� ��ȣ Ȯ��
			for (int i = 0; i < N; i++) {
				if (my_lotto[x][i] == bonus_num) {
					lotto_result[x][i] = 1;
					check_bonus += 1;
				}
			}
		}

		//printf("\n");
		//for(int i=0;i<6;i++) printf("%d ", lotto_result[x][i]);

		for (int i = 0; i < N; i++) {
			if (lotto_result[x][i] == 0)
				printf("X ");
			else if (lotto_result[x][i] == 1)
				printf("%d ", my_lotto[x][i]);
		}

		//printf("%d", check_LottoNum[x]);
		switch (check_LottoNum[x]) {
		case 0:
		case 1:
		case 2:
			printf("<��>");
			break;
		case 3:
			printf("<5��>");
			break;
		case 4:
			printf("<4��>");
			break;
		case 5:
			if (check_bonus == 0)
				printf("<3��>");
			else if (check_bonus == 1)
				printf("<2��>");
			break;
		case 6:
			printf("<1��>");
			break;
		}

		printf("\n");
	}

	return 0;
}
