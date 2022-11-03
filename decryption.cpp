#include <iostream>
#include "decryption.h"
#include "funcs.h"

string decryptCaesar(string ciphertext, int rshift){
    return encryptCaesar(ciphertext, 26 - rshift);
}