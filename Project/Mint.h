/*
 * Mint Header containing all the function declarations.
 */

#ifndef MINT_H
#define MINT_H

// struct mint which contains two variables: .val, .mod
struct mint {
    int val;
    int mod;
};

void add(struct mint *this, int b);

void add_mm(struct mint *a, struct mint *b);

void subtract(struct mint *this, int b);

void subtract_mm(struct mint *a, struct mint *b);

void multiply(struct mint *this, int b);

void multiply_mm(struct mint *a, struct mint *b);

void divide(struct mint *this, int b);

void divide_mm(struct mint *a, struct mint *b);

void mod_inverse(struct mint *this);

int equals(struct mint *this, int b);

int equals_mm(struct mint *a, struct mint *b);

void checkMint(struct mint *this);

int power_helper(int x, int y, int m);

#endif //MINT_H
