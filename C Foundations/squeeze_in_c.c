#include <stdio.h>

void shift(char *str, int start) {
    for(int i = start; str[i] != '\0'; i++) {
        str[i] = str[i + 1];
    }
}

void squeeze(char *s1, char *s2) {

    int vis[256] = {0};

    for(int i = 0; s2[i] != '\0'; i++) {
        vis[s2[i]] = 1;
    }

    for(int i = 0; s1[i] != '\0'; i++) {
        while(s1[i] != '\0' && vis[s1[i]]) {
            shift(s1, i);
        }
    }
}

int main() {
    char s1[100], s2[100];
    // scan the strings.
    scanf("%s %s", s1, s2);

    // squeeze s1.
    squeeze(s1, s2);
    
    // print the squeezed s1 string.
    printf("%s\n", s1);
}
