/* 将字符串中的空格替换成"%20", 例如当字符串为"We Are Happy", 替换之后字符串为"We%20Are%20Happy" */

#include <stdio.h>

#define KEY         "%20"

static void rel_strncpy(char *src, char *dst, int len)
{
    int i;

    for (i = len; i >= 0; i--) {
        src[i] = dst[i];
    }

    return 0;
}

static void replace_space(char *src, int len)
{
    int i;
    char *p;

    for (i = 0; i < len; i++) {
        if (src[i] == ' ') {
            p = src + i;
            src[i] = '%';
            rel_strncpy(src + i + 3, p + 1, len - i);
            src[i + 1] = '2';
            src[i + 2] = '0';
        }
    }

    return ;
}

int main(int argc, char *argv[])
{
    char test[100] = {"We Are Happy."};

    replace_space(test, 15);
    printf("str: %s\n", test);

    return 0;
}
