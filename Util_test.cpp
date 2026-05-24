#include <iostream>
#include "Library/clsDate.h"
#include "Library/clsUtil.h"

using namespace std;

int main()
{
    clsUtil::Srand();

    cout << clsUtil::RandomNumber(1, 10) << endl;
    cout << clsUtil::GetRandomCharacter(clsUtil::CapitalLetter) << endl;
    cout << clsUtil::GenerateWord(clsUtil::MixChars, 8) << endl;

    string key = clsUtil::GenerateKey(clsUtil::MixChars);
    cout << key << endl;

    clsUtil::GenerateKeys(3, clsUtil::MixChars);

    cout << "\n";

    int x = 10, y = 20;
    clsUtil::Swap(x, y);
    cout << "Swap int: " << x << " " << y << endl;

    string s1 = "Ali", s2 = "Ahmed";
    clsUtil::Swap(s1, s2);
    cout << "Swap string: " << s1 << " " << s2 << endl;

    clsDate d1(1, 10, 2022), d2(1, 1, 2022);
    clsUtil::Swap(d1, d2);
    cout << "Swap dates: " << d1.DateToString() << " "
         << d2.DateToString() << endl;

    int arr[5] = {1,2,3,4,5};
    clsUtil::ShuffleArray(arr, 5);

    cout << "\nShuffled array:\n";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << endl;

    string text = "Mohammed";
    string enc = clsUtil::EncryptText(text, 2);
    string dec = clsUtil::DecryptText(enc, 2);

    cout << "\nOriginal: " << text << endl;
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << dec << endl;

    return 0;
}