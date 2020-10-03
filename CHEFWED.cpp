#include<bits/stdc++.h>

using namespace std;

int main() {
    long long int tests;
    cin >> tests;
    for (long long int test = 0; test < tests; test++) {
        long long int k;
        long long int n;

        cin >> n >> k;

        map < long long int, long long int > dictionary;

        long long int arr[n + 1];

        long long int final = 0;
        long long int i, j;
        long long int tests = 1;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long int tabley[n + 1][n + 1] = {
            0
        };

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                tabley[i][j] = 0;
            }
        }

        for (i = 0; i < n; i++) {
            dictionary.clear();
            for (j = i; j < n; j++) {
                if (j == 0) {
                    tabley[i][j] = 0;
                } else {
                    tabley[i][j] = tabley[i][j - 1];
                }

                if (dictionary.count(arr[j])) {
                    tabley[i][j]++;
                    if (dictionary[arr[j]] == 1) {
                        tabley[i][j]++;
                    }
                }

                dictionary[arr[j]]++;
            }

        }


        long long int prev[101][1001] = {
            0
        };

        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                prev[i][j] = 0;
            }
        }

        i = 0;
        while (i < n + 1) {
            prev[1][i] = tabley[0][i - 1];
            i++;
        }

        i = 2;
        while (i <= 100) {
            prev[i][1] = 0;
            i++;
        }

        for (i = 2; i <= 100; i++) {
            j = 2;
            while (j <= n) {
                long long int bestanswer = 1000000000000000000;
                long long int
                var = 1;
                while (var < j) {
                    bestanswer = min(bestanswer, prev[i - 1][var] + tabley[var][j - 1]);
                    var ++;
                }
                prev[i][j] = bestanswer;
                j++;
            }
        }
        final = 1000000000000000000;
        long long int tablex = 1;
        while (tablex <= 100) {
            final = min(tablex * k + prev[tablex][n], final);
            tablex++;
        }
        cout << final << endl;

    }

}
