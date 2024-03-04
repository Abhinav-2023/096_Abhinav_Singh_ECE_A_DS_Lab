#include <stdio.h>
#include <string.h>

int string_length(char str[]) {
    return strlen(str);
}

void string_reverse(char result[], char str[]) {
    strcpy(result, str);
    strrev(result);
}

int string_compare(char str1[], char str2[]) {
    return strcmp(str1, str2);
}

void string_concatenate(char result[], char str1[], char str2[]) {
    strcpy(result, str1);
    strcat(result, str2);
}

void string_copy(char dest[], char src[]) {
    strcpy(dest, src);
}

int main() {
    char str1[100], str2[100], result[200], copy[100];

    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    printf("Length of string 1: %u\n", string_length(str1));
    printf("Length of string 2: %u\n", string_length(str2));

    string_reverse(result, str1);
    printf("Reversed string 1: %s\n", result);
    string_reverse(result, str2);
    printf("Reversed string 2: %s\n", result);

    int compare_result = string_compare(str1, str2);
    if (compare_result == 0)
        printf("Comparison result: Strings are equal\n");
    else if (compare_result < 0)
        printf("Comparison result: String 2 is less than String 1\n");
    else
        printf("Comparison result: String 2 is greater than String 1\n");

    string_concatenate(result, str1, str2);
    printf("Concatenated string: %s\n", result);

    string_copy(copy, str1);
    printf("Copied string: %s\n", copy);

    return 0;
}
