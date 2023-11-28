#include <stdio.h>
#include <locale.h>

#define ROWS 8
#define COLS 8
struct Cloud {
    int x;
    int y;
    int width;
    int height;
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
void poleX(int x, int y, int cloudWidth, int cloudHeight);

int main()
{
    setlocale(LC_CTYPE, "Rus");

    int option;
    int x, y, width, height;
    int n = 8;
    struct Cloud clouds[4] = { {3, 2, 3, 2}, {6, 1, 2, 2}, {1, 6, 3, 3}, {5, 6, 3, 3} };
    int cloudCoordinates[4][4] = { {3, 2, 3, 2}, {6, 1, 2, 2}, {1, 6, 3, 3}, {5, 6, 3, 3} };

    do
    {
        printf("\nИгра Облака\n");
        printf("Меню:\n");
        printf("Выберите опцию\n 1) Правила игры\n 2) Начать игру\n 3) Выход\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            printf("Задача – расставить “облака” (прямоугольники) в “небе” (сетке головоломки) так, чтобы они не касались друг друга ни сторонами, ни углами.\n");
            printf("Числа по краям сетки означают количество клеток, занятых “облаками”. Минимальный размер “облака” – 2 на 2 клетки\n");
            break;
        case 2:
            pole();
            for (int i = 0; i < 4; i++) {
                int cloudIndex = -1;
                // Запрос координат у пользователя до тех пор, пока он не введет все необходимые значения
                do {
                    printf("Введите координаты клетки, в которую хотите установить облако, и размер облака по ширине и высоте:\n");
                    scanf("%d %d %d %d", &x, &y, &width, &height);
                    for (int j = 0; j < 4; j++) {
                        if ((x == clouds[j].x && y == clouds[j].y && width == clouds[j].width && height == clouds[j].height) ||
                            (x == clouds[j].y && y == clouds[j].x && width == clouds[j].height && height == clouds[j].width) ||
                            (x == clouds[j].x && y == clouds[j].y && width == clouds[j].height && height == clouds[j].width) ||
                            (x == clouds[j].y && y == clouds[j].x && width == clouds[j].width && height == clouds[j].height)) {
                            cloudIndex = j;
                            break;
                        }
                    }
                } while (cloudIndex == -1);

                poleX(x, y, width, height);
                pole();  // Печатаем поле после установки облака
                printf("Верно! Облако добавлено.\n");
            }
            printf("                                    ТЫ ПОБЕДИЛ!             \n");
            return 0;


            // вывод результата
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    printf("%c ", a[i][j]);
                }
                printf("\n");

            }
            break;
        case 3:
            return 0;
        default:
            printf("Неизвестная опция\n");
            break;
        }
    } while (option != 3);

    return 0;
}

// Остальной код остаётся без изменений

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

void poleX(int x, int y, int cloudWidth, int cloudHeight)
{
    for (int i = x; i < x + cloudHeight; i++)
    {
        for (int j = y; j < y + cloudWidth; j++)
        {
            a[i][j] = 'Х';
        }
    }
}

