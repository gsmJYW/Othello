#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "reversi.h"
#include "printPlace.h"
#include "printBoard.h"

// 돌 설치
int piecePlace(int board[][8], int boardTemp[][8][8], int turn, char whiteID[], char blackID[]) {

	int x = 0, y = 0; // 커서 좌표
	int placeable; // 배치 가능 여부
	int check = 0; // 배치 시도 여부

	while (1) {

		printPlace(board, turn, x, y, whiteID, blackID); // 보드판 & 커서 출력

		placeable = 0;
		check = 0;

		switch (getch()) {

		// 엔터 & 스페이스 : 돌 설치
		case 13:
		case 32:
			check = 1;
			placeable = reversi(board, boardTemp, turn, x, y);
			break;

		// ← : 왼쪽으로 이동
		case 75:
			if (x > 0) x--;
			break;

		// → : 오른쪽으로 이동
		case 77:
			if (x < 7) x++;
			break;

		// ↑ : 위쪽으로 이동
		case 72:
			if (y > 0) y--;
			break;

		// ↓ : 아래쪽으로 이동
		case 80:
			if (y < 7) y++;
			break;

		// G : 포기
		case 'g':
		case 'G': 
			printBoard(board, turn, whiteID, blackID);
			printf(" %s이(가) 게임을 포기 하였습니다!\n %s의 승\n\n", (turn == 1) ? whiteID : blackID, (turn == 1) ? blackID : whiteID);
			return retry();

		}

		if (placeable && placeable != -1) return 3;

	}
}