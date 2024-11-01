#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCandies(const vector<int>& candies) {
    int n = candies.size();

    if (n == 1) return candies[0];
    if (n == 2) return max(candies[0], candies[1]);

    vector<int> max_candies(n, 0);
    max_candies[0] = candies[0];
    max_candies[1] = max(candies[0], candies[1]);

    for (int i = 2; i < n; i++) {
        max_candies[i] = max(max_candies[i - 1], candies[i] + max_candies[i - 2]);
    }

    return max_candies[n - 1];
}

int main() {
    int t;
    cin >> t;

    for (size_t i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> candies(n);

        for (int i = 0; i < n; i++) {
            cin >> candies[i];
        }

        cout << maxCandies(candies) << endl;
    }

    return 0;
}
