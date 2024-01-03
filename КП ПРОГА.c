// подключаем заголовочные файлы
#include <stdio.h>
#include <locale.h>

// Объявление функций
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
    int option, play_res; //Инициализация
    char a[9][9] = {    // Пустой массив, который в дальнейшем будет заполняться облаками
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
    char pole1[9][9] = {   // массив с верным решением
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
    {   Menu(); //Вызов фунции меню и считывание опции из меню
        scanf("%d", &option);
        getchar();
        switch (option) //Оператор switch для выбора опции меню
        {
        case 1:
            Pravila(); //Вызов функции с правилами игры
            break;
        case 2:
            resetArray(a);
            pole(a);
            play_res = play(a, pole1);
            if (play_res == 2) // Вызов функции с самой игрой
            {continue;}
            break;
        case 3:
            loadfromfile(a);
            printf("Ваш прогресс:\n");
            pole(a); // Вывод начального поля
            play_res = play(a, pole1);
            if (play_res == 2) // Вызов функции с самой игрой
            {continue;}
            break;
        case 4:
            savetofileProgress("progress.txt", a);
            printf("Прогресс успешно сохранён");
            break;
        case 5:
            return 0; // Выход из игры
        default:
            printf("Неизвестная опция\n");
            break;
        }
    } while (option != 5);
    return 0;
}

// Функция для вывода меню
int Menu()
{
    printf("\n                                        ***** Игра Облака *****\n");
    printf("                                               - Меню - \n");
    printf(" Выберите опцию: \n1) Правила игры \n2) Начать игру с начала \n3) Продолжить игру \n4) Сохранение прогресса \n5) Выход\n ");
    return 1;
}

// Функция для вывода правил игры
int Pravila()
{
    printf("Задача – расставить “облака” (прямоугольники) в “небе” (сетке головоломки) так, чтобы они не касались друг друга ни \nсторонами, ни углами.\n");
    printf("Числа по краям сетки означают количество клеток, занятых “облаками”. \nМинимальный размер “облака” – 2 на 2 клетки\n");
    return 1;
}

// Функция с самой игрой
int play(char(*a)[9], char(*pole1)[9])
{
    char itog[9][9]; // массив, в который будем считывать константный массив pole1 из файла
    int x, y, shir, dlin;
    savetofile("itog.txt", pole1); // Запись константного массива pole1 в файл itog.txt
    for (int i = 0; i < 9; i++) //Добавление облака на поле размером 9 на 9
    {
        int res = 0;
        int filledRows = 0;
        // Цикл do-while для возможности пользователя вводить координаты и размеры облака до тех пор, пока не будет найдена подходящая позиция для него
        do
        {
            printf("\nВведите координаты клетки, в которую хотите установить облако, и размер облака по ширине и высоте:\n 1. У от 1 до 8\n 2. Х от 1 до 8\n 3. Ширину от 2 до 8\n 4. Высоту от 2 до 8\n Введите хотя бы один 0, если хотите выйти из игры\n");
            scanf("%d %d %d %d", &x, &y, &dlin, &shir);

            // Условие для завершения игры при вводе хотя бы одного 0 пользователем
            if (x == 0 || y == 0 || dlin == 0 || shir == 0)
            {
                printf("                                        * * Игра Завершена! * *\n");
                break;
            }

            if (checkCloud(a, x, y, dlin, shir) == 1 && checkOverlap(a, x, y, dlin, shir) == 1)
            {
                printf("Облако добавлено.\n");
                //Функция добавления облака
                poleX(a, x, y, dlin, shir);
            }

            // Проверяем, заполнены ли все строки
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
            printf("Вы выиграли!\n");

            break;
        }
        else
        {
            printf("Вы проиграли :(\n");
            printf("Попробуйте снова!\n");
            break;
        }
    }
    return 2;
}

// Функция для записи константьного массива pole1 в файл
int savetofile(const char* filename, char mas[9][9])
{
    FILE* taskFile = fopen("itog.txt", "w");
    if (taskFile == NULL)
    {
        printf("Ошибка при открытии файла\n");
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

// Функция для чтения константного массива из файла и сравнения его с получившимся
int proverka(char(*a)[9], char(*pole1)[9])
{
    // Чтение из файла
    FILE* taskFile = fopen("itog.txt", "r");
    if (taskFile == NULL)
    {
        printf("Ошибка при открытии файла\n");
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

    // сравнение двух массивов
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if (a[i][j] != itog[i][j])
            {
                return 0; // массивы разные
            }
        }
    }
    return 1; // массивы одинаковые

}

// Функция проверки размера и положения облака
int checkCloud(char(*a)[9], int x, int y, int dlin, int shir) {
    if (shir < 2 || dlin < 2 || shir > 8 || dlin > 8 || x < 1 || x > 8 || y < 1 || y > 8) {
        printf("Облако не может быть меньше, чем 2 на 2, больше, чем 8 на 8 или расположено вне поля\n");
        return 0; // Облако недействительно
    }
    return 1; // Облако действительно
}

// Функция проверки пересечения с другими облаками
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
            printf("Облако не может быть размещено в данной позиции. Попробуйте еще раз.\n");
            return 0;
        }
    }
    return 1; // Пересечения нет
}

// Функция для вывода начального поля (массив а с границами)
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

// Заполнение поля облаком из Х
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

// Возвращение поля к начальному виду
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

// Функция для записи игорового прогресса в файл
int savetofileProgress(const char* filename, char mas[9][9])
{
    FILE* taskFile = fopen("progress.txt", "w");
    if (taskFile == NULL)
    {
        printf("Ошибка при открытии файла\n");
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

// Функция для чтения игрового прогресса из файла
int loadfromfile(char(*a)[9])
{
    FILE* taskFile = fopen("progress.txt", "r");
    if (taskFile == NULL)
    {
        printf("Ошибка при открытии файла\n");
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

