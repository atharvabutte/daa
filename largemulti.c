#include <stdio.h>
#include <string.h>
#include <conio.h>

int iseven(int num) {
    return (num % 2 == 0);
}

int p10(int num) {
    int res = 1;
    int i;
    for (i = 1; i <= num; i++)
        res *= 10;
    return res;
}

int digit(char *str, int start, int end) {
    int num = 0;
    int i;
    for (i = start; i < end; i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

void pad(char *str, int pad, int len) {
    memmove(str + pad, str, len + 1);
    memset(str, '0', pad);
}

void set(char *x, char *y) {
    int xl = strlen(x);
    int yl = strlen(y);
    int diff = 0;
    
    if (xl == yl) {
        if (!iseven(xl)) {
            pad(x, 1, xl);
            pad(y, 1, yl);
        }
    } else if (xl > yl) {
        if (!iseven(xl)) {
            pad(x, 1, xl);
            diff = 1;
        }
        diff += xl - yl;
        pad(y, diff, yl);
    } else {
        if (!iseven(yl)) {
            pad(y, 1, yl);
            diff = 1;
        }
        diff += yl - xl;
        pad(x, diff, xl);
    }
}

int main() {
    char x[100], y[100];
    int xlen, ylen, xh, xl, yh, yl, s1, s2, s3, s4, res;

    clrscr();
    
    printf("Enter first number: ");
    scanf("%s", x);
    printf("Enter second number: ");
    scanf("%s", y);
    
    set(x, y);
    
    xlen = strlen(x);
    ylen = strlen(y);
    
    xh = digit(x, 0, xlen / 2);
    xl = digit(x, xlen / 2, xlen);
    yh = digit(y, 0, ylen / 2);
    yl = digit(y, ylen / 2, ylen);
    
    s1 = xh * yh;
    s2 = xl * yl;
    s3 = (xh + xl) * (yh + yl);
    s4 = s3 - s2 - s1;
    
    res = s1 * p10(xlen) + s4 * p10(xlen / 2) + s2;
    
    printf("\nResult: %d", res);
    
    getch();
    return 0;
}
