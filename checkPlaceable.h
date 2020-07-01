#include "checkReversi.h"

// 돌 배치 가능 여부
int checkPlaceable(int board[][8], int turn) {

	int placeable = 0; // 배치 가능 칸 수

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			placeable += checkReversi(board, turn, j, i); // 둘 수 있는 곳이 있는지 검사

	return placeable; // 돌 수 없을 경우 0 반환

}