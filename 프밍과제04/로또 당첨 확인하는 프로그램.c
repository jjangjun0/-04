#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 6

int main(void)
{

	// 1. 2차원 배열 선언과 동시에 초기화
	int my_lotto[M][N] = {
		{ 1, 2, 3, 4, 5, 6 },
		{ 10, 15, 25, 35, 40, 42 },
		{ 1, 9, 11, 22, 23, 25 },
		{ 9, 28, 31, 34, 35, 36 },
		{ 1, 9, 23, 28, 33, 35 }
	};

	// 2. 키보드 입력으로 로또 번호 6개와 보너스 번호 1개를 받는다
	int lotto_num[N];
	int bonus_num;
	printf("금주의 로또 번호를 입력하세요 -> ");

	int n;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &n);
		lotto_num[i] = n;
	}

	printf("보너스 번호를 입력하세요 -> ");
	scanf_s("%d", &n);
	bonus_num = n;


	//for (int i = 0; i < N; i++) printf("lotto_num[%d] = %d\n", i, lotto_num[i]);
	//printf("%d", bonus_num);


	// 3. 출력

	printf("\n");
	printf("홍길동님의 로또 당첨 결과는 다음과 같습니다.\n");
	printf("\n");
	int x, y;

	int check_LottoNum[M] = { 0 };		// 몇 등인지 확인하는 배열
	int lotto_result[M][N] = { 0 };		// 로또 번호 일치 확인하는 배열
	int check_bonus = 0;				// 보너스 번호 확인하는 배열

	for (x = 0; x < M; x++) {
		printf("%d세트 번호", x + 1);

		printf("<");
		for (y = 0; y < N; y++) {
			printf("%d", my_lotto[x][y]);
			if (y != 5)
				printf(" ");
		}
		printf(">");


		// 로또 당첨 결과 출력
		printf(" -> ");
		//for(int i=0;i<6;i++) printf("%d ", lotto_result[x][i]);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (my_lotto[x][i] == lotto_num[j]) {	// 로또 번호 6자리 확인
					lotto_result[x][i] = 1;
					check_LottoNum[x] += 1;
				}
			}
		}

		if (check_LottoNum[x] == 5) {					// 5개가 일치했을 때 보너스 번호 확인
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
			printf("<꽝>");
			break;
		case 3:
			printf("<5등>");
			break;
		case 4:
			printf("<4등>");
			break;
		case 5:
			if (check_bonus == 0)
				printf("<3등>");
			else if (check_bonus == 1)
				printf("<2등>");
			break;
		case 6:
			printf("<1등>");
			break;
		}

		printf("\n");
	}

	return 0;
}
