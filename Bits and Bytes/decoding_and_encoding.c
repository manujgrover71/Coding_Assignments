/*
 * 
 * Program to convert base32 string into base64.
 * 
 * Compilation: gcc decoding_and_encoding.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * 
 * Resouces:
 * https://en.wikipedia.org/wiki/Base32
 * https://en.wikipedia.org/wiki/Base64
 * https://www.dcode.fr/base-32-encoding
 * https://www.garykessler.net/library/base64.html
 * 
*/

#include <stdio.h>
#include <string.h>

// base32 table
char base32[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

// base64 table.
char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// int value for base32, base64 table.
int base32_pos[256], base64_pos[256];

void init() {
    
    memset(base32_pos, -1, sizeof(base32_pos));
    memset(base64_pos, -1, sizeof(base64_pos));
    
    // fill the value for base32
    for(int i = 0; i < 32; i++) {
        base32_pos[base32[i]] = i;
    }
    
    // fill the value for base64.
    for(int i = 0; i < 64; i++) {
        base64_pos[base64[i]] = i;
    }
    
}


void solve() {
    
    // base32 string.
    char input[210];
    // scan the string.
    scanf("%s", input);
    
    // get the length of base32 string.
    int len = strlen(input);
    
    int string_binary[100000] = {0};
    int j = 0;
    
    // convert the base32 string into binary string, where each character of base32 will have a decimal
    // value according to the base32 array / table.
    // covert that decimal value to binary string of length 5.
    for(int i = 0; i < len; i++) {
        int decimal_char = input[i];
        
        int binary_val = base32_pos[decimal_char];
        
        if(binary_val != -1) {
            for(int k = 4; k >= 0; k--) {
                string_binary[j++] = (binary_val >> k) & 1;
            }
        }
        
    }
    
    char ascii_string[100000];
    int as = 0;
    
    // take the binary string and convert it into ascii string, i.e. take 8 bits and convert it ascii character
    // for example: 
    // binary string: 0100001101
    // slice into 8 bit parts: 01000011 01000000(add extra 0's if not there)
    // 01000011 = 67 = 'C' in ASCII
    for(int i = 0; i < j; ) {
        int temp = 0;
        
        for(int k = 7; k >= 0; k--, i++) {
            if(string_binary[i]) {
                temp += (1 << k);
            }
        }
        
        ascii_string[as++] = temp;
    }
    ascii_string[as] = 0;
    as = strlen(ascii_string);
    
    memset(string_binary, 0, sizeof(string_binary));
    j = 0;
    
    // convert the ascii string into decimal again.
    // split each character into 8 bits.
    for(int i = 0; i < as; i++) {
        int temp = ascii_string[i];
        
        for(int k = 7; k >= 0; k--) {
            string_binary[j++] = ((temp >> k) & 1);
        }
    }
    
    int ref = 0;
    char res[10000];
    int rs = 0;
    
    // take the binary string and make splits of 6 bits and take the value according to base64 array/table.
    for(int i = 0; ref < j; i++) {
        int decimal_val = 0;
        for(int k = 5; k >= 0 && ref < j; k--) {
            if(string_binary[ref++]) {
                decimal_val += (1 << k);
            }
        }
        res[rs++] = base64[decimal_val];
    }
    
    int temp = 0;
    
    
    // if length of ascii_string modulo 3 is 1, there will be two '=' for padding
    // if length of ascii_string modulo 3 is 2, there will be one '=' for padding
    // if length of ascii_string modulo 3 is 0 else there will be no '=' for padding
    
    if(as % 3 == 1) {
        temp = 2;
    }else if(as % 3 == 2) {
        temp = 1;
    }else temp = 0;
    
    for(int i = 0; i < temp; i++) {
        res[rs++] = '=';
    }
    res[rs] = '\0';
    
    // print the string.
    printf("%s\n", res);
}

int main() {
    // preprocess the base32, base64 table.
    init();
    
    int t;
    scanf("%d", &t);
    
    // for each test case.
    while(t--) {
        solve();
    }
    
    return 0;
}