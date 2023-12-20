#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ������� ����� � 2-�� ������� ���������
void transf_sec(double number);

// ������� ����� � 8-�� ������� ���������
void transf_eight(double number);

// ������� ����� � 16-�� ������� ���������
void transf_sixteen(double number);

// ����� �����
//void printNumber(double number);

// ����� ��������
//void printOperations(double number_1, double number_2, double result, char operation);

void printNumberin2(double number);
void printNumberin8(double number);
void printNumberin16(double number);

void second(double number_1, double number_2, double result, char operation);
void eight(double number_1, double number_2, double result, char operation);
void sixteen(double number_1, double number_2, double result, char operation);

// ������� ������� ��� �������� � �������� � ������� ��������� ������ ���������
int main()
{
    // �����������
    setlocale(LC_CTYPE, "rus");

    //�������������
    int cc;
    double number_1, number_2, result;
    char operation;

    // ���� ����� �������������
    printf("������� ������ ����� � 10-�� ������� ���������: ");
    scanf("%lf", &number_1);

    printf("������� ������ ����� � 10-�� ������� ���������: ");
    scanf("%lf", &number_2);

    printf("������� ���� �������� (+, -, *, /): ");
    scanf(" %c", &operation);

    printf("������� ������� ���������, � ������� ������ �������� ����� (2, 8, 16): ");
    scanf("%d", &cc);
   
    // ����� ������������� ��������
    switch (operation)
    {
    case '+':
        printf("\n����� �����:\n");
        result = number_1 + number_2;
        break;
    case '-':
        if (number_1 < number_2)
        {
            printf("����������� ������ �����������, ��������� �������� ����������\n");
            return 1;
        }
        printf("\n�������� �����:\n");
        result = number_1 - number_2;
        break;
    case '*':
        printf("\n������������ �����:\n");
        result = number_1 * number_2;
        break;
    case '/':
        printf("\n������� �����:\n");
        result = number_1 / number_2;
        break;
    default:
        printf("\n����������� ��������\n");
        return -2;
        break;
    }

    // ����� ������� ���������
    if (cc == 2)
    {
        printNumberin2(number_1);
        printNumberin2(number_2);
        second(number_1, number_2, result, operation);
    }
    if (cc == 8)
    {
        printNumberin8(number_1);
        printNumberin8(number_2);
        eight(number_1, number_2, result, operation);
    }
    if (cc == 16) {
        printNumberin16(number_1);
        printNumberin16(number_2);
        sixteen(number_1, number_2, result, operation);
    }
    if (cc != 2 || cc != 8 || cc != 16)
    {
        printf("\n����������� ��\n");
    }
}

// ������� ����� � 2-��� ��
void printNumberin2(double number) {
    printf("\n%lf � �������� �� = ", number);
    transf_sec(number);
    printf("\n");
}

// ������� ����� � 8-�� ��
void printNumberin8(double number) {
    printf("\n%lf � ������������ �� = ", number);
    transf_eight(number);
    printf("\n");
}

// ������� ����� � 16-�� ��
void printNumberin16(double number) {
    printf("\n%lf � ����������������� �� = ", number);
    transf_sixteen(number);
    printf("\n");
}

// ���������� �������� � 2-�� ��
void second(double number_1, double number_2, double result, char operation)
{
    printf("\n10-a�: %lf %c %lf = %lf\n", number_1, operation, number_2, result);

    printf("\n2-a� CC: ");
    transf_sec(number_1);
    printf(" %c ", operation);
    transf_sec(number_2);
    printf(" = ");
    transf_sec(result);
    printf("\n");
}

// ���������� �������� � 8-�� ��
void eight(double number_1, double number_2, double result, char operation)
{
    printf("\n10-a�: %lf %c %lf = %lf\n", number_1, operation, number_2, result);

    printf("\n8-a� CC: ");
    transf_eight(number_1);
    printf(" %c ", operation);
    transf_eight(number_2);
    printf(" = ");
    transf_eight(result);
    printf("\n");
}

//���������� �������� � 16-�� ��
void sixteen(double number_1, double number_2, double result, char operation)
{
    printf("\n10-a�: %lf %c %lf = %lf\n", number_1, operation, number_2, result);

    printf("\n16-�� ��: ");
    transf_sixteen(number_1);
    printf(" %c ", operation);
    transf_sixteen(number_2);
    printf(" = ");
    transf_sixteen(result);
    printf("\n");
}

// ������� ����� � 2-�� ������� ���������
void transf_sec(double number) {
    //  ���������� ������� ��� �������� ��������� ����� � ���������� i ��� ������������ �������
    int binar_number[32], i = 0;

    // ��������� ����� ����� ��������� �����
    int int_zn = (int)number;

    // ��������� ������� ����� ��������� �����
    double drob_zn = number - int_zn;

    // ���� ����� ����� ����� 0, ��������� 0, ����� ����������� �������������� ����� ����� � �������� ����� � ��������� � �������� �������
    if (int_zn == 0)
        printf("0");
    else {
        while (int_zn > 0)
        {   
            binar_number[i] = int_zn % 2;
            int_zn = int_zn / 2;
            i++;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            printf("%d", binar_number[j]);
        }
    }

    // ���������� ����� � ������� ������
    printf(".");

    // ���� ������� ����� = 0.0, ��������� 0, ����� ����������� ��������. �����. �. � 2-�� ����� � ���������
    if (drob_zn == 0.0)
    {
        printf("0");
    }
    else {
        while (drob_zn > 0)
        {
            // ��������� ����. �. �� 2, ����� ����� ����. ����� � 2-�� �������������
            drob_zn *= 2;
            printf("%d", (int)drob_zn);

            // �������� ����� �����
            drob_zn -= (int)drob_zn;
        }
    }
}

// ������� ����� � 8-�� ������� ���������
void transf_eight(double number)
{
    // ������������� ���������� ��� �������� 8-��� ����� � i ��� �������� ���� ��� ��������
    int eight_zn = 0, i = 1;

    // ��������� ����� ����� ��������� �����
    int int_zn = (int)number;

    // ��������� ������� ����� ��������� �����
    double drob_zn = number - int_zn;

    if (int_zn == 0)
    {
        printf("0.");
    }
    else {
        while (int_zn != 0)
        {
            eight_zn += (int_zn % 8) * i;
            int_zn /= 8;
            i *= 10;
        }
        printf("%d.", eight_zn);
    }
    i = 1;

    if (drob_zn == 0.0)
        printf("0");
    else {
        while (drob_zn > 0)
        {
            drob_zn *= 8;
            printf("%d", (int)drob_zn);
            drob_zn -= (int)drob_zn;
            i *= 10;
        }
    }
}

// ������� ����� � 16-�� ������� ���������
void transf_sixteen(double number)
{
    // ���������� ���������� ost ��� ������� � i ��� ������������ ������� � ������� sixteen_zn[20]
    int ost, i = 0;

    // ��������� ����� �����
    int int_zn = (int)number;

    // ���������� ������� ��� �������� 16-��� �����
    char sixteen_zn[20];

     // ��������� ������� ����� ���������� �����
    double drob_zn = number - int_zn;

    if (int_zn == 0)
    {
        printf("0");
    }
    else {
        while (int_zn != 0)
        {
            ost = int_zn % 16;
            if (ost < 10)
            {
                sixteen_zn[i++] = ost + 48;
            }
            else
            {
                sixteen_zn[i++] = ost + 55;
            }
            int_zn /= 16;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            printf("%c", sixteen_zn[j]);
        }
    }
    printf(".");

    if (drob_zn == 0.0)
    {
        printf("0");
    }
    else {
        while (drob_zn > 0)
        {
            drob_zn *= 16;
            ost = (int)drob_zn;
            if (ost < 10)
            {
                printf("%d", ost);
            }
            else
            {
                printf("%c", ost + 55);
            }
            drob_zn -= ost;
        }
    }
}