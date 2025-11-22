#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<int> counts;
    stack<string> resultStack;
    string current;
    int k = 0;

    for (char c : s) {
        if (isdigit(c)) {
            // формируем число k (может быть многозначным)
            k = k * 10 + (c - '0');
        } 
        else if (c == '[') {
            // сохраняем текущее состояние
            counts.push(k);
            resultStack.push(current);

            // сбрасываем
            k = 0;
            current.clear();
        } 
        else if (c == ']') {
            // извлекаем число и предыдущую строку
            int repeat = counts.top(); counts.pop();
            string prev = resultStack.top(); resultStack.pop();

            // повторяем current repeat раз
            string repeated;
            repeated.reserve(current.size() * repeat);
            for (int i = 0; i < repeat; i++) repeated += current;

            // добавляем к предыдущей строке
            current = prev + repeated;
        } 
        else {
            // обычная буква
            current.push_back(c);
        }
    }

    return current;
}

int main() {
    string s;
    cin >> s;
    cout << decodeString(s);
    return 0;
}