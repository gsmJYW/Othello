#include <stdio.h>
#include <Windows.h>
#include <conio.h>

// 시작 메뉴
int startMenu() {

	int menu = 0; // 메뉴 선택

	system("cls");
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
	printf("　■■■　　■■■■■　■　　　■　■■■■■　■　　　　　■　　　　　　■■■　\n");
	printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
	printf("■　　　■　　　■　　　■■■■■　■■■■■　■　　　　　■　　　　　■　　　■\n");
	printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
	printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
	printf("　■■■　　　　■　　　■　　　■　■■■■■　■■■■■　■■■■■　　■■■\n");
	printf("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
	printf("　　　　　　　　　　　　　　　　　　 1. 시작\n");
	printf("　　　　　　　　　　　　　　　　　　 2. 설명\n");
	printf("　　　　　　　　　　　　　　　　　　 3. 종료\n");
	printf("\n원하는 메뉴의 번호를 입력하세요. ");

	do {

		if (menu == -1) {

			system("cls");
			printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("　■■■　　■■■■■　■　　　■　■■■■■　■　　　　　■　　　　　　■■■　\n");
			printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
			printf("■　　　■　　　■　　　■■■■■　■■■■■　■　　　　　■　　　　　■　　　■\n");
			printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
			printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
			printf("　■■■　　　　■　　　■　　　■　■■■■■　■■■■■　■■■■■　　■■■\n");
			printf("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("　　　　　　　　　　　　　　　　　　 1. 시작\n");
			printf("　　　　　　　　　　　　　　　　　　 2. 설명\n");
			printf("　　　　　　　　　　　　　　　　　　 3. 종료\n");
			printf("\n원하는 메뉴의 번호를 입력하세요. ");

			menu = 0;

		}
		
		scanf("%d", &menu);
		
		// 1, 2, 3 외의 숫자가 입력될 경우 재입력
		if (menu != 1 && menu != 2 && menu != 3) {

			system("cls");
			printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("　■■■　　■■■■■　■　　　■　■■■■■　■　　　　　■　　　　　　■■■　\n");
			printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
			printf("■　　　■　　　■　　　■■■■■　■■■■■　■　　　　　■　　　　　■　　　■\n");
			printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
			printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
			printf("　■■■　　　　■　　　■　　　■　■■■■■　■■■■■　■■■■■　　■■■\n");
			printf("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("　　　　　　　　　　　　　　　　　　 1. 시작\n");
			printf("　　　　　　　　　　　　　　　　　　 2. 설명\n");
			printf("　　　　　　　　　　　　　　　　　　 3. 종료\n");
			printf("\n'메뉴의 번호'를 입력하세요! ");
			getchar();

		}

		switch (menu) {

		// 3번 : 종료
		case 3:
			return 2;

		// 2번 : 설명 보기
		case 2:
			system("cls");
			printf("키보드의 방향키(← ↑ → ↓)를 이용하여\n보드판의 커서(■ / □)를 이동시킬 수 있습니다.\n\n엔터(<┘ )나 스페이스(Space)를 입력하면\n커서가 있는 위치에 돌(● / ○)을 놓습니다.\n\n만약 돌을 놓을 수 있는 곳이 없다면 자동으로 턴이 넘겨집니다.\nG키를 누르면 게임을 포기하실 수 있습니다.\n\n이 외의 룰은 보드게임 오델로(리버시)와 같습니다.\n\n시작 메뉴로 돌아가기 <┘");
			
			while (1) {
				switch (getch()) {

				case 13:
				case 32:
					menu = -1;
					break;
		
				}
				if (menu == -1) break;
			}
			break;
		}
	} while (menu != 1); // 1번 : 게임 시작

	return 1;

}