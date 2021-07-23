#include <stdio.h>
#include <string.h>

int checkAlphaNumeric(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

int checkCharacters(char a, char b) {
    if(a >= 'A' && a <= 'Z')
	a += 32;

    if(b >= 'A' && b <= 'Z')
	b += 32;

    return a == b;
}

int checkPalindrome(char str[], int len) {
    int i = 0, j = len - 1;

    while(i <= j) {
	if(!checkAlphaNumeric(str[i])) {
	    i++;
	    continue;
	}	

	if(!checkAlphaNumeric(str[j])) {
	    j--;
	    continue;
	}

	if(!checkCharacters(str[i], str[j]))
	    return 0;

	i++, j--;
    }

    return 1;
}

int main() {
    char str[100];
    scanf("%[^\n]%*c", str);

    int len = strlen(str);

    int res = checkPalindrome(str, len);

    if(res == 1) {
	printf("true\n");
    } else {
	printf("false\n");
    }
}

