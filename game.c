// ���� ������ ���ų�, ������ ������ �� �ִ�.
// �� ����� ���̵� �Է¹޴´�.
// 8 * 8�� �������� �׷�����.	
// �� �߾ӿ� ��� ���� ������ ���� ������ �����Ѵ�.
// ������ �Ʒ����� ���� ������ ��Ȳ�� �����ִ�.
// ���� ���� ��ġ�� �Է¹޴´�.
	// Ű������ ����Ű�� �̿��� Ŀ���� �̵���ų �� �ִ�.
    // ���ͳ� �����̽��� �̿��� Ŀ���� �ִ� ��ġ�� ���� ���� �� �ִ�.
	// �̹� ���� �ְų� ���� ���� �� ���� ��ġ���� ���� �� ����.
// ���� ���� �������� �� 8�������� ���� ���� �˻��Ѵ�.
	// 1ĭ �տ� ������ ���� �ִ��� Ȯ���Ѵ�.
	// �� �����̰ų� �� ���� �ִٸ� ���� ���� �� �����Ƿ� �˻縦 ���� �ʴ´�.
	// ����� ���� �ִٸ� ���� ���� ���ɼ��� �����Ƿ� �� ĭ�� ���ư��� �˻縦 �����Ѵ�.
		// �˻� �� ����� ���� ������ �˻縦 ��� �����Ѵ�.
		// �˻� �� �� ������ �����ų� �������� ����� �˻縦 �����Ѵ�.
		// �˻� �� �� ���� ������ ��� �˻��� ����� ���� ��� �� ���� ����� �˻縦 �����Ѵ�.
// ���� ���� ���� �� ���� ��� �ڵ����� ���� �Ѱ�����.
// G�� ������ ������ ������ �� �ִ�.
// ������ ����� ������ �ݺ��Ѵ�
	// �������� ��� ä������ ���
	// �� ��� ��� ���� ���� �� ���� ���
	// �� ����� ���� ���� ���
	// �� ��밡 ������ �������� ���
// ���� ����� ����Ѵ�.
// ��õ� ���θ� �����.

#include "othello.h"

int board[8][8]; // ������
int boardTemp[64][8][8]; // ������ �ӽ� ����
int turn; // ����
int switchTurn; // �� �ѱ��
int placeable; // ��ġ ���� ����
int restart; // ��õ� ����
int finished; // ���� ���� ����
int checkPiecePlace; // �� ��ġ ���
char turnID[255]; // ���� ����� ID
char whiteID[255], blackID[255]; // �� ID, �� ID

int main() {

	SetConsoleTitle("OTHELLO");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	system("mode con:cols=82 lines=23");

	while (1) {

		switch (startMenu()) {

		// 1�� : ���� ����
		case 1:
			break;

		// 2�� : ���α׷� ����
		case 2:
			return 0;

		}

		getID(&whiteID, &blackID); // ID �Է�
		turn = 2; // ���� ��

		// ������ �ʱ�ȭ
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				board[i][j] = 0;

		board[3][3] = 1, board[4][4] = 1; // �鵹 ���� ��ġ
		board[3][4] = 2, board[4][3] = 2; // �浹 ���� ��ġ

		while (1) {

			// �� ��ġ ���� ���� Ȯ��
			if (checkPlaceable(board, turn)) {

				checkPiecePlace = piecePlace(board, boardTemp, turn, whiteID, blackID);

				if (!checkPiecePlace) break; // �� �ѱ��
				else if (checkPiecePlace == 1) return 0; // ����
				else if (checkPiecePlace == 2) restart = 1; // �����

			}
			else {

				printBoard(board, turn, whiteID, blackID); // ������ ���
				
				if (!placeable) printf(" ���� ���� �� �ִ� ���� �����ϴ�!\n �� �ѱ�� <��");
				while (1) {
					switch (getch()) {

					case 13:
					case 32:
						switchTurn = 1;
						break;
					
					}
					if (switchTurn) {

						switchTurn = 0;
						break;

					}
				}
			}

			// �� ����
			if (checkPiecePlace != 2) {

				if (turn == 1) turn = 2;
				else if (turn == 2) turn = 1;

			}

			// ���� ���� Ȯ��
			finished = checkFinish(board);
			if (finished == 1 || finished == 2 || finished == 3) {
				
				printBoard(board, turn, whiteID, blackID);

				switch (checkFinish(board)) {

				case 1:
					printf(" �� �̻� �� ������ �����ϴ�!\n");
					break;

				case 2:
					printf(" �� ����� ���� �����߽��ϴ�!\n");
					break;

				case 3:
					printf(" �� ��� ��� ���� ���� �� �����ϴ�!\n");
					break;

				}

				printResult(board, whiteID, blackID); // ���� ��� ���
				
				// ��õ� ���� Ȯ��
				if (retry() == 2) restart = 1;
				else return 0;

			}

			// ������� ���� ���� �ʱ�ȭ
			if (restart) {

				turn = 0;
				placeable = 0;
				restart = 0;
				turnID[0] = NULL;
				break;

			}
		}
	}
}