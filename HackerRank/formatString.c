#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'FormatString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char sz[] = "static allocation of string";
 *
 *     return sz;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* sz = malloc(100 * sizeof(char));
 *
 *     sz = "dynamic allocation of string";
 *
 *     return sz;
 * }
 *
 */
char* FormatString(char* s) {
    char *sz = malloc(100 * sizeof(char));
    int i = 0;
    int k = 0;
    int tracker = 0;
    while (s[i] != '\0')
    {
        if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            
            sz[k] = s[i];
            tracker++;
            k++;
            if(tracker % 3 == 0)
            {
                sz[k] = ' ';
                k++;
            }
        }
        i++;
    }
    sz[k] = '\0';
    if (sz[k - 2] == ' ')
    {
        char temp;
        temp = sz[k-3];
        sz[k - 3] = ' ';
        sz[k - 2] = temp;
    }
    return (sz);
}
/*
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = FormatString(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            *data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            *data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            *data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
*/