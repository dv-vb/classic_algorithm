/* ��ά���飬ÿ�д����ҵ�����ÿ�д��ϵ��µ���������һ���������飬�ҳ��������Ƿ��ж�Ӧ���� */

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
