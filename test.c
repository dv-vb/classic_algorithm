/* 圆桌会议，总共有n人，每次数到M， 对应人员出去，继续数M, 求最后一个人 */

#include <stdio.h>

#define TOTAL_NUM           30
#define COUNT               6

static void print_status(char *arr)
{
    int i;

    for (i = 0; i < TOTAL_NUM; i++) {
        printf("%2d", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    char array[TOTAL_NUM] = {0};
    int i, n, pos;

    for (i = 0; i < TOTAL_NUM; i++) {
        array[i] = 1;
    }
    n = TOTAL_NUM;
    i = pos = 0;
    while (n--) {
        i = 1;
        for (;;) {
            if (array[pos] == 1) {
                i++;
            }
            pos++;
            if (pos >= TOTAL_NUM) {
                pos = 0;
            }
            if (i == COUNT && (array[pos] == 1)) {
                break;
            }
        }
        array[pos] = 0;
        pos++;
        print_status(array);
    }

    printf("index: %d\n", pos);

}
