#include <stdio.h>

// 돌 뒤집기
int reversi(int board[][8], int boardTemp[][8][8], int turn, int x, int y) {

	// 현재 커서가 있는 위치 기억
	int ox = x;
	int oy = y;
	int reversible = 0;
	
	// 빈 공간이 아닌 경우 돌을 놓을 수 없음
	if (board[oy][ox] == 1 || board[oy][ox] == 2) return -1;

	// 오른쪽 검사
	if (board[oy][ox + 1] != turn && board[oy][ox + 1] != 0) {

		while (1) {

			x++;
			if (x > 7) break;

			if (!board[y][x]) break;
			if (board[y][x] != turn && board[y][x] != 0) board[y][x] = turn + 2;
			if (board[y][x] == turn) {

				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (board[i][j] == 3 || board[i][j] == 4) board[i][j] -= 2;

				reversible = 1;
				board[oy][ox] = turn;
				break;

			}
		}

		if (reversible != 1) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {

					if (board[i][j] == 3) board[i][j] = 2;
					else if (board[i][j] == 4) board[i][j] = 1;

				}
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
			if (board[y][x] != turn && board[y][x] != 0) board[y][x] = turn + 2;
			if (board[y][x] == turn) {
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (board[i][j] == 3 || board[i][j] == 4) board[i][j] -= 2;

				reversible = 2;
				board[oy][ox] = turn;
				break;

			}
		}

		if (reversible != 2) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {

					if (board[i][j] == 3) board[i][j] = 2;
					else if (board[i][j] == 4) board[i][j] = 1;

				}
			}
		}
	}

	x = ox;
	y = oy;

	// 위쪽 검사
	if (board[oy + 1][ox] != turn && board[oy + 1][ox] != 0) {

		while (1) {

			y++;
			if (y > 7) break;

			if (!board[y][x]) break;
			if (board[y][x] != turn && board[y][x] != 0) board[y][x] = turn + 2;
			if (board[y][x] == turn) {

				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (board[i][j] == 3 || board[i][j] == 4) board[i][j] -= 2;

				reversible = 3;
				board[oy][ox] = turn;
				break;

			}
		}

		if (reversible != 3) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {

					if (board[i][j] == 3) board[i][j] = 2;
					else if (board[i][j] == 4) board[i][j] = 1;

				}
			}
		}
	}

	x = ox;
	y = oy;

	// 아래쪽 검사
	if (board[oy - 1][ox] != turn && board[oy - 1][ox] != 0) {

		while (1) {

			y--;
			if (y < 0) break;

			if (!board[y][x]) break;
			if (board[y][x] != turn && board[y][x] != 0) board[y][x] = turn + 2;
			if (board[y][x] == turn) {

				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (board[i][j] == 3 || board[i][j] == 4) board[i][j] -= 2;

				reversible = 4;
				board[oy][ox] = turn;
				break;

			}
		}

		if (reversible != 4) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {

					if (board[i][j] == 3) board[i][j] = 2;
					else if (board[i][j] == 4) board[i][j] = 1;

				}
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
			if (board[y][x] != turn && board[y][x] != 0) board[y][x] = turn + 2;
			if (board[y][x] == turn) {

				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (board[i][j] == 3 || board[i][j] == 4) board[i][j] -= 2;

				reversible = 5;
				board[oy][ox] = turn;
				break;

			}
		}

		if (reversible != 5) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {

					if (board[i][j] == 3) board[i][j] = 2;
					else if (board[i][j] == 4) board[i][j] = 1;

				}
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
			if (board[y][x] != turn && board[y][x] != 0) board[y][x] = turn + 2;
			if (board[y][x] == turn) {

				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (board[i][j] == 3 || board[i][j] == 4) board[i][j] -= 2;

				reversible = 6;
				board[oy][ox] = turn;
				break;

			}
		}

		if (reversible != 6) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {

					if (board[i][j] == 3) board[i][j] = 2;
					else if (board[i][j] == 4) board[i][j] = 1;

				}
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
			if (board[y][x] != turn && board[y][x] != 0) board[y][x] = turn + 2;
			if (board[y][x] == turn) {

				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (board[i][j] == 3 || board[i][j] == 4) board[i][j] -= 2;

				reversible = 7;
				board[oy][ox] = turn;
				break;

			}
		}

		if (reversible != 7) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {

					if (board[i][j] == 3) board[i][j] = 2;
					else if (board[i][j] == 4) board[i][j] = 1;

				}
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
			if (board[y][x] != turn && board[y][x] != 0) board[y][x] = turn + 2;
			if (board[y][x] == turn) {

				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (board[i][j] == 3 || board[i][j] == 4) board[i][j] -= 2;

				reversible = 8;
				board[oy][ox] = turn;
				break;

			}
		}

		if (reversible != 8) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {

					if (board[i][j] == 3) board[i][j] = 2;
					else if (board[i][j] == 4) board[i][j] = 1;

				}
			}
		}
	}

	return reversible; // 뒤집은 경우 1, 못 뒤집은 경우 0 반환

}