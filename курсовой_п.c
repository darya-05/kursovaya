#include <stdio.h>
#include <locale.h>
#define ROWS 8
#define COLS 8
struct Cloud {
	int x;
	int y;
	int dlin;
	int shir;
};
char a[9][9] = {
{' ', '2', '4', '2', '2', '0', '6', '6', '6'},
{'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
{'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
{'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
{'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
{'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
{'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
{'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
{'0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};

void pole();
void poleX(int x, int y, int clouddlin, int cloudshir);
int proverka(char a[9][9], char itog[9][9]) {
	int n = 2;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (a[i][j] != itog[i][j]) {
				return 0; // ������� ������
			}
		}
	}
	return 1; // ������� ����������
}
int main()
{
	setlocale(LC_CTYPE, "Rus");
	int option;
	int x, y, dlin, shir;
	int n = 8;
	struct Cloud clouds[4] = { {3, 2, 3, 2}, {6, 1, 2, 2}, {1, 6, 3, 3}, {5, 6, 3, 3} };
	int cloudCoordinates[4][4] = { {3, 2, 3, 2}, {6, 1, 2, 2}, {1, 6, 3, 3}, {5, 6, 3, 3} };
	do
	{
		char itog[9][9];
		char pole1[9][9] = {
        {' ', '2', '4', '2', '2', '0', '6', '6', '6'},
		{'3', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X'},
		{'3', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X'},
		{'6', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X'},
		{'3', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' '},
		{'3', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X'},
		{'5', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X'},
		{'5', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X'},
		{'0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		};
		FILE* taskFile = fopen("itog.txt", "w");
		if (taskFile == 0)
		{
			printf("������ ��� �������� �����\n");
			return 0;
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fprintf(taskFile, "%d", pole1[i][j]);
			}
			fprintf(taskFile, "\n");
		}

		fclose(taskFile);

		printf("\n                                        ***** ���� ������ *****\n");
		printf("    - ���� - \n");
		printf(" �������� �����: \n1) ������� ���� \n2) ������ ���� \n3) �����\n");
		scanf("%d", &option);
		getchar();
		switch (option)
		{
		case 1:
			printf("������ � ���������� �������� (��������������) � ����� (����� �����������) ���, ����� ��� �� �������� ���� ����� �� ���������, �� ������.\n");
			printf("����� �� ����� ����� �������� ���������� ������, ������� ���������. ����������� ������ �������� � 2 �� 2 ������\n");
			break;
		case 2:
			pole();
			for (int i = 0; i < 4; i++) {
				int cloudIndex = -1;
				do {
					printf("\n������� ���������� ������, � ������� ������ ���������� ������, � ������ ������ �� ������ � ������:\n 1. � �� 1 �� 8\n 2. � �� 1 �� 8\n 3. ������ �� 2 �� 8\n 4. ������ �� 2 �� 8\n ������� ���� �� ���� 0, ���� ������ ����� �� ����\n");
					scanf("%d %d %d %d", &x, &y, &dlin, &shir);
					if (x == 0 || y == 0 || dlin == 0 || shir == 0) {
						printf("���� ���������\n");
						return 0;
					}
					for (int j = 0; j < 4; j++) {
						int invalidPosition = 0;
						for (int i = x; i < x + shir; i++) {
							for (int j = y; j < y + dlin; j++)
							{
								if (a[i][j] == '�') {
									invalidPosition = 1;
									break;
								}
							}
							if (invalidPosition) {
								break;
							}
						}

						if (invalidPosition)
						{
							printf("������ �� ����� ���� ��������� � ������ �������. ���������� ��� ���.\n");
						}
						if (shir < 2 || dlin < 2)
						{
							printf("������ �� ����� ���� ������, ��� 2 �� 2\n");
						}
						if ((x == clouds[j].x && y == clouds[j].y && dlin == clouds[j].dlin && shir == clouds[j].shir) ||
							(x == clouds[j].y && y == clouds[j].x && dlin == clouds[j].shir && shir == clouds[j].dlin) ||
							(x == clouds[j].x && y == clouds[j].y && dlin == clouds[j].shir && shir == clouds[j].dlin) ||
							(x == clouds[j].y && y == clouds[j].x && dlin == clouds[j].dlin && shir == clouds[j].shir))
						{
							cloudIndex = j;
							break;
						}
					}
				} while (cloudIndex == -1);
				poleX(x, y, dlin, shir);
				pole(); // �������� ���� ����� ��������� ������
				printf("�����! ������ ���������.\n");
			}

			int result = proverka(pole, itog);
			if (result == 0) {
				printf("������� ���������\n");
				printf("�� ��������!\n");
			}
			else {
				printf("������� �� ���������\n");
			}

			return 0;
			// ����� ����������
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					printf("%c ", a[i][j]);
				}
				printf("\n");
			}

			break;
		case 3:
			return 0;
		default:
			printf("����������� �����\n");
			break;
		}
	} while (option != 3);
	return 0;
}
void pole()
{
	int n = 8;
	printf("___________________________\n");
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			printf("|_%c", a[i][j]);
		}
		printf("|\n");
	}
}
void poleX(int x, int y, int clouddlin, int cloudshir)
{
	for (int i = x; i < x + cloudshir; i++)
	{
		for (int j = y; j < y + clouddlin; j++)
		{
			a[i][j] = '�';
		}
	}
}