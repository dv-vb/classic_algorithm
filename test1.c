/* 二维数组，每行从左到右递增，每列从上到下递增，输入一个数与数组，找出数组中是否有对应数。 */

#include <stdio.h>



int main(int argc, char const *argv[])
{
    int array[10][7] = {0};
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 7; j++) {
            array[i][j] = i+j;
        }
    }

    printf("row num: %p, %p, %ld\n", &array[0][1], &array[1][1], (&array[1][1]- &array[0][1]));

    return 0;
}
