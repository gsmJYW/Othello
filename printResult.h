#include <stdio.h>

// 게임 결과 출력
void printResult(int board[][8], char whiteID[], char blackID[]) {

	int white = 0, black = 0; // 흑백 돌 개수

	// 돌 개수 카운트
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (board[i][j]) {

			case 1:
				white++;
				break;

			case 2:
				black++;
				break;

			}
		}
	}

	// 우승자 출력
	if (white == black) printf(" 무승부\n\n");
	else printf(" %s의 승\n\n", (white > black) ? whiteID : blackID);

	return;

}