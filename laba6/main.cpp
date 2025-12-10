#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


class BaseObject {
public:
    virtual void read() = 0;
    virtual void display() const = 0;
    virtual string toString() const = 0;
    virtual ~BaseObject() {}
};


// Битовая строка до 100 бит
class BitString : public BaseObject {
private:
    unsigned char bits[100];
    int length;

public:
    BitString(int len = 100) {
        if (len > 100) len = 100;
        length = len;
        for (int i = 0; i < length; i++) bits[i] = 0;
    }


    // виртуальные методы
    void read() override {
        cout << "Введите битовую строку (0/1), длина = " << length << " бит:\n";
        for (int i = 0; i < length; i++) {
            char c;
            cin >> c;
            if (c == '0' || c == '1') bits[i] = c - '0';
            else {
                cout << "Неверный символ, принимается как 0\n";
                bits[i] = 0;
            }
        }
    }

    void display() const override {
        for (int i = 0; i < length; i++) cout << (int)bits[i];
        cout << endl;
    }

    string toString() const override {
        string s;
        s.reserve(length);
        for (int i = 0; i < length; i++) s += (bits[i] ? '1' : '0');
        return s;
    }
};


// PascalString 
class PascalString : public BaseObject {
private:
    unsigned char data[256];  // data[0] = длина
    int maxSize;

public:
    PascalString(int maxLen = 255) {
        if (maxLen > 255) maxLen = 255;
        maxSize = maxLen;
        data[0] = 0;
    }


    // виртуальные методы
    void read() override {
        cout << "Введите строку (макс " << maxSize << " символов):\n";
        string s;
        getline(cin >> ws, s);

        if ((int)s.size() > maxSize) s = s.substr(0, maxSize);

        data[0] = s.size();
        for (int i = 0; i < data[0]; i++) data[i + 1] = s[i];
    }

    void display() const override {
        for (int i = 1; i <= data[0]; i++) cout << data[i];
        cout << endl;
    }

    string toString() const override {
        string s;
        s.reserve(data[0]);
        for (int i = 1; i <= data[0]; i++) s += data[i];
        return s;
    }
};






int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    BaseObject* obj;

    cout << "|---| BitString \n";
    obj = new BitString(16);        // пример с длиной 16 бит
    obj->read();
    obj->display();
    cout << "toString(): " << obj->toString() << "\n\n";
    delete obj;

    cout << "|---| PascalString \n";
    obj = new PascalString(20);     // строка до 20 символов
    obj->read();
    obj->display();
    cout << "toString(): " << obj->toString() << "\n\n";
    delete obj;

    return 0;
}
