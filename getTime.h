#include <stdio.h>
#include <Windows.h>
#include <limits.h>

// ���� �ð� �ޱ�
int getTime () {

	int time;

	system("cls");
	printf("���� �ð��� �� ���ΰ���? ");

	do {

		scanf("%d", &time);
		if (time < 1 || time > 2147483) {

			system("cls");
			printf("1 - 2147483�� ���ڸ� �Է��ϼ���! ");

		}
	} while (time < 1 || time > 2147483);

	return time * 1000;

}