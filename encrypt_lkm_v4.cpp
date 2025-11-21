#include <iostream>
#include <cstdio>
using namespace std;
int a=106;
int c=1283;
int m=26;
int choice;
int current_seed=1234;
int next_seed() {
    int current_seed = (a*current_seed+c)%m;
    return current_seed;
}
char encrypt(char& decrypted_char) {
    char encrypted_char;
    char a = decrypted_char;
    if (a >= 'A' && a <= 'Z') {
        int seed = a - 'A';
        int n_seed = next_seed();
        int encrypted_seed = (seed+n_seed)%m;
        encrypted_char = (char)('A' + encrypted_seed);
    }
    else if (a >= 'a' && a <= 'z') {
        int seed = a - 'a';
        int n_seed = next_seed();
        int encrypted_seed = (seed+n_seed)%m;
        encrypted_char = (char)('a' + encrypted_seed);
    }
    else encrypted_char = a;
    return encrypted_char;
}
char decrypt(char& encrypted_char) {
    char decrypted_char;
    char a = encrypted_char;
    if (a >= 'A' && a <= 'Z') {
        int seed = a - 'A';
        int n_seed = next_seed();
        int decrypted_seed = ((seed-n_seed)+m)%m;
        decrypted_char = (char)('A' + decrypted_seed);
    }
    else if (a >= 'a' && a <= 'z') {
        int seed = a - 'a';
        int n_seed = next_seed();
        int decrypted_seed = ((seed-n_seed)+m)%m;
        decrypted_char = (char)('a' + decrypted_seed);
    }
    else decrypted_char = a;
    return decrypted_char;
}
int main() {
    const int max_arr_size = 1024;
    char text[max_arr_size];
    int new_char;
    int i=0;
    cout << "Исходный текст: " << endl;
    while (i < max_arr_size - 1 && (new_char = getchar()) != '\n' && new_char != EOF) {
        text[i] = static_cast<char>(new_char);
        i++;
    }
    text[i]='\0';
    cout << "1 - шифрование, 2 - дешифрование [1/2]: " << endl;
    cin >> choice;
    if (choice == 1) { 
        for (int i = 0; i < size(text) && text[i]!='\0'; i++) {
            cout << encrypt(text[i]);
       }}
    else if (choice == 2) {
        for (int i = 0; i < size(text) && text[i]!='\0'; i++) {
            cout << decrypt(text[i]);
    }}
    return 0;

}
