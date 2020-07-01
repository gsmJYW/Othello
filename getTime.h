#include <stdio.h>
#include <Windows.h>
#include <limits.h>

// 제한 시간 받기
int getTime () {

	int time;

	system("cls");
	printf("제한 시간은 몇 초인가요? ");

	do {

		scanf("%d", &time);
		if (time < 1 || time > 2147483) {

			system("cls");
			printf("1 - 2147483의 숫자만 입력하세요! ");

		}
	} while (time < 1 || time > 2147483);

	return time * 1000;

}