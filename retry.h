#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

// 재시도 여부 확인
int retry() {

	int entered = 0; // 결과 확인
	char askRetry = NULL; // 확인 여부

	printf(" 결과 확인 <┘");
	
	// 엔터 & 스페이스 : 확인
	while (1) {
		switch (getch()) {

		case 13:
		case 32:
			entered = 1;
			break;

		}
		if (entered) break;
	}

	// Y : 재시작, N : 종료
	while (1) {

		system("cls");
		
		if (askRetry == NULL) printf("다시 하시겠습니까? ");
		else printf("'Y' 또는 'N'으로 대답하세요! ");

		scanf("%c", &askRetry);

		if (askRetry == 'y' || askRetry == 'Y') return 2;
		else if (askRetry == 'n' || askRetry == 'N') return 1;

	}
}