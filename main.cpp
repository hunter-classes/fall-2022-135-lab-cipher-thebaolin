#include <iostream>
#include "funcs.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include "doctest.h"
using namespace std;

int main(){
    string encrypted_string = "Miffy";
    vector<double> english_frequencies{.084966,.020720,.045388,.033844,.111607,.018121,.024705,.030034, .075448,.001965,.011016,.054893,.030129,.066544,.071635,.031671,.001962,.075809,.057351,.069509,.036308,.010074,.012899,.002902,.017779,.002902};
    vector<string> alphabet{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    vector<double> string_frequencies(26); //will store how many occurences of each letter in encrypted_string
    //string_frequencies = getFrequencies(encrypted_string);

    for(int i = 0 ; i < encrypted_string.length(); i++){
        string_frequencies[i] = count(encrypted_string.begin(), encrypted_string.end(), alphabet[i]) / (1.0 * encrypted_string.length());
        cout<<string_frequencies[i]<<endl;
    }
}
