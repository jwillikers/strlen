#include <stddef.h>
#include <strlen/strlen.h>

int my_strlen(char const *s) {
    if (s == NULL) {
        return 0;
    }

    int length = 0;
    // Progress through each character of the string, incrementing length, until
    // the terminating null character is reached.
    while (s[length] != '\0') {
        length++;
    }

    return length;
}
