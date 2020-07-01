#include <stdio.h>

// �� ������
int reversi(int board[][8], int boardTemp[][8][8], int turn, int x, int y) {

	// ���� Ŀ���� �ִ� ��ġ ���
	int ox = x;
	int oy = y;
	int reversible = 0;
	
	// �� ������ �ƴ� ��� ���� ���� �� ����
	if (board[oy][ox] == 1 || board[oy][ox] == 2) return -1;

	// ������ �˻�
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

	// ���� �˻�
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

	// ���� �˻�
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

	// �Ʒ��� �˻�
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

	// ������ �Ʒ� �˻�
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

	// ���� �Ʒ� �˻�
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

	// ������ �� �˻�
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

	// ���� �� �˻�
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

	return reversible; // ������ ��� 1, �� ������ ��� 0 ��ȯ

}