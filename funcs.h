#pragma once
#include <vector>
#include <iostream>
using namespace std;

string encryptCaesar(string plaintext, int rshift);
string decryptCaesar(string ciphertext, int rshift);
char shiftChar(char c, int rshift);
string solve(string encrypted_string);
vector<double> countFrequencies(string encrypted_string);
