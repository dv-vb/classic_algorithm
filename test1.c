/* 二维数组，每行从左到右递增，每列从上到下递增，输入一个数与数组，找出数组中是否有对应数。 */

#include <stdio.h>

int find(int num, int *array, int rows, int cols)
{
    int row, col = 0, pos;

    row = rows - 1;
    /*
     * 从最后一行第一列开始找，如果这个数比当前位置的大，意味着该数在当前列之后，所以列++
     * 如果当前位置大于这个数，意味着该数在当前行之上，所以行--
     */
    while (row >= 0 && col < cols) {
        pos = ((row) * (cols)) + col;
        printf("%d ", array[pos]);
        if (array[pos] == num) {
            return 0;
        } else if (array[pos] < num) {
            ++col;
        } else {
            --row;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int array[10][7] = {0};
    int i, j;
    int result;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 7; j++) {
            array[i][j] = i*j + i+j;
            printf("%3d ", i*j + i+j);
        }
        printf("\n");
    }

    result = find(41, array, 10, 7);
    printf("result: %d\n", result);

    return 0;
}
