#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    printf("Enter the code name: ");
    scanf("%s", s);

    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }

    printf("Mirrored code name: %s", s);

    return 0;
}
