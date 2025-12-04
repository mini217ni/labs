#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

class BitString {
private:
    unsigned long high; // старшие 32 бита
    unsigned long low;  // младшие 32 бита

public:
    // --- Конструкторы ---
    BitString() : high(0), low(0) {}

    BitString(unsigned long h, unsigned long l) : high(h), low(l) {}

    // --- Инициализация из другой битовой строки ---
    void initFromBitString(const BitString& other) {
        high = other.high;
        low = other.low;
    }

    // --- Инициализация из строки (0 и 1, длина до 64) ---
    void initFromString(const string& s) {
        if (s.length() > 64)
            throw invalid_argument("Слишком длинная битовая строка");

        high = 0;
        low = 0;

        for (char c : s) {
            if (c != '0' && c != '1')
                throw invalid_argument("Строка должна содержать только 0 или 1");

            shiftLeft(1);
            if (c == '1') low |= 1;
        }
    }

    // --- Геттеры ---
    unsigned long getHigh() const { return high; }
    unsigned long getLow() const { return low; }

    // --- Побитовые операции ---
    BitString bitAnd(const BitString& other) const {
        return BitString(high & other.high, low & other.low);
    }

    BitString bitOr(const BitString& other) const {
        return BitString(high | other.high, low | other.low);
    }

    BitString bitXor(const BitString& other) const {
        return BitString(high ^ other.high, low ^ other.low);
    }

    BitString bitNot() const {
        return BitString(~high, ~low);
    }

    // --- Сдвиг влево ---
    void shiftLeft(int n) {
        if (n < 0) {
            shiftRight(-n);
            return;
        }

        if (n >= 64) {
            high = 0;
            low = 0;
            return;
        }

        while (n--) {
            high <<= 1;
            if (low & (1UL << 31))
                high |= 1;
            low <<= 1;
        }
    }

    // --- Сдвиг вправо ---
    void shiftRight(int n) {
        if (n < 0) {
            shiftLeft(-n);
            return;
        }

        if (n >= 64) {
            high = 0;
            low = 0;
            return;
        }

        while (n--) {
            low >>= 1;
            if (high & 1)
                low |= (1UL << 31);
            high >>= 1;
        }
    }

    // --- Вывод в бинарном виде ---
    string toBinaryString() const {
        string result;

        for (int i = 31; i >= 0; --i)
            result += ((high >> i) & 1) ? '1' : '0';

        for (int i = 31; i >= 0; --i)
            result += ((low >> i) & 1) ? '1' : '0';

        return result;
    }
};

// ---------------------- MAIN ----------------------
int main() {
    setlocale(LC_ALL, "");

    try {
        // --- Автоматические тесты ---
        BitString a;
        a.initFromString("101010");

        BitString b;
        b.initFromString("111100");

        cout << "a: " << a.toBinaryString() << "\n";
        cout << "b: " << b.toBinaryString() << "\n";

        BitString c = a.bitAnd(b);
        cout << "a AND b: " << c.toBinaryString() << "\n";

        c = a.bitOr(b);
        cout << "a OR b:  " << c.toBinaryString() << "\n";

        c = a.bitXor(b);
        cout << "a XOR b: " << c.toBinaryString() << "\n";

        c = a.bitNot();
        cout << "NOT a:   " << c.toBinaryString() << "\n";

        a.shiftLeft(3);
        cout << "a << 3:  " << a.toBinaryString() << "\n";

        a.shiftRight(5);
        cout << "a >> 5:  " << a.toBinaryString() << "\n";

        // --- Ввод от пользователя ---
        cout << "\nВведите битовую строку (до 64 бит): ";
        string input;
        cin >> input;

        BitString user;
        user.initFromString(input);

        cout << "Вы ввели:  " << user.toBinaryString() << "\n";

        cout << "Введите сдвиг: ";
        int shift;
        cin >> shift;
        user.shiftLeft(shift);
        cout << "После сдвига: " << user.toBinaryString() << "\n";
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}