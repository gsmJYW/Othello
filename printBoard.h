#include <stdio.h>
#include <Windows.h>

// ������ ���
void printBoard(int board[][8], int turn, char whiteID[], char blackID[]) {

	int white = 0, black = 0; // ��� �� ����
	char piece[8][8][3]; // �� ��¿� �迭

	// ������ �˻� �� �迭�� �� or ���� ����
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (board[i][j]) {

			case 0:
				strcpy(piece[i][j], "��");
				break;

			case 1:
				strcpy(piece[i][j], "��");
				break;

			case 2:
				strcpy(piece[i][j], "��");
				break;

			}
		}
	}

	// ������ ���
	system("cls");
	printf("������������������������������������������������������������������\n�� %s�� %s�� %s�� %s�� %s�� %s�� %s�� %s��\n������������������������������������������������������������������\n�� %s�� %s�� %s�� %s�� %s�� %s�� %s�� %s��\n������������������������������������������������������������������\n�� %s�� %s�� %s�� %s�� %s�� %s�� %s�� %s��\n������������������������������������������������������������������\n�� %s�� %s�� %s�� %s�� %s�� %s�� %s�� %s��\n������������������������������������������������������������������\n�� %s�� %s�� %s�� %s�� %s�� %s�� %s�� %s��\n������������������������������������������������������������������\n�� %s�� %s�� %s�� %s�� %s�� %s�� %s�� %s��\n������������������������������������������������������������������\n�� %s�� %s�� %s�� %s�� %s�� %s�� %s�� %s��\n������������������������������������������������������������������\n�� %s�� %s�� %s�� %s�� %s�� %s�� %s�� %s��\n������������������������������������������������������������������\n", piece[0][0], piece[0][1], piece[0][2], piece[0][3], piece[0][4], piece[0][5], piece[0][6], piece[0][7], piece[1][0], piece[1][1], piece[1][2], piece[1][3], piece[1][4], piece[1][5], piece[1][6], piece[1][7], piece[2][0], piece[2][1], piece[2][2], piece[2][3], piece[2][4], piece[2][5], piece[2][6], piece[2][7], piece[3][0], piece[3][1], piece[3][2], piece[3][3], piece[3][4], piece[3][5], piece[3][6], piece[3][7], piece[4][0], piece[4][1], piece[4][2], piece[4][3], piece[4][4], piece[4][5], piece[4][6], piece[4][7], piece[5][0], piece[5][1], piece[5][2], piece[5][3], piece[5][4], piece[5][5], piece[5][6], piece[5][7], piece[6][0], piece[6][1], piece[6][2], piece[6][3], piece[6][4], piece[6][5], piece[6][6], piece[6][7], piece[7][0], piece[7][1], piece[7][2], piece[7][3], piece[7][4], piece[7][5], piece[7][6], piece[7][7]);

	// NOTE : �������� for���� ������� �ʰ� printf �ϳ��� ����� ������
	//        for�� ���� �����̷� ���� ȭ���� �����Ÿ��� ���̱� ������

	// for�� ������ ��� �ڵ�
	/*
	system("cls");
	printf("������������������������������������������������������������������\n");
	for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {

	printf("�� %s", piece[i][j]);

	}

	printf("��\n");
	if (i != 7) printf("������������������������������������������������������������������\n");

	}
	printf("������������������������������������������������������������������\n");
	*/

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

	// �� ���� ���
	if (turn == 1) {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		printf(" %s ", whiteID);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("%d VS %d %s\n\n", white, black, blackID);

	}
	else if (turn == 2) {

		printf(" %s %d VS %d", whiteID, white, black);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

		printf(" %s\n\n", blackID);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	}

	return;

}