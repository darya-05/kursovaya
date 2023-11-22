//#include <stdio.h>
//#include<locale.h>
//#define SIZE 8
//#define EMPTY 0
//#define FILLED 1
//#define CLOUD_MIN_SIZE 2
//
//int grid[SIZE][SIZE];
//
//// ��������, ����� �� ������ ���� ��������� � ������ �������
//int isPositionValid(int row, int col, int size) {
//    // �������� ��������
//    for (int i = 0; i < size; i++) {
//        if (col + i >= SIZE || grid[row][col + i] != EMPTY) {
//            return 0;
//        }
//    }
//
//    // �������� �����
//    for (int i = 0; i < size; i++) {
//        if (row + i >= SIZE || grid[row + i][col] != EMPTY) {
//            return 0;
//        }
//    }
//
//    // �������� �����
//    if (row + size < SIZE && col + size < SIZE && grid[row + size][col + size] != EMPTY) {
//        return 0;
//    }
//
//    if (row - 1 >= 0 && col + size < SIZE && grid[row - 1][col + size] != EMPTY) {
//        return 0;
//    }
//
//    if (row + size < SIZE && col - 1 >= 0 && grid[row + size][col - 1] != EMPTY) {
//        return 0;
//    }
//
//    if (row - 1 >= 0 && col - 1 >= 0 && grid[row - 1][col - 1] != EMPTY) {
//        return 0;
//    }
//
//    return 1;
//}
//
//// ���������� ������ � ������ �������
//void placeCloud(int row, int col, int size) {
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            grid[row + i][col + j] = FILLED;
//        }
//    }
//}
//
//// ����� ����� �� �����
//void printGrid() {
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            printf("%d ", grid[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    setlocale(LC_CTYPE, "Rus");
//    // ������������� �����
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            grid[i][j] = EMPTY;
//        }
//    }
//
//    // ���� � ���������� ������ �� �����������
//    int row, col;
//    for (int i = 0; i < SIZE / 2; i++) {
//        printf("������� ������ � ������� ��� ������ �������� %d:\n", (i % 2) ? 2 : 4);
//        scanf("%d %d", &row, &col);
//
//        if (isPositionValid(row, col, (i % 2) ? CLOUD_MIN_SIZE : CLOUD_MIN_SIZE + 2)) {
//            placeCloud(row, col, (i % 2) ? CLOUD_MIN_SIZE : CLOUD_MIN_SIZE + 2);
//        }
//        else {
//            printf("������ ������ ���������� � ������ �������.\n");
//            i--;
//        }
//    }
//
//    // ����� ����� �� �����
//    printGrid();
//
//    return 0;
//}
