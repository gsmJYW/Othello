#include <stdio.h>

// ������ ���� ����
int checkReversi(int board[][8], int turn, int x, int y) {

	// ���� Ŀ���� �ִ� ��ġ ���
	int ox = x;
	int oy = y;
	int reversible = 0;

	// �� ������ �ƴ� ��� ���� ���� �� ����
	if (board[oy][ox] == 1 || board[oy][ox] == 2) return 0;

	// ������ �˻�
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

	// ���� �˻�
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

	// �Ʒ��� �˻�
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

	// ���� �˻�
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

	// ������ �Ʒ� �˻�
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

	// ���� �Ʒ� �˻�
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

	// ������ �� �˻�
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

	// ���� �� �˻�
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

	return reversible; // ������ �� �ִ� ��� 1, ������ ���ϴ� ��� 0 ��ȯ

}