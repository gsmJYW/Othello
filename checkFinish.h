#include "checkPlaceable.h"

// 게임 종료 조건
int checkFinish(int board[][8]) {

	int empty = 0; // 빈 공간
	int finished = 0; // 종료 여부
	int white = 0, black = 0; // 흑돌, 백돌
	int whitePlaceable = checkPlaceable(board, 1); // 백의 돌 배치 가능 여부
	int blackPlaceable = checkPlaceable(board, 2); // 흑의 돌 배치 가능 여부

	// 빈 공간, 흑돌, 백돌이 하나라도 있는지 검사
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (board[i][j]) {

			// 빈 공간
			case 0:
				empty = 1;
				break;

			// 백돌
			case 1:
				white = 1;
				break;

			// 흑돌
			case 2:
				black = 1;
				break;

			}
		}
	}

	if (!empty) finished = 1; // 보드판이 모두 채워졌을 경우
	else if (!white || !black) finished = 2; // 한 상대의 돌만 남은 경우
	else if (!whitePlaceable && !blackPlaceable) finished = 3; // 두 상대 모두 돌을 놓을 수 없는 경우
															 
	return finished;

}