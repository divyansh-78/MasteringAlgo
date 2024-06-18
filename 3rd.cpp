#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    int arraySize, queryCount;
    cin >> arraySize >> queryCount;
    vector<int> array(arraySize);
    for (int i = 0; i < arraySize; ++i) {
        cin >> array[i];
    }
    vector<int> queries(queryCount);
    for (int i = 0; i < queryCount; ++i) {
        cin >> queries[i];
    }
    map<int, int> frequencyMap;
    for (int element : array) {
        frequencyMap[element]++;
    }
    for (int operations : queries) {
        map<int, int> tempMap = frequencyMap;
        for (int i = 0; i < operations; ++i) {
            if (tempMap.size() < 2) break;
            auto minElement = tempMap.begin();
            int minValue = minElement->first;
            if (--minElement->second == 0) {
                tempMap.erase(minElement);
            }
            auto maxElement = prev(tempMap.end());
            int maxValue = maxElement->first;
            if (--maxElement->second == 0) {
                tempMap.erase(maxElement);
            }
            int difference = maxValue - minValue;
            tempMap[difference]++;
        }
        long long totalSum = 0;
        for (const auto& [key, count] : tempMap) {
            totalSum += key * count;
        }
        cout << totalSum << " ";
    }
    cout << endl;
    return 0;
}
