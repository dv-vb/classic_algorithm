/* ��ʵ��һ���㷨��ȷ��һ���ַ����������ַ��Ƿ�ȫ����ͬ����������Ҫ������ʹ�ö���Ĵ洢�ṹ��
 * ����һ��string iniString���뷵��һ��boolֵ,True���������ַ�ȫ����ͬ��False���������ͬ���ַ���
 * ��֤�ַ����е��ַ�ΪASCII�ַ����ַ����ĳ���С�ڵ���3000��
 * ����������
 * "aeiou" ���أ�True
 * "BarackObama" ���أ�False
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

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

int main(int argc, char *argv[])
{
    char test[100] = {"qwertyuiop[]asdfghjklzxcvbnm,./1234567890"};
    bool result;

    result = check_different_basic(test);
    printf("result: %s, %s\n", test, result?"True":"False");

    return 0;
}
