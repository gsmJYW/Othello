#include "checkReversi.h"

// �� ��ġ ���� ����
int checkPlaceable(int board[][8], int turn) {

	int placeable = 0; // ��ġ ���� ĭ ��

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			placeable += checkReversi(board, turn, j, i); // �� �� �ִ� ���� �ִ��� �˻�

	return placeable; // �� �� ���� ��� 0 ��ȯ

}