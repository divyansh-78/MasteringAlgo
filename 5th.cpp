#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int calculateDigitSum(const string& str) {
    int totalSum = 0;
    for (char digit : str) {
        totalSum += digit - '0';
    }
    return totalSum;
}

int main() {
    int numStrings;
    cin >> numStrings;
    vector<string> inputStrings(numStrings);
    for (int i = 0; i < numStrings; ++i) {
        cin >> inputStrings[i];
    }
    
    unordered_map<int, int> sumFrequency;
    int numberOfValidPairs = 0;
    
    for (const string& str : inputStrings) {
        int currentDigitSum = calculateDigitSum(str);
        int neededSum = 50 - currentDigitSum;
        
        if (sumFrequency.find(neededSum) != sumFrequency.end()) {
            numberOfValidPairs += sumFrequency[neededSum];
        }
        
        sumFrequency[currentDigitSum]++;
    }
    
    cout << numberOfValidPairs << endl;
    return 0;
}
