/* 请实现一个算法，确定一个字符串的所有字符是否全都不同。这里我们要求不允许使用额外的存储结构。
 * 给定一个string iniString，请返回一个bool值,True代表所有字符全都不同，False代表存在相同的字符。
 * 保证字符串中的字符为ASCII字符。字符串的长度小于等于3000。
 * 测试样例：
 * "aeiou" 返回：True
 * "BarackObama" 返回：False
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static bool check_different_basic(char *str)
{
    int len, i, j;

    len = strlen(str);

    for (i = 0; i < len; i++) {
        for (j = (i + 1); j < len; j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }

    return true;
}

static bool check_diff_high_pri(char *str)
{
#define PER_LONG (sizeof(unsigned long) * 8)
#define MAX      (3000 / PER_LONG)
    unsigned long *bitmap, *p, index, bit;
    int len, i;

    len = strlen(str);
    bitmap = (unsigned long *)malloc(MAX);
    if (bitmap == NULL) {
        return false;
    }
    memset(bitmap, 0, MAX);
    for (i = 0; i < len; i++) {
        index = (str[i] / PER_LONG);
        bit = (str[i] % PER_LONG);
        p = bitmap + index;
#ifdef __DEBUG__
        printf("bitmap: 0x%lx, index: %ld, str: %c, bit: %ld, 0x%lx\n", *p, index, str[i], bit, (1UL << bit));
#endif
        if ((*p & (1UL << bit))) {
            free(bitmap);
            return false;
        }
        *p |= (1UL << bit);
    }
    free(bitmap);

    return true;
}

int main(int argc, char *argv[])
{
    char test[100] = {"qwertyuiop[]asdfghjklzxcvbnm,./1234567890"};
    char test_pri[100] = {"qwertyuiop[]asdfghjkl;'zxcvbnm,./12345678990"};
    bool result;

    result = check_different_basic(test);
    printf("result: %s, %s\n", test, result ? "True":"False");
    result = check_diff_high_pri(test);
    printf("high_pri: %s\n", result ? "True":"False");

    result = check_different_basic(test_pri);
    printf("result: %s, %s\n", test_pri, result ? "True":"False");
    result = check_diff_high_pri(test_pri);
    printf("high_pri: %s\n", result ? "True":"False");


    return 0;
}
