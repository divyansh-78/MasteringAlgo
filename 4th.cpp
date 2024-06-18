#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxOreosDP(vector<pair<int, int>>& packets, int n, int budget) {
    vector<int> dp(budget + 1, 0);
    for (int i = 0; i < n; ++i) {
        int cost = packets[i].first;
        int oreos = packets[i].second;
        for (int j = budget; j >= cost; --j) {
            dp[j] = max(dp[j], dp[j - cost] + oreos);
        }
    }
    return dp[budget];
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int packetCount, maxCost;
        cin >> packetCount >> maxCost;
        vector<pair<int, int>> packets(packetCount);
        for (int i = 0; i < packetCount; ++i) {
            cin >> packets[i].first >> packets[i].second;
        }
        cout << maxOreosDP(packets, packetCount, maxCost) << endl;
    }
    return 0;
}
