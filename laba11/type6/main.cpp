#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp = triangle.back(); // последняя строка

    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col < triangle[row].size(); col++) {
            dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
        }
    }

    return dp[0];
}

int main() {
    string s;
    getline(cin, s); // читаем всю строку вида [[2],[3,4],[6,5,7],[4,1,8,3]]

    vector<vector<int>> triangle;
    vector<int> current;
    int num = 0;
    bool inNumber = false, negative = false;

    for (char c : s) {
        if (c == '-') {
            negative = true;
        }
        else if (isdigit(c)) {
            inNumber = true;
            num = num * 10 + (c - '0');
        }
        else {
            if (inNumber) {
                if (negative) num = -num;
                current.push_back(num);
                num = 0;
                inNumber = false;
                negative = false;
            }
            if (c == ']') {
                if (!current.empty()) {
                    triangle.push_back(current);
                    current.clear();
                }
            }
        }
    }

    cout << minimumTotal(triangle);
    return 0;
}