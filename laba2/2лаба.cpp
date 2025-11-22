#include <iostream>
#include <stdexcept>
using namespace std;

struct BitString {
	unsigned long high; // старшие 32 бита
	unsigned long low;  // младшие 32 бита
};



BitString initBitString(unsigned long h = 0, unsigned long l = 0) {
	BitString bs;
	bs.high = h;
	bs.low = l;
	return bs;
}

// Ввод
void read(BitString& bs) {
	cout << "Введите старшие 32 бита (hex): ";
	cin >> hex >> bs.high;
	cout << "Введите младшие 32 бита (hex): ";
	cin >> hex >> bs.low;
}

// Вывод
void display(const BitString& bs) {
	cout << "BitString: high = 0x" << hex << bs.high << ", low = 0x" << bs.low << dec << endl;
}

// Преобразование в строку
string toString(const BitString& bs) {
	return "BitString: high = 0x" + to_string(bs.high) + ", low = 0x" + to_string(bs.low);
}

// И
BitString operator&(const BitString& lhs, const BitString& rhs) {
	return initBitString(lhs.high & rhs.high, lhs.low & rhs.low);
}

// ИЛИ
BitString operator|(const BitString& lhs, const BitString& rhs) {
	return initBitString(lhs.high | rhs.high, lhs.low | rhs.low);
}

// Исключающее ИЛИ
BitString operator^(const BitString& lhs, const BitString& rhs) {
	return initBitString(lhs.high ^ rhs.high, lhs.low ^ rhs.low);
}

// НЕ
BitString operator~(const BitString& bs) {
	return initBitString(~bs.high, ~bs.low);
}

// Сдвиг влево
BitString shiftLeft(const BitString& bs, int bits) {
	if (bits < 0) {
		throw invalid_argument("Количество битов для сдвига должно быть неотрицательным");
	}

	if (bits == 0) {
		return bs;
	}

	if (bits >= 64) {
		return initBitString(0, 0); 
	}

	if (bits < 32) {
		unsigned long newHigh = (bs.high << bits) | (bs.low >> (32 - bits));
		unsigned long newLow = bs.low << bits;
		return initBitString(newHigh, newLow);
	}
	else {
		unsigned long newHigh = bs.low << (bits - 32);
		unsigned long newLow = 0;
		return initBitString(newHigh, newLow);
	}
}

// Сдвиг вправо
BitString shiftRight(const BitString& bs, int bits) {
	if (bits < 0) {
		throw invalid_argument("Количество битов для сдвига должно быть неотрицательным");
	}

	if (bits == 0) {
		return bs;
	}

	if (bits >= 64) {
		return initBitString(0, 0); 
	}

	if (bits < 32) {
		unsigned long newLow = (bs.low >> bits) | (bs.high << (32 - bits));
		unsigned long newHigh = bs.high >> bits;
		return initBitString(newHigh, newLow);
	}
	else {
		unsigned long newLow = bs.high >> (bits - 32);
		unsigned long newHigh = 0;
		return initBitString(newHigh, newLow);
	}
}

// Вывод в двоичном формате
void printBinary(const BitString& bs) {
	// Вывод старших 32 бит
	for (int i = 31; i >= 0; i--) {
		cout << ((bs.high >> i) & 1);
		if (i % 8 == 0) cout << " ";
	}

	// Вывод младших 32 бит
	for (int i = 31; i >= 0; i--) {
		cout << ((bs.low >> i) & 1);
		if (i % 8 == 0) cout << " ";
	}
	cout << endl;
}

// Пример использования
int main() {
	BitString bs1 = initBitString(0xFFFF0000, 0x0000FFFF);
	BitString bs2 = initBitString(0x0000FFFF, 0xFFFF0000);

	cout << "BitString 1: ";
	display(bs1);
	cout << "Binary: ";
	printBinary(bs1);

	cout << "\n\nBitString 2: ";
	display(bs2);
	cout << "Binary: ";
	printBinary(bs2);

	cout << "\nAND: ";
	BitString andResult = bs1 & bs2;
	display(andResult);
	cout << "Binary: ";
	printBinary(andResult);

	cout << "\nOR:  ";
	BitString orResult = bs1 | bs2;
	display(orResult);
	cout << "Binary: ";
	printBinary(orResult);

	cout << "\nXOR: ";
	BitString xorResult = bs1 ^ bs2;
	display(xorResult);
	cout << "Binary: ";
	printBinary(xorResult);

	cout << "\nNOT bs1: ";
	BitString notResult = ~bs1;
	display(notResult);
	cout << "Binary: ";
	printBinary(notResult);

	cout << "\nСДВИГ ВЛЕВО на 8: ";
	BitString shiftLeftResult = shiftLeft(bs1, 8);
	display(shiftLeftResult);
	cout << "Binary: ";
	printBinary(shiftLeftResult);

	cout << "\nСДВИГ ВПРАВО на 8: ";
	BitString shiftRightResult = shiftRight(bs1, 8);
	display(shiftRightResult);
	cout << "Binary: ";
	printBinary(shiftRightResult);



	// Демонстрация ввода с клавиатуры
	BitString bs3;
	cout << "\n\nВведите BitString 3:" << endl;
	read(bs3);
	cout << "Вы ввели: \n";
	display(bs3);
	cout << "Это: \n";
	printBinary(bs3);
	cout << "Строковое представление: " << toString(bs3) << endl;

	return 0;
}