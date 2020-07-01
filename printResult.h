#include <stdio.h>

// ���� ��� ���
void printResult(int board[][8], char whiteID[], char blackID[]) {

	int white = 0, black = 0; // ��� �� ����

	// �� ���� ī��Ʈ
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

	// ����� ���
	if (white == black) printf(" ���º�\n\n");
	else printf(" %s�� ��\n\n", (white > black) ? whiteID : blackID);

	return;

}