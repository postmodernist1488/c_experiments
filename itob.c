/* excersizes in string-number conversion and recursive functions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(t, x, y) { t temp = x; x = y; y = temp; }

/*reverse int array s */
void reverse(char s[]) {
    char temp;
    for (int i=0, j=strlen(s) - 1; i < j; i++, j--)
        temp = s[i], s[i] = s[j], s[j] = temp;
}

/* recursive version of reverse */
void reverse_re(char s[]) 
{
    static int i;
    int len = strlen(s);
    char temp;
    if (i < len / 2) {
        temp = s[i], s[i] = s[len - i - 1], s[len - i - 1] = temp;
        i++;
        reverse_re(s);
    }
    else i = 0;
}

/* itob: convert integer n to a string representation of n in base b */
void itob(int n, char s[], int b) {
    //2 <= b <= 36 (10 digits and 26 letters of the English alphabet)
    if (!(2 <= b && b <= 36)) {
        fprintf(stderr, "Error: `b` is supposed to be a base between 2 and 36");
        exit(1);
    }

    int i=0, sign=n, digit;
    do {
        digit = abs(n % b);
        s[i++] = (digit < 10) ? digit + '0': digit + - 10 + 'A';
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
/* itoa_field: convert int to string adding padding to fit minimum width field */
void itoa_field(int n, char s[], int field) {
    int i=0, sign=n;
    do {
        s[i++] = n % 10 + '0';
        field--;
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
        field--;
    }
    //add padding if field > 0
    for (int k=0; k < field; k++)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

/* recursive implementation of itoa - convert integer to string */
void itoa_re(int n, char s[]) {
    static int i;

    if (n / 10) {
        itoa_re(n / 10, s);
    }
    else {
        i = 0;
        if (n < 0) {
            s[i++] = '-';
        }
    }

    s[i++] = (abs(n % 10) + '0');
    s[i] = '\0';
}

void strncpy_ptr(char *s, char *t, int n) {
    while (n-- && (*s++ = *t++));
}

void strcat_ptr(char *s, char *t) {
    while (*s) s++;
    while ((*s++ = *t++));
}

/* return 1 if the last characters of s match t */
int endswith(char *s, char *t) {
    int s_len = strlen(s), t_len = strlen(t);
    return (s_len >= t_len) && !(strcmp(s + s_len - t_len, t));
}

/* get hex int from stdin */
long htoi(char * hex) {
    int i;
    long res = 0;
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
        i = 2;
    else
        i = 0;

    while (hex[i] != '\0') {
        int digit_value;
        if ('0' <= hex[i] && hex[i] <= '9')
            digit_value = hex[i] - '0';
        else if ('A' <= hex[i] && hex[i] <= 'F')
            digit_value = hex[i] - 'A' + 10;
        else if ('a' <= hex[i] && hex[i] <= 'f')
                digit_value = hex[i] - 'a' + 10;
        else {
            fprintf(stderr, "Error: wrong symbol \'%c\'", hex[i]);
            exit(1);
        }   
        res = res * 16 + digit_value;
        ++i;
        }
    return res;
    }
