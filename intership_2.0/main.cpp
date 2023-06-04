#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int findUnfairDigit(const string sequence) {
    int n = sequence.length();

    int onesOnEven = 0;
    int onesOnOdd = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            onesOnEven += sequence[i] - '0';
        else
            onesOnOdd += sequence[i] - '0';
    }

    int leftOnEven = 0;
    int leftOnOdd = 0;
    int rightOnEven = onesOnEven;
    int rightOnOdd = onesOnOdd;

    if (onesOnEven == 0 && onesOnOdd == 0) {
        return 0;
    }
    else if (sequence.length() == 1) {
        return 0;
    }
    else if(onesOnEven+onesOnOdd==sequence.length()){
        return 1;
    }
    else if ((onesOnEven == 1 && onesOnOdd == 0) || (onesOnEven == 0 && onesOnOdd == 1)) {
        return 0;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                rightOnEven -= sequence[i] - '0';
                if (leftOnEven + rightOnOdd == leftOnOdd + rightOnEven)
                    return i + 1;
                leftOnEven += sequence[i] - '0';
            }
            else {
                rightOnOdd -= sequence[i] - '0';
                if (leftOnEven + rightOnOdd == leftOnOdd + rightOnEven)
                    return i + 1;
                leftOnOdd += sequence[i] - '0';
            }
        }

        return 0;
    }

}

int main() {
    ifstream inputFile("D:/intership/intership_2.0/fair.in.txt");
    ofstream outputFile("D:/intership/intership_2.0/fair.out.txt");

    string sequence;
    inputFile >> sequence;

    int unfairDigit = findUnfairDigit(sequence);

    outputFile << unfairDigit << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
