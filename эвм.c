#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Перевод числа в 2-ую систему счисления
void transf_sec(double number);

// Перевод числа в 8-ую систему счисления
void transf_eight(double number);

// Перевод числа в 16-ую систему счисления
void transf_sixteen(double number);

// Вывод чисел
//void printNumber(double number);

// Вывод операций
//void printOperations(double number_1, double number_2, double result, char operation);

void printNumberin2(double number);
void printNumberin8(double number);
void printNumberin16(double number);

void second(double number_1, double number_2, double result, char operation);
void eight(double number_1, double number_2, double result, char operation);
void sixteen(double number_1, double number_2, double result, char operation);

// Главная функция для перевода и операций с числами различных систем счисления
int main()
{
    // Локализация
    setlocale(LC_CTYPE, "rus");

    //Инициализация
    int cc;
    double number_1, number_2, result;
    char operation;

    // Ввод чисел пользователем
    printf("Введите первое число в 10-ой системе счисления: ");
    scanf("%lf", &number_1);

    printf("Введите второе число в 10-ой системе счисления: ");
    scanf("%lf", &number_2);

    printf("Введите знак операции (+, -, *, /): ");
    scanf(" %c", &operation);

    printf("Введите систему счисления, в которой хотите получить ответ (2, 8, 16): ");
    scanf("%d", &cc);
   
    // Выбор пользователем операции
    switch (operation)
    {
    case '+':
        printf("\nСумма чисел:\n");
        result = number_1 + number_2;
        break;
    case '-':
        if (number_1 < number_2)
        {
            printf("Уменьшаемое меньше вычитаемого, получение разности невозможно\n");
            return 1;
        }
        printf("\nРазность чисел:\n");
        result = number_1 - number_2;
        break;
    case '*':
        printf("\nПроизведение чисел:\n");
        result = number_1 * number_2;
        break;
    case '/':
        printf("\nЧастное чисел:\n");
        result = number_1 / number_2;
        break;
    default:
        printf("\nНеизвестная операция\n");
        return -2;
        break;
    }

    // Выбор системы счисления
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
        printf("\nНеизвестная СС\n");
    }
}

// Перевод числа в 2-ную СС
void printNumberin2(double number) {
    printf("\n%lf в двоичной СС = ", number);
    transf_sec(number);
    printf("\n");
}

// Перевод числа в 8-ую СС
void printNumberin8(double number) {
    printf("\n%lf в восьмеричной СС = ", number);
    transf_eight(number);
    printf("\n");
}

// Перевод числа в 16-ую СС
void printNumberin16(double number) {
    printf("\n%lf в шестнадцатеричной СС = ", number);
    transf_sixteen(number);
    printf("\n");
}

// Выполнение операции в 2-ой СС
void second(double number_1, double number_2, double result, char operation)
{
    printf("\n10-aя: %lf %c %lf = %lf\n", number_1, operation, number_2, result);

    printf("\n2-aя CC: ");
    transf_sec(number_1);
    printf(" %c ", operation);
    transf_sec(number_2);
    printf(" = ");
    transf_sec(result);
    printf("\n");
}

// Выполнение операции в 8-ой СС
void eight(double number_1, double number_2, double result, char operation)
{
    printf("\n10-aя: %lf %c %lf = %lf\n", number_1, operation, number_2, result);

    printf("\n8-aя CC: ");
    transf_eight(number_1);
    printf(" %c ", operation);
    transf_eight(number_2);
    printf(" = ");
    transf_eight(result);
    printf("\n");
}

//Выполнение операции в 16-ой СС
void sixteen(double number_1, double number_2, double result, char operation)
{
    printf("\n10-aя: %lf %c %lf = %lf\n", number_1, operation, number_2, result);

    printf("\n16-ая СС: ");
    transf_sixteen(number_1);
    printf(" %c ", operation);
    transf_sixteen(number_2);
    printf(" = ");
    transf_sixteen(result);
    printf("\n");
}

// Перевод числа в 2-ую систему счисления
void transf_sec(double number) {
    //  Объявление массива для хранения двоичного числа и переменной i для отслеживания индекса
    int binar_number[32], i = 0;

    // Получение целой части введённого числа
    int int_zn = (int)number;

    // Получение дробной части введённого числа
    double drob_zn = number - int_zn;

    // Если целая часть равна 0, выводится 0, иначе выполняется преобразование целой части в двоичное число и выводится в обратном порядке
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

    // Разделение целой и дробной частей
    printf(".");

    // Если дробная часть = 0.0, выводится 0, иначе выполняется преобраз. дробн. ч. в 2-ое число и выводится
    if (drob_zn == 0.0)
    {
        printf("0");
    }
    else {
        while (drob_zn > 0)
        {
            // Умножение дроб. ч. на 2, чтобы найти след. цифру в 2-ом представлении
            drob_zn *= 2;
            printf("%d", (int)drob_zn);

            // Удаление целой части
            drob_zn -= (int)drob_zn;
        }
    }
}

// Перевод числа в 8-ую систему счисления
void transf_eight(double number)
{
    // Инициализация переменных для хранения 8-ого числа и i для создания мест для разрядов
    int eight_zn = 0, i = 1;

    // Получение целой части введённого числа
    int int_zn = (int)number;

    // Получение дробной части введённого числа
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

// Перевод числа в 16-ую систему счисления
void transf_sixteen(double number)
{
    // Объявление переменных ost для остатка и i для отслеживания индекса в массиве sixteen_zn[20]
    int ost, i = 0;

    // Получение целой части
    int int_zn = (int)number;

    // Объявление массива для хранения 16-ого числа
    char sixteen_zn[20];

     // Получение дробной части введенного числа
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