// ���������� ������������ �����
#include <stdio.h>
#include <locale.h>

// ���������� �������
int Menu();
int Pravila();
int pole(char(*a)[9]);
int play(char(*a)[9], char(*pole1)[9]);
int poleX(char(*a)[9], int x, int y, int clouddlin, int cloudshir);
int resetArray(char(*a)[9]);
int savetofile(const char* filename, char mas[9][9]);
int savetofileProgress(const char* filename, char mas[9][9]);
int loadfromfile(char(*a)[9]);
int checkCloud(char(*a)[9], int x, int y, int dlin, int shir);
int checkOverlap(char(*a)[9], int x, int y, int dlin, int shir);
int proverka(char(*a)[9], char(*pole1)[9]);

int main()
{   setlocale(LC_CTYPE, "Rus");
    int option, play_res; //�������������
    char a[9][9] = {    // ������ ������, ������� � ���������� ����� ����������� ��������
    {'-', '2', '4', '2', '2', '0', '6', '6', '6'},
    {'3', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'3', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'6', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'3', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'3', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'5', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'5', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'0', '-', '-', '-', '-', '-', '-', '-', '-'},
    };
    char pole1[9][9] = {   // ������ � ������ ��������
    {'-', '2', '4', '2', '2', '0', '6', '6', '6'},
    {'3', '-', '-', '-', '-', '-', '1', '1', '1'},
    {'3', '-', '-', '-', '-', '-', '1', '1', '1'},
    {'6', '-', '1', '1', '1', '-', '1', '1', '1'},
    {'3', '-', '1', '1', '1', '-', '-', '-', '-'},
    {'3', '-', '-', '-', '-', '-', '1', '1', '1'},
    {'5', '1', '1', '-', '-', '-', '1', '1', '1'},
    {'5', '1', '1', '-', '-', '-', '1', '1', '1'},
    {'0', '-', '-', '-', '-', '-', '-', '-', '-'},
    };
    do
    {   Menu(); //����� ������ ���� � ���������� ����� �� ����
        scanf("%d", &option);
        getchar();
        switch (option) //�������� switch ��� ������ ����� ����
        {
        case 1:
            Pravila(); //����� ������� � ��������� ����
            break;
        case 2:
            resetArray(a);
            pole(a);
            play_res = play(a, pole1);
            if (play_res == 2) // ����� ������� � ����� �����
            {continue;}
            break;
        case 3:
            loadfromfile(a);
            printf("��� ��������:\n");
            pole(a); // ����� ���������� ����
            play_res = play(a, pole1);
            if (play_res == 2) // ����� ������� � ����� �����
            {continue;}
            break;
        case 4:
            savetofileProgress("progress.txt", a);
            printf("�������� ������� �������");
            break;
        case 5:
            return 0; // ����� �� ����
        default:
            printf("����������� �����\n");
            break;
        }
    } while (option != 5);
    return 0;
}

// ������� ��� ������ ����
int Menu()
{
    printf("\n                                        ***** ���� ������ *****\n");
    printf("                                               - ���� - \n");
    printf(" �������� �����: \n1) ������� ���� \n2) ������ ���� � ������ \n3) ���������� ���� \n4) ���������� ��������� \n5) �����\n ");
    return 1;
}

// ������� ��� ������ ������ ����
int Pravila()
{
    printf("������ � ���������� �������� (��������������) � ����� (����� �����������) ���, ����� ��� �� �������� ���� ����� �� \n���������, �� ������.\n");
    printf("����� �� ����� ����� �������� ���������� ������, ������� ���������. \n����������� ������ �������� � 2 �� 2 ������\n");
    return 1;
}

// ������� � ����� �����
int play(char(*a)[9], char(*pole1)[9])
{
    char itog[9][9]; // ������, � ������� ����� ��������� ����������� ������ pole1 �� �����
    int x, y, shir, dlin;
    savetofile("itog.txt", pole1); // ������ ������������ ������� pole1 � ���� itog.txt
    for (int i = 0; i < 9; i++) //���������� ������ �� ���� �������� 9 �� 9
    {
        int res = 0;
        int filledRows = 0;
        // ���� do-while ��� ����������� ������������ ������� ���������� � ������� ������ �� ��� ���, ���� �� ����� ������� ���������� ������� ��� ����
        do
        {
            printf("\n������� ���������� ������, � ������� ������ ���������� ������, � ������ ������ �� ������ � ������:\n 1. � �� 1 �� 8\n 2. � �� 1 �� 8\n 3. ������ �� 2 �� 8\n 4. ������ �� 2 �� 8\n ������� ���� �� ���� 0, ���� ������ ����� �� ����\n");
            scanf("%d %d %d %d", &x, &y, &dlin, &shir);

            // ������� ��� ���������� ���� ��� ����� ���� �� ������ 0 �������������
            if (x == 0 || y == 0 || dlin == 0 || shir == 0)
            {
                printf("                                        * * ���� ���������! * *\n");
                break;
            }

            if (checkCloud(a, x, y, dlin, shir) == 1 && checkOverlap(a, x, y, dlin, shir) == 1)
            {
                printf("������ ���������.\n");
                //������� ���������� ������
                poleX(a, x, y, dlin, shir);
            }

            // ���������, ��������� �� ��� ������
            for (int i = 0; i < 9; i++)
            {
                int rowFilled = 0;
                for (int j = 0; j < 9; j++)
                {
                    if (a[i][j] == '1')
                    {
                        rowFilled++;
                    }
                }

                if ((rowFilled == 3 && (i == 1 || i == 2 || i == 4 || i == 5)) || (rowFilled == 5 && (i == 6 || i == 7)) || (rowFilled == 6 && i == 3))
                {
                    filledRows++;
                }
            }

        } while (res != 1 && filledRows < 12);


        int result = proverka(a, itog);
        if (result == 1)
        {
            printf("�� ��������!\n");

            break;
        }
        else
        {
            printf("�� ��������� :(\n");
            printf("���������� �����!\n");
            break;
        }
    }
    return 2;
}

// ������� ��� ������ ������������� ������� pole1 � ����
int savetofile(const char* filename, char mas[9][9])
{
    FILE* taskFile = fopen("itog.txt", "w");
    if (taskFile == NULL)
    {
        printf("������ ��� �������� �����\n");
        return 0;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            fprintf(taskFile, " %c", mas[i][j]);
        }
        fprintf(taskFile, "\n");
    }
    fclose(taskFile);
    return 1;
}

// ������� ��� ������ ������������ ������� �� ����� � ��������� ��� � ������������
int proverka(char(*a)[9], char(*pole1)[9])
{
    // ������ �� �����
    FILE* taskFile = fopen("itog.txt", "r");
    if (taskFile == NULL)
    {
        printf("������ ��� �������� �����\n");
        return 0;
    }

    char itog[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            fscanf(taskFile, " %c", &itog[i][j]);
        }
    }

    fclose(taskFile);

    // ��������� ���� ��������
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if (a[i][j] != itog[i][j])
            {
                return 0; // ������� ������
            }
        }
    }
    return 1; // ������� ����������

}

// ������� �������� ������� � ��������� ������
int checkCloud(char(*a)[9], int x, int y, int dlin, int shir) {
    if (shir < 2 || dlin < 2 || shir > 8 || dlin > 8 || x < 1 || x > 8 || y < 1 || y > 8) {
        printf("������ �� ����� ���� ������, ��� 2 �� 2, ������, ��� 8 �� 8 ��� ����������� ��� ����\n");
        return 0; // ������ ���������������
    }
    return 1; // ������ �������������
}

// ������� �������� ����������� � ������� ��������
int checkOverlap(char(*a)[9], int x, int y, int dlin, int shir) {
    int isOverlap = 0;
    for (int m = x - 1; m <= x + shir; m++) {
        for (int n = y - 1; n <= y + dlin; n++) {
            if (a[m][n] == '1') {
                isOverlap = 1;
                break;
            }
        }
        if (isOverlap) {
            printf("������ �� ����� ���� ��������� � ������ �������. ���������� ��� ���.\n");
            return 0;
        }
    }
    return 1; // ����������� ���
}

// ������� ��� ������ ���������� ���� (������ � � ���������)
int pole(char(*a)[9])
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
    return 1;
}

// ���������� ���� ������� �� �
int poleX(char(*a)[9], int x, int y, int dlin, int shir)
{
    for (int i = x; i < x + shir; i++)
    {
        for (int j = y; j < y + dlin; j++)
        {
            a[i][j] = '1';
        }
    }
    printf("___________________________\n");
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            printf("|_%c", a[i][j]);
        }
        printf("|\n");
    }
    return 1;
}

// ����������� ���� � ���������� ����
int resetArray(char(*a)[9]) {
    char initialArray[9][9] = {
        {'-', '2', '4', '2', '2', '0', '6', '6', '6'},
        {'3', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'3', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'6', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'3', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'3', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'5', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'5', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'0', '-', '-', '-', '-', '-', '-', '-', '-'}
    };

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            a[i][j] = initialArray[i][j];
        }
    }
    return 1;
}

// ������� ��� ������ ��������� ��������� � ����
int savetofileProgress(const char* filename, char mas[9][9])
{
    FILE* taskFile = fopen("progress.txt", "w");
    if (taskFile == NULL)
    {
        printf("������ ��� �������� �����\n");
        return 0;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            fprintf(taskFile, " %c", mas[i][j]);
        }
        fprintf(taskFile, "\n");
    }
    fclose(taskFile);
    return 3;
}

// ������� ��� ������ �������� ��������� �� �����
int loadfromfile(char(*a)[9])
{
    FILE* taskFile = fopen("progress.txt", "r");
    if (taskFile == NULL)
    {
        printf("������ ��� �������� �����\n");
        return 0;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            fscanf(taskFile, " %c", &a[i][j]);
        }
    }
    fclose(taskFile);
    return 1;
}

