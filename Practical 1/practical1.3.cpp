#include <iostream>
using namespace std;

int main() {
    string str, word, longest = "";
    cout<<"Enter your string"<<endl;
    getline(cin, str);

    str += ' ';

    for (int i=0; i<str.length(); i++) {
        if (str[i] != ' ') {
            word += str[i];
        } else {
            if (word.length() > longest.length()) {
                longest = word;
            }
            word = "";
        }
    }
    cout <<"longest word is : "<<longest << endl;
    cout <<"length : "<<longest.length();

    return 0;
}
