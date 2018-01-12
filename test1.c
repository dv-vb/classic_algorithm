/* ��ά���飬ÿ�д����ҵ�����ÿ�д��ϵ��µ���������һ���������飬�ҳ��������Ƿ��ж�Ӧ���� */

#include <stdio.h>

int find(int num, int *array, int rows, int cols)
{
    int row, col = 0, pos;

    row = rows - 1;
    /*
     * �����һ�е�һ�п�ʼ�ң����������ȵ�ǰλ�õĴ���ζ�Ÿ����ڵ�ǰ��֮��������++
     * �����ǰλ�ô������������ζ�Ÿ����ڵ�ǰ��֮�ϣ�������--
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
