#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

// === Базовый класс Pair ===
class Pair {
protected:
 double first;
 double second;

public:
 // Конструкторы
 Pair(double a = 0, double b = 0) {
  if (!isfinite(a) || !isfinite(b)) {
   cerr << "Ошибка: недопустимые значения для Pair!" << endl;
   exit(1);
  }
  first = a;
  second = b;
 }

 // Методы доступа
 double getFirst() const { return first; }
 double getSecond() const { return second; }

 void setFirst(double a) {
  if (!isfinite(a)) {
   cerr << "Ошибка: недопустимое значение first!" << endl;
   exit(1);
  }
  first = a;
 }

 void setSecond(double b) {
  if (!isfinite(b)) {
   cerr << "Ошибка: недопустимое значение second!" << endl;
   exit(1);
  }
  second = b;
 }

 // Метод перемножения
 double multiply() const {
  return first * second;
 }

 // Операция сложения пар (a, b) + (c, d) = (a + b, c + d)
 Pair operator+(const Pair& other) const {
  return Pair(first + second, other.first + other.second);
 }

 // Преобразование в строку
 virtual string toString() const {
  ostringstream oss;
  oss << "(" << first << ", " << second << ")";
  return oss.str();
 }

 // Виртуальный деструктор
 virtual ~Pair() {}
};

// === Производный класс Complex ===
class Complex : public Pair {
public:
 // Конструктор
 Complex(double real = 0, double imag = 0) : Pair(real, imag) {}

 double getReal() const { return first; }
 double getImag() const { return second; }

 void setReal(double r) { setFirst(r); }
 void setImag(double i) { setSecond(i); }

 // Умножение комплексных чисел: (a, b) * (c, d) = (ac - bd, ad + bc)
 Complex operator*(const Complex& other) const {
  double a = first, b = second;
  double c = other.first, d = other.second;
  return Complex(a * c - b * d, a * d + b * c);
 }

 // Вычитание: (a, b) - (c, d) = (a - c, b - d)
 Complex operator-(const Complex& other) const {
  return Complex(first - other.first, second - other.second);
 }

 // Переопределение toString()
 string toString() const override {
  ostringstream oss;
  oss << first;
  if (second >= 0) oss << "+";
  oss << second << "i";
  return oss.str();
 }
};

// === Главная функция ===
int main() {
 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    // Создание объектов
    Pair p1(2, 3);
    Pair p2(4, 5);

    cout << "p1 = " << p1.toString() << endl;
    cout << "p2 = " << p2.toString() << endl;

    Pair p3 = p1 + p2;
    cout << "p1 + p2 = " << p3.toString() << endl;
    cout << "p1.multiply() = " << p1.multiply() << endl;

    // Работа с комплексными числами
    Complex c1(2, 3);
    Complex c2(1, -4);

    cout << "\nc1 = " << c1.toString() << endl;
    cout << "c2 = " << c2.toString() << endl;

    Complex c3 = c1 * c2;
    cout << "c1 * c2 = " << c3.toString() << endl;

    Complex c4 = c1 - c2;
    cout << "c1 - c2 = " << c4.toString() << endl;

    // Массив объектов
    vector<Complex> arr = { Complex(1, 1), Complex(2, -1), Complex(0, 3) };
    cout << "\nМассив комплексных чисел:" << endl;
    for (auto& c : arr) {
    cout << "  " << c.toString() << endl;
    }

    // Принцип подстановки (базовый указатель на производный объект)
    Pair* ptr = new Complex(5, -2);
    cout << "\nПринцип подстановки (Pair* -> Complex): "
    << ptr->toString() << endl;
    delete ptr;

    return 0;
}
