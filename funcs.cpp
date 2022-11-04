#include <iostream>
#include "funcs.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>

//from lab 6
char shiftChar(char c, int rshift){
    char newchar;
    if(!isalpha(c))
        return c;
    else if(isupper(c))
        newchar = (c - 'A' + rshift) % 26 + 'A';
    else
        newchar = (c - 'a' + rshift) % 26 + 'a';
    return newchar;
}

string encryptCaesar(string plaintext, int rshift){
    string newString = "";
    for(int i = 0; i < plaintext.length(); i++){
        newString += shiftChar(plaintext[i], rshift);
    }
    return newString;
}

string decryptCaesar(string ciphertext, int rshift){
    return encryptCaesar(ciphertext, 26 - rshift);
}

vector<double> countFrequencies(string encrypted_string){

    vector<double> frequencies(26,0.0);

    for(int i = 0; i < encrypted_string.length(); i++){
        if(isalpha(encrypted_string[i])){
            int index = 0;

            if(isupper(encrypted_string[i]))
                index = (int)(encrypted_string[i]) - 65;
            else //lowercase
                index = (int)(encrypted_string[i]) - 97;
            
            frequencies[index] += 1;
        }
    }
    //calculate frequencies
    for(int i = 0; i < 26; i++)
        frequencies[i] = frequencies[i] / encrypted_string.length();

    return frequencies;
}

//for loop from 0-26, where each iteration represents a shift in decrypt caesar
//calculate frequencies using a functoin (of each character - size 26 array)
// compare distance between frequencies (add distances +=)
// keep track of minimum distance rotation
// return output

string solve(string encrypted_string){
    vector<double> english_frequencies{.084966,.020720,.045388,.033844,.111607,.018121,.024705,.030034, .075448,.001965,.011016,.054893,.030129,.066544,.071635,.031671,.001962,.075809,.057351,.069509,.036308,.010074,.012899,.002902,.017779,.002902};
    vector<double> curr_frequencies(26, 0.0);

    double closest = 0.0; //min initially
    string output = "";
    string rotated = ""; //rotated string
    double currFreq = 0.0;

    for(int i = 0 ; i < 26; i++){
        rotated = decryptCaesar(encrypted_string, i);
        curr_frequencies = countFrequencies(rotated);
        double distance = 0.0;
    
    for(int j = 0; j < 26; j++)
        distance += pow((curr_frequencies[j] - english_frequencies[j]) , 2);
    

        if(closest == 0.0){
            closest = distance;
            output = rotated;
        }
        if(distance < closest){
            closest = distance;
            output = rotated;
        }

    }

    return output;
}
