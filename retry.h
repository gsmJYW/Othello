#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

// ��õ� ���� Ȯ��
int retry() {

	int entered = 0; // ��� Ȯ��
	char askRetry = NULL; // Ȯ�� ����

	printf(" ��� Ȯ�� <��");
	
	// ���� & �����̽� : Ȯ��
	while (1) {
		switch (getch()) {

		case 13:
		case 32:
			entered = 1;
			break;

		}
		if (entered) break;
	}

	// Y : �����, N : ����
	while (1) {

		system("cls");
		
		if (askRetry == NULL) printf("�ٽ� �Ͻðڽ��ϱ�? ");
		else printf("'Y' �Ǵ� 'N'���� ����ϼ���! ");

		scanf("%c", &askRetry);

		if (askRetry == 'y' || askRetry == 'Y') return 2;
		else if (askRetry == 'n' || askRetry == 'N') return 1;

	}
}