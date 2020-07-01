// 게임 설명을 보거나, 게임을 시작할 수 있다.
// 두 상대의 아이디를 입력받는다.
// 8 * 8의 보드판이 그려진다.	
// 정 중앙에 흑백 돌을 교차로 놓고 게임을 시작한다.
// 보드판 아래에는 현재 게임의 상황이 나와있다.
// 돌을 놓을 위치를 입력받는다.
	// 키보드의 방향키를 이용해 커서를 이동시킬 수 있다.
    // 엔터나 스페이스를 이용해 커서가 있는 위치에 돌을 놓을 수 있다.
	// 이미 돌이 있거나 돌을 먹을 수 없는 위치에는 놓을 수 없다.
// 놓은 돌을 기준으로 한 8방향으로 먹을 돌을 검사한다.
	// 1칸 앞에 누구의 돌이 있는지 확인한다.
	// 빈 공간이거나 내 돌이 있다면 돌을 먹을 수 없으므로 검사를 하지 않는다.
	// 상대의 돌이 있다면 돌을 먹을 가능성이 있으므로 한 칸씩 나아가며 검사를 시작한다.
		// 검사 중 상대의 돌을 만나면 검사를 계속 진행한다.
		// 검사 중 빈 공간을 만나거나 보드판을 벗어나면 검사를 중지한다.
		// 검사 중 내 돌을 만나면 방금 검사한 상대의 돌을 모두 내 돌로 만들고 검사를 중지한다.
// 만약 돌을 놓을 수 없는 경우 자동으로 턴이 넘겨진다.
// G를 누르면 게임을 포기할 수 있다.
// 게임이 종료될 때까지 반복한다
	// 보드판이 모두 채워졌을 경우
	// 두 상대 모두 돌을 놓을 수 없는 경우
	// 한 상대의 돌만 남은 경우
	// 한 상대가 게임을 포기했을 경우
// 게임 결과를 출력한다.
// 재시도 여부를 물어본다.

#include "othello.h"

int board[8][8]; // 보드판
int boardTemp[64][8][8]; // 보드판 임시 저장
int turn; // 차례
int switchTurn; // 턴 넘기기
int placeable; // 배치 가능 여부
int restart; // 재시도 여부
int finished; // 게임 종료 조건
int checkPiecePlace; // 돌 배치 결과
char turnID[255]; // 선인 상대의 ID
char whiteID[255], blackID[255]; // 백 ID, 흑 ID

int main() {

	SetConsoleTitle("OTHELLO");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	system("mode con:cols=82 lines=23");

	while (1) {

		switch (startMenu()) {

		// 1번 : 게임 시작
		case 1:
			break;

		// 2번 : 프로그램 종료
		case 2:
			return 0;

		}

		getID(&whiteID, &blackID); // ID 입력
		turn = 2; // 흑의 선

		// 보드판 초기화
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				board[i][j] = 0;

		board[3][3] = 1, board[4][4] = 1; // 백돌 시작 위치
		board[3][4] = 2, board[4][3] = 2; // 흑돌 시작 위치

		while (1) {

			// 돌 배치 가능 여부 확인
			if (checkPlaceable(board, turn)) {

				checkPiecePlace = piecePlace(board, boardTemp, turn, whiteID, blackID);

				if (!checkPiecePlace) break; // 턴 넘기기
				else if (checkPiecePlace == 1) return 0; // 종료
				else if (checkPiecePlace == 2) restart = 1; // 재시작

			}
			else {

				printBoard(board, turn, whiteID, blackID); // 보드판 출력
				
				if (!placeable) printf(" 돌을 놓을 수 있는 곳이 없습니다!\n 턴 넘기기 <┘");
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

			// 턴 변경
			if (checkPiecePlace != 2) {

				if (turn == 1) turn = 2;
				else if (turn == 2) turn = 1;

			}

			// 게임 종료 확인
			finished = checkFinish(board);
			if (finished == 1 || finished == 2 || finished == 3) {
				
				printBoard(board, turn, whiteID, blackID);

				switch (checkFinish(board)) {

				case 1:
					printf(" 더 이상 빈 공간이 없습니다!\n");
					break;

				case 2:
					printf(" 한 상대의 돌이 전멸했습니다!\n");
					break;

				case 3:
					printf(" 두 상대 모두 돌을 놓을 수 없습니다!\n");
					break;

				}

				printResult(board, whiteID, blackID); // 게임 결과 출력
				
				// 재시도 여부 확인
				if (retry() == 2) restart = 1;
				else return 0;

			}

			// 재시작을 위해 변수 초기화
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