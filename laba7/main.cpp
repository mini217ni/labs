#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Структура прямой
struct Line {
    double A, B, C;
};

// === Варианты собственных исключений ===

// 1. Пустой класс
class MyExceptionEmpty {};

// 2. Класс с полями
class MyExceptionWithFields {
public:
    string message;
    double A1, B1, A2, B2;
    MyExceptionWithFields(string msg, double a1, double b1, double a2, double b2)
        : message(msg), A1(a1), B1(b1), A2(a2), B2(b2) {}
};

// 3. Наследник от стандартного исключения
class MyExceptionInherited : public runtime_error {
public:
    double A1, B1, A2, B2;
    MyExceptionInherited(string msg, double a1, double b1, double a2, double b2)
        : runtime_error(msg), A1(a1), B1(b1), A2(a2), B2(b2) {}
};

// === 1. Без спецификации исключений ===
bool areLinesIndependent(Line l1, Line l2) {
    double d = l1.A * l2.B - l2.A * l1.B;
    if (d == 0)
        throw invalid_argument("Прямые не существуют (совпадают или параллельны)");
    return true;
}

// === 2. Со спецификацией throw() ===
bool areLinesIndependentThrow(Line l1, Line l2) throw(invalid_argument) {
    double d = l1.A * l2.B - l2.A * l1.B;
    if (d == 0)
        throw invalid_argument("Прямые не существуют (совпадают или параллельны)");
    return true;
}

// === 3. С конкретной спецификацией (стандартное исключение) ===
bool areLinesIndependentStd(Line l1, Line l2) throw(runtime_error) {
    double d = l1.A * l2.B - l2.A * l1.B;
    if (d == 0)
        throw runtime_error("Прямые не существуют (runtime_error)");
    return true;
}

// === 4. С собственным исключением ===
bool areLinesIndependentCustom(Line l1, Line l2) throw(MyExceptionInherited) {
    double d = l1.A * l2.B - l2.A * l1.B;
    if (d == 0)
        throw MyExceptionInherited("Собственное исключение: прямые не существуют", l1.A, l1.B, l2.A, l2.B);
    return true;
}

// === Главная функция для демонстрации ===
int main() {
    setlocale(LC_ALL, "Russian");

    Line l1 = {1, 2, 3};
    Line l2 = {2, 4, 6}; // Параллельные прямые → d = 0

    try {
        cout << "=== Проверка без спецификации ===" << endl;
        areLinesIndependent(l1, l2);
        cout << "Прямые существуют!\n";
    } catch (const exception &e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    try {
        cout << "\n=== Проверка с собственной спецификацией ===" << endl;
        areLinesIndependentCustom(l1, l2);
        cout << "Прямые существуют!\n";
    } catch (const MyExceptionInherited &e) {
        cerr << "Исключение: " << e.what()
             << "\nПараметры: (" << e.A1 << ", " << e.B1
             << ") и (" << e.A2 << ", " << e.B2 << ")\n";
    }

    cout << "\nПрограмма завершена корректно.\n";
    return 0;
}