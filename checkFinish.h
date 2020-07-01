#include "checkPlaceable.h"

// ���� ���� ����
int checkFinish(int board[][8]) {

	int empty = 0; // �� ����
	int finished = 0; // ���� ����
	int white = 0, black = 0; // �浹, �鵹
	int whitePlaceable = checkPlaceable(board, 1); // ���� �� ��ġ ���� ����
	int blackPlaceable = checkPlaceable(board, 2); // ���� �� ��ġ ���� ����

	// �� ����, �浹, �鵹�� �ϳ��� �ִ��� �˻�
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (board[i][j]) {

			// �� ����
			case 0:
				empty = 1;
				break;

			// �鵹
			case 1:
				white = 1;
				break;

			// �浹
			case 2:
				black = 1;
				break;

			}
		}
	}

	if (!empty) finished = 1; // �������� ��� ä������ ���
	else if (!white || !black) finished = 2; // �� ����� ���� ���� ���
	else if (!whitePlaceable && !blackPlaceable) finished = 3; // �� ��� ��� ���� ���� �� ���� ���
															 
	return finished;

}