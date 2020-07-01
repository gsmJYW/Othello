#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "reversi.h"
#include "printPlace.h"
#include "printBoard.h"

// �� ��ġ
int piecePlace(int board[][8], int boardTemp[][8][8], int turn, char whiteID[], char blackID[]) {

	int x = 0, y = 0; // Ŀ�� ��ǥ
	int placeable; // ��ġ ���� ����
	int check = 0; // ��ġ �õ� ����

	while (1) {

		printPlace(board, turn, x, y, whiteID, blackID); // ������ & Ŀ�� ���

		placeable = 0;
		check = 0;

		switch (getch()) {

		// ���� & �����̽� : �� ��ġ
		case 13:
		case 32:
			check = 1;
			placeable = reversi(board, boardTemp, turn, x, y);
			break;

		// �� : �������� �̵�
		case 75:
			if (x > 0) x--;
			break;

		// �� : ���������� �̵�
		case 77:
			if (x < 7) x++;
			break;

		// �� : �������� �̵�
		case 72:
			if (y > 0) y--;
			break;

		// �� : �Ʒ������� �̵�
		case 80:
			if (y < 7) y++;
			break;

		// G : ����
		case 'g':
		case 'G': 
			printBoard(board, turn, whiteID, blackID);
			printf(" %s��(��) ������ ���� �Ͽ����ϴ�!\n %s�� ��\n\n", (turn == 1) ? whiteID : blackID, (turn == 1) ? blackID : whiteID);
			return retry();

		}

		if (placeable && placeable != -1) return 3;

	}
}