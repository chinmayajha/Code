// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Find all subsequences
void printSubsequence(string input, string output) {
    // Base Case
    // if the input is empty print the output string
    if (input.empty()) {
        cout << output << ", ";
        return;
    }

    // output is passed with including
    // the Ist characther of
    // Input string
    printSubsequence(input.substr(1), output + input[0]);

    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output);
}

// Driver code
int main() {
    // output is set to null before passing in as a
    // parameter
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string output = "";
    string input = "abcde";

    printSubsequence(input, output);

    return 0;
}
