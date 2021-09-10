/*
 * Implementation of functions of mint header file.
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 */

#include <limits.h>
#include <assert.h>
#include "Mint.h"

/*
 * Function that returns the pow(x, y) with modulo m.
 */
int power_helper(int x, int y, int m) {
    long long res = 1;
    while(y > 0) {
        if(y & 1) res = (res * x) % m;
        y >>= 1;
        x = ((x % m) * (x % m)) % m;
    }

    return res % m;
}

/*
 * Function that check the limits and reduces the mint with respect to its modulo.
 */
void checkMint(struct mint *this) {
    assert(this->mod >= 1 && this->mod <= INT_MAX);

    this->val %= this->mod;
}

/*
 * Function which add a mint and an int with respect to its modulo.
 */
void add(struct mint *this, int b) {
    // check the mint
    checkMint(this);

    // reduce b according to mint's modulo value.
    b %= this->mod;

    // add the result.
    long long res = this->val;
    res = (res + (long long)b);

    if(res >= this->mod)
        res %= this->mod;

    // assign th result.
    this->val = (int)res;
}

/*
 * Function that add two mints.
 */
void add_mm(struct mint *a, struct mint *b) {
    // check both mints.
    checkMint(a);
    checkMint(b);

    // calculate the addition..
    long long res = a->val;
    res = (res + (long long)b->val);

    // if the range is above the mod value, apply mod.
    if(res >= a->mod) {
        res %= a->mod;
    }

    // assign the value.
    a->val = (int)res;
}

/*
 * Function to multiply a mint and int.
 */
void multiply(struct mint *this, int b) {
    // check mint.
    checkMint(this);

    // reduce b according to mint's modulo.
    b %= this->mod;

    // calculate the result.
    long long res = (long long)this->val;
    res = (res * (long long)b);

    // if the result is greater than mint's mod value, apply modulo.
    if(res >= this->mod)
        res %= this->mod;

    // assign the result.
    this->val = (int)res;
}

/*
 * Function to multiply two mints.
 */
void multiply_mm(struct mint *a, struct mint *b) {
    // check both mints.
    checkMint(a);
    checkMint(b);

    // calculate the result.
    long long res = a->val;
    res = (res * (long long)b->val);

    // if the result is greater than mint's mod value, apply modulo.
    if(res >= a->mod)
        res = (res % a->mod);

    // assign the result.
    a->val = (int)res;
}

/*
 * Function to subtract mint from int.
 */
void subtract(struct mint *this, int b) {
    // check mint.
    checkMint(this);

    // reduce int value.
    b %= this->mod;

    // calculate the result.
    long long res = this->val;
    res = (res - (long long)b);

    // if the result is negative, add mod.
    if(res < 0) {
        res = (res + this->mod);
    }

    // assign the value.
    this->val = (int)res;
}

/*
 * Function to subtract two mints.
 */
void subtract_mm(struct mint *a, struct mint *b) {
    // check both mints.
    checkMint(a);
    checkMint(b);

    // calculate the result.
    long long res = (long long) a->val - (long long) b->val;

    // if the result is negative, add mod.
    if(res < 0) {
        res = (res + a->mod);
    }

    // assign mod value.
    a->val = (int)res;
}

/*
 * Function to divide mint with int.
 */
void divide(struct mint *this, int b) {
    // check mint.
    checkMint(this);

    // check if int is zero.
    assert(b != 0);

    // calculate the result.
    long long res = this->val;
    res = (res / b);
    res = (res % this->mod);

    // assign the value.
    this->val =  (int)res;
}

/*
 * Function to divide two mints.
 */
void divide_mm(struct mint *a, struct mint *b) {
    // check both mints.
    checkMint(a);
    checkMint(b);

    // calculate the result.
    long long res = a->val;
    res = (res / (long long)b->val);
    res = (res % a->mod);

    // assing the result.
    a->val = (int)res;
}

/*
 * Function to find the mod_inverse of a given mint.
 */
void mod_inverse(struct mint *this) {
    // check mint.
    checkMint(this);
    // calculate and assign the mod_inverse.
    this->val = power_helper(this->val, this->mod - 2, this->mod);
}

/*
 * Function to check if a mint and an int are equal, with or without mod.
 */
int equals(struct mint *this, int b) {
    // check mint.
    checkMint(this);

    return (this->val == b) || (this->val % this->mod == b % this->mod);
}

/*
 * Function to check if two mints are equal, with or without mod.
 */
int equals_mm(struct mint *a, struct mint *b) {
    // check both mints.
    checkMint(a);
    checkMint(b);

    return (a->val == b->val) || ((a->val % a->mod) == (b->val % b->mod));
}
