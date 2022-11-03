#include <iostream>
#include "funcs.h"
#include <vector>
#include <cmath>
#include <algorithm>

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

void count_frequency(){
    vector<double> string_frequencies(26);

}
string solve(string encrypted_string, vector<double> frequencies){
    vector<double> english_frequencies{.084966,.020720,.045388,.033844,.111607,.018121,.024705,.030034, .075448,.001965,.011016,.054893,.030129,.066544,.071635,.031671,.001962,.075809,.057351,.069509,.036308,.010074,.012899,.002902,.017779,.002902};
    vector<string> alphabet{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    vector<double> string_frequencies(26); //will store how many occurences of each letter in encrypted_string
    //string_frequencies = getFrequencies(encrypted_string);

    for(int i = 0 ; i < encrypted_string.length(); i++){
        string_frequencies[i] = count(encrypted_string.begin(), encrypted_string.end(), alphabet[i]) / (1.0 * encrypted_string.length());
        cout<<string_frequencies[i]<<endl;
    }


    //apply distance formula
    double answer = 0;
    for(int i = 0 ; i < encrypted_string.length(); i++){
        answer += pow(frequencies[i] - english_frequencies[i] , 2);
    }
}

// double calculateDistance(vector<double> frequencies, ){

// }
// vector <double> getFrequencies(string s){
//     vector <double> frequencies(26);
//     int count = 0;

//     for(int i = 0 ; i < s.length(); i++){
//         switch(s[i]){
//             case 'a':
//             frequencies[0] += 1;
//             count++;
//             break;
//             case 'b':
//             frequencies[1] += 1;
//             count++;
//             break;
//             case 'c':
//             frequencies[2] += 1;
//             count++;
//             break;
//             case 'd':
//             frequencies[3] += 1;
//             count++;
//             break;
//             case 'e':
//             frequencies[4] += 1;
//             count++;
//             break;
//             case 'f':
//             frequencies[5] += 1;
//             count++;
//             break;
//             case 'f':
//             frequencies[6] += 1;
//             count++;
//             break;
//             case 'h':
//             frequencies[7] += 1;
//             count++;
//             break;
//             case 'i':
//             frequencies[8] += 1;
//             count++;
//             break;
//             case 'j':
//             frequencies[9] += 1;
//             count++;
//             break;
//             case 'k':
//             frequencies[10] += 1;
//             count++;
//             break;
//             case 'l':
//             frequencies[11] += 1;
//             count++;
//             break;
//             case 'm':
//             frequencies[12] += 1;
//             count++;
//             break;
//             case 'n':
//             frequencies[13] += 1;
//             count++;
//             break;
//             case 'o':
//             frequencies[14] += 1;
//             count++;
//             break;
//             case 'p':
//             frequencies[15] += 1;
//             count++;
//             break;
//             case 'q':
//             frequencies[16] += 1;
//             count++;
//             break;
//             case 'r':
//             frequencies[17] += 1;
//             count++;
//             break;
//             case 's':
//             frequencies[18] += 1;
//             count++;
//             break;
//             case 't':
//             frequencies[19] += 1;
//             count++;
//             break;
//             case 'u':
//             frequencies[20] += 1;
//             count++;
//             break;
//             case 'v':
//             frequencies[21] += 1;
//             count++;
//             break;
//             case 'w':
//             frequencies[22] += 1;
//             count++;
//             break;
//             case 'x':
//             frequencies[23] += 1;
//             count++;
//             break;
//             case 'y':
//             frequencies[24] += 1;
//             count++;
//             break;
//             case 'z':
//             frequencies[25] += 1;
//             count++;
//             break;
//         }
//         for(int i = 0; i < 26; i++){
//             frequencies[i] = frequencies[i] / count;
//         }
//         return frequencies;
//     }