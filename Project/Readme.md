# Mint (Modular Int)
Mint is a C helper file which mimics the primary data type integer in C but all the operations on the mint are done with respect to a modulo value.

## Specifications
- Mint.h is the header file containing all the declarations, just import the file in your project and enjoy all the features :rocket:
- Mint.c is file which contains all the implementation of functions.

## Setup
Clone the repository.
```shell
git clone https://github.com/manujgrover71/Coding_Assignments/Project/Mint.c
```
Create a new C file in desired directory.
```shell
touch test.c
```
Import the Mint.h file into your C file.
```c
#import "Mint.h"
```
Compiler the program using GCC.
```shell
gcc mint.c test.c
```
Run the executable
```shell
./a.out
```

## Instance variables
| Name | Syntax | Info |
| :---: | :---: | :--: |
| Value | .val | The Integer value stored in the Mint variable |
| Modulo | .mod_value | All the operations are done respect to this modulo value |

## Usage
Declaring
```c
// val must be in the range of [INT_MIN, INT_MAX]
// mod_value must be in the range of [1, INT_MAX]

struct mint variable_name = {10, 33}; // first value is val, second value is mod_value
// or
struct mint variable_name;
variable_name.val = 10; 
variable_name.mod_value = 33; 
```
Accessing the mint instance variables.
```c
// struct mint a = {10, (int)1e9 + 7};

// use .val to get the value and .mod_value to get the current mod.
printf("%d %d", a.val, a.mod_value); 
```
Using any mint function
```c
// struct mint a = {10, (int)1e9 + 7};

multiply(a, 10);

add(a, 100);
```
## Functions
| Return Type | Name |  Declaration  | Info |
| :---: | :---: | :-----: | :--: |
| void | Add | `add(struct mint &this, int b)`  | Add integer b to mint variable |
| void | Subtract | `subtract(struct mint &this, int b)` | Subtract integer b from mint variable |
| void | Multiply | `mutliply(struct mint &this, int b)` | Multiply integer b to mint variable |
| void | Divide | `divide(struct mint &this, int b)` | Divide mint variable by integer b |
| void | Mod Inverse | `mod_inverse(struct mint &a)` | Calculate the mod inverse value of mint using the mint's modulo value (The modulo value must be a prime.) |
| int | Equals | `equals(struct mint &this, int b)` | Checks whether mint variable value is same as integer b <br>(with or without modulo operation) |

__more coming soon...__

> Note: All the function can be used with two mints as parameters by using the same functions prefixes ending with "_mm"<br>
> Example: add_mm(struct mint &a, struct mint &b)

