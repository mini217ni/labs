#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// класс
class BitStringClass {
private:
    unsigned long high;
    unsigned long low;

public:
    BitStringClass() : high(0), low(0) {}

    void init(unsigned long h = 0, unsigned long l = 0) {
        high = h;
        low  = l;
    }

    void read() {
        cout << "Введите старшие 32 бита (hex): ";
        cin >> hex >> high;
        cout << "Введите младшие 32 бита (hex): ";
        cin >> hex >> low;
        cin >> dec;
    }

    void display() const { cout << "high = 0x" << hex << high << " low = 0x" << low << dec << endl; }
    string toString() const { return "high = " + to_string(high) + ", low = " + to_string(low); }



    // И
    BitStringClass bitAnd(const BitStringClass &b) const {
        BitStringClass r;
        r.init(high & b.high, low & b.low);
        return r;
    }

    // ИЛИ
    BitStringClass bitOr(const BitStringClass &b) const {
        BitStringClass r;
        r.init(high | b.high, low | b.low);
        return r;
    }

    // исключающее ИЛИ
    BitStringClass bitXor(const BitStringClass &b) const {
        BitStringClass r;
        r.init(high ^ b.high, low ^ b.low);
        return r;
    }

    // НЕ
    BitStringClass bitNot() const {
        BitStringClass r;
        r.init(~high, ~low);
        return r;
    }

    // сдвиг влево
    BitStringClass shiftLeft(int n) const {
        BitStringClass r = *this;

        if (n >= 64) return BitStringClass();

        if (n >= 32) {
            r.high = r.low << (n - 32);
            r.low = 0;
        } else {
            r.high = (r.high << n) | (r.low >> (32 - n));
            r.low <<= n;
        }

        return r;
    }

    // сдвиг вправо
    BitStringClass shiftRight(int n) const {
        BitStringClass r = *this;

        if (n >= 64) return BitStringClass();

        if (n >= 32) {
            r.low = r.high >> (n - 32);
            r.high = 0;
        } else {
            r.low = (r.low >> n) | (r.high << (32 - n));
            r.high >>= n;
        }

        return r;
    }
};




// структура
struct BitString {
    unsigned long high;
    unsigned long low;
};

void init(BitString &bs, unsigned long h = 0, unsigned long l = 0) {
    bs.high = h;
    bs.low = l;
}

// ввод
void read(BitString &bs) {
    cout << "Введите старшие 32 бита (hex): ";
    cin >> hex >> bs.high;
    cout << "Введите младшие 32 бита (hex): ";
    cin >> hex >> bs.low;
    cin >> dec;
}

// вывод
void display(const BitString &bs) {
    cout << "high = 0x" << hex << bs.high
         << " low = 0x" << bs.low << dec << endl;
}

// преобразование в строку
string toString(const BitString &bs) {
    return "high = " + to_string(bs.high) +
           ", low = " + to_string(bs.low);
}

// И
BitString bitAnd(const BitString &a, const BitString &b) {
    BitString r;
    init(r, a.high & b.high, a.low & b.low);
    return r;
}

// ИЛИ
BitString bitOr(const BitString &a, const BitString &b) {
    BitString r;
    init(r, a.high | b.high, a.low | b.low);
    return r;
}

// исключающее ИЛИ
BitString bitXor(const BitString &a, const BitString &b) {
    BitString r;
    init(r, a.high ^ b.high, a.low ^ b.low);
    return r;
}

// НЕ
BitString bitNot(const BitString &a) {
    BitString r;
    init(r, ~a.high, ~a.low);
    return r;
}



// сдвиг влево
BitString shiftLeft(const BitString &a, int n) {
    BitString r = a;
    if (n >= 64) return {0,0};

    if (n >= 32) {
        r.high = r.low << (n - 32);
        r.low = 0;
    } else {
        r.high = (r.high << n) | (r.low >> (32 - n));
        r.low <<= n;
    }
    return r;
}

// сдвиг вправо
BitString shiftRight(const BitString &a, int n) {
    BitString r = a;
    if (n >= 64) return {0,0};

    if (n >= 32) {
        r.low = r.high >> (n - 32);
        r.high = 0;
    } else {
        r.low = (r.low >> n) | (r.high << (32 - n));
        r.high >>= n;
    }
    return r;
}








int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "|-~-| Классы:\n\n";
    BitStringClass x;
    x.init(0xAAAA0000, 0x0000BBBB);

    cout << "Инициализация объекта x (константные значения):\n";
    x.display();
    cout << "Строка: " << x.toString() << "\n\n";

    BitStringClass y;
    cout << "Введите объект y:\n";
    y.read();
    cout << "y: ";
    y.display();
    cout << "\n";

    cout << "---- Побитовые операции ----\n";
    cout << "x AND y:\n"; x.bitAnd(y).display();
    cout << "x OR  y:\n"; x.bitOr(y).display();
    cout << "x XOR y:\n"; x.bitXor(y).display();
    cout << "NOT x:\n";  x.bitNot().display();
    cout << "\n";

    int n;
    cout << "Введите количество бит для сдвига: ";
    cin >> n;

    cout << "\n---- Сдвиги ----\n";
    cout << "x << n:\n"; x.shiftLeft(n).display();
    cout << "x >> n:\n"; x.shiftRight(n).display();
    cout << "\nСтрока результата (x >> n): " << x.shiftRight(n).toString() << "\n\n\n";

 



    cout << "|-~-| Структуры:\n\n";
    BitString a;
    init(a, 0xFFFF0000, 0x0000FFFF);

    cout << "Инициализация объекта a (константные значения):\n";
    display(a);
    cout << "Строка: " << toString(a) << "\n\n";

    BitString b;
    cout << "Введите объект b:\n";
    read(b);
    cout << "b: ";
    display(b);
    cout << "\n";

    cout << "---- Побитовые операции ----\n";
    cout << "a AND b:\n"; display(bitAnd(a, b));
    cout << "a OR  b:\n"; display(bitOr(a, b));
    cout << "a XOR b:\n"; display(bitXor(a, b));
    cout << "NOT a:\n";   display(bitNot(a));
    cout << "\n";

    int m;
    cout << "Введите количество бит для сдвига: ";
    cin >> m;

    cout << "\n---- Сдвиги ----\n";
    cout << "a << n1:\n"; display(shiftLeft(a, m));
    cout << "a >> n1:\n"; display(shiftRight(a, m));
    cout << "\nСтрока результата (a << n1): " << toString(shiftLeft(a, m)) << "\n";

    return 0;
}



