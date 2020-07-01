#include <stdio.h>

// 뒤집기 가능 여부
int checkReversi(int board[][8], int turn, int x, int y) {

	// 현재 커서가 있는 위치 기억
	int ox = x;
	int oy = y;
	int reversible = 0;

	// 빈 공간이 아닌 경우 돌을 놓을 수 없음
	if (board[oy][ox] == 1 || board[oy][ox] == 2) return 0;

	// 오른쪽 검사
	if (board[oy][ox + 1] != turn && board[oy][ox + 1] != 0) {

		while (1) {
			x++;
			if (x > 7) break;

			if (!board[y][x]) break;
			if (board[y][x] == turn) {

				reversible = 1;
				break;

			}
		}
	}

	x = ox;
	y = oy;

	// 왼쪽 검사
	if (board[oy][ox - 1] != turn && board[oy][ox - 1] != 0) {

		while (1) {

			x--;
			if (x < 0) break;

			if (!board[y][x]) break;
			if (board[y][x] == turn) {

				reversible = 1;
				break;

			}
		}
	}

	x = ox;
	y = oy;

	// 아래쪽 검사
	if (board[oy + 1][ox] != turn && board[oy + 1][ox] != 0) {

		while (1) {

			y++;
			if (y > 7) break;

			if (!board[y][x]) break;
			if (board[y][x] == turn) {

				reversible = 1;
				break;

			}
		}
	}

	x = ox;
	y = oy;

	// 위쪽 검사
	if (board[oy - 1][ox] != turn && board[oy - 1][ox] != 0) {

		while (1) {

			y--;
			if (y < 0) break;

			if (!board[y][x]) break;
			if (board[y][x] == turn) {

				reversible = 1;
				break;

			}
		}
	}

	x = ox;
	y = oy;

	// 오른쪽 아래 검사
	if (board[oy + 1][ox + 1] != turn && board[oy + 1][ox + 1] != 0) {

		while (1) {

			x++;
			y++;
			if (x > 7 || y > 7) break;

			if (!board[y][x]) break;
			if (board[y][x] == turn) {

				reversible = 1;
				break;

			}
		}
	}

	x = ox;
	y = oy;

	// 왼쪽 아래 검사
	if (board[oy + 1][ox - 1] != turn && board[oy + 1][ox - 1] != 0) {

		while (1) {

			x--;
			y++;
			if (x < 0 || y > 7) break;

			if (!board[y][x]) break;
			if (board[y][x] == turn) {

				reversible = 1;
				break;

			}
		}
	}

	x = ox;
	y = oy;

	// 오른쪽 위 검사
	if (board[oy - 1][ox + 1] != turn && board[oy - 1][ox + 1] != 0) {

		while (1) {

			x++;
			y--;
			if (x > 7 || y < 0) break;

			if (!board[y][x]) break;
			if (board[y][x] == turn) {

				reversible = 1;
				break;

			}
		}
	}

	x = ox;
	y = oy;

	// 왼쪽 위 검사
	if (board[oy - 1][ox - 1] != turn && board[oy - 1][ox - 1] != 0) {

		while (1) {

			x--;
			y--;
			if (x < 0 || y < 0) break;

			if (!board[y][x]) break;
			if (board[y][x] == turn) {

				reversible = 1;
				break;

			}
		}
	}

	return reversible; // 뒤집을 수 있는 경우 1, 뒤집지 못하는 경우 0 반환

}