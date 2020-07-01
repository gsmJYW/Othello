#include <stdio.h>
#include <string.h>
#include <Windows.h>

// ID 입력 받기
void getID(char whiteID[], char blackID[]) {

	system("cls");
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
	printf("　■■■　　■■■■■　■　　　■　■■■■■　■　　　　　■　　　　　　■■■　\n");
	printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
	printf("■　　　■　　　■　　　■■■■■　■■■■■　■　　　　　■　　　　　■　　　■\n");
	printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
	printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
	printf("　■■■　　　　■　　　■　　　■　■■■■■　■■■■■　■■■■■　　■■■\n");
	printf("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
	printf("　　　　　　　　　　　　   최대 255바이트까지 입력 가능\n\n\n");
	getchar();
	
	printf("백 : ");
	gets(whiteID);
	printf("흑 : ");
	gets(blackID);

	// 같은 ID가 입력될 경우 재입력
	do {
		if (!strcmp(whiteID, blackID)) {

			system("cls");
			printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("　■■■　　■■■■■　■　　　■　■■■■■　■　　　　　■　　　　　　■■■　\n");
			printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
			printf("■　　　■　　　■　　　■■■■■　■■■■■　■　　　　　■　　　　　■　　　■\n");
			printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
			printf("■　　　■　　　■　　　■　　　■　■　　　　　■　　　　　■　　　　　■　　　■\n");
			printf("　■■■　　　　■　　　■　　　■　■■■■■　■■■■■　■■■■■　　■■■\n");
			printf("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("　　　　　　　　　　　　　　 ID는 같을 수 없습니다!\n\n\n");
			printf("백 ID : ");
			gets(whiteID);
			printf("흑 ID : ");
			gets(blackID);

		}
	} while (!strcmp(whiteID, blackID));

	return;

}