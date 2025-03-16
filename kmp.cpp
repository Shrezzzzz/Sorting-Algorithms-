#include <iostream>
#include <vector>
using namespace std;

void computeLPSArray(const string &pattern, vector<int> &lps) {
    int length = 0, i = 1;
    lps[0] = 0;

    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0)
                length = lps[length - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string &pattern, const string &text) {
    vector<int> lps(pattern.size());
    computeLPSArray(pattern, lps);

    int i = 0, j = 0;
    while (i < text.size()) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == pattern.size()) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < text.size() && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    KMPSearch(pattern, text);

    return 0;
}

