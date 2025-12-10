#include <iostream>
#include <string>
#include <windows.h>
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

// ввод
void read(BitString& bs) {
	cout << "Введите старшие 32 бита (hex): ";
	cin >> hex >> bs.high;
	cout << "Введите младшие 32 бита (hex): ";
	cin >> hex >> bs.low;
}

// вывод
void display(const BitString& bs) {
	cout << "BitString: high = 0x" << hex << bs.high << ", low = 0x" << bs.low << dec << endl;
}

// преобразование в строку
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

// исключающее ИЛИ
BitString operator^(const BitString& lhs, const BitString& rhs) {
	return initBitString(lhs.high ^ rhs.high, lhs.low ^ rhs.low);
}

// НЕ
BitString operator~(const BitString& bs) {
	return initBitString(~bs.high, ~bs.low);
}

// сдвиг влево
BitString shiftLeft(const BitString& bs, int bits) {
	if (bits < 0) throw invalid_argument("Количество битов для сдвига должно быть неотрицательным");
	if (bits == 0) return bs;
	if (bits >= 64) return initBitString(0, 0); 
	
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

// сдвиг вправо
BitString shiftRight(const BitString& bs, int bits) {
	if (bits < 0) throw invalid_argument("Количество битов для сдвига должно быть неотрицательным");
	if (bits == 0) return bs;
	if (bits >= 64) return initBitString(0, 0); 

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

// вывод в двоичном формате
void printBinary(const BitString& bs) {
	// вывод старших 32 бит
	for (int i = 31; i >= 0; i--) {
		cout << ((bs.high >> i) & 1);
		if (i % 8 == 0) cout << " ";
	}

	// вывод младших 32 бит
	for (int i = 31; i >= 0; i--) {
		cout << ((bs.low >> i) & 1);
		if (i % 8 == 0) cout << " ";
	}
	cout << endl;
}



int main() {
	SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

	BitString bs1 = initBitString(0xFFFF0000, 0x0000FFFF);
	BitString bs2 = initBitString(0x0000FFFF, 0xFFFF0000);

	cout << "a: ";
	printBinary(bs1);
	display(bs1);

	cout << "\n\nb: ";
	printBinary(bs2);
	display(bs2);
	

	cout << "\na AND b: ";
	BitString andResult = bs1 & bs2;
	printBinary(andResult);
	cout << "Binary: ";
	display(andResult);
	
	cout << "\na OR b:  ";
	BitString orResult = bs1 | bs2;
	printBinary(orResult);
	cout << "Binary: ";
	display(orResult);
	
	cout << "\na XOR b: ";
	BitString xorResult = bs1 ^ bs2;
	printBinary(xorResult);
	cout << "Binary: ";
	display(xorResult);
	
	cout << "\nNOT a: ";
	BitString notResult = ~bs1;
	printBinary(notResult);
	cout << "Binary: ";
	display(notResult);
	
	cout << "\na << 8: ";
	BitString shiftLeftResult = shiftLeft(bs1, 8);
	printBinary(shiftLeftResult);
	cout << "Binary: ";
	display(shiftLeftResult);

	cout << "\na >> 8: ";
	BitString shiftRightResult = shiftRight(bs1, 8);
	printBinary(shiftRightResult);
	cout << "Binary: ";
	display(shiftRightResult);
	
	


	// ручной ввод
	BitString bs3;
	cout << "\n\nВведите битовую строку:" << endl;
	read(bs3);
	cout << "\nВы ввели: \n";
	display(bs3);
	cout << "Это: ";
	printBinary(bs3);
	cout << "Строковое представление: " << toString(bs3) << endl;

	cout << "Введите сдвиг влево: ";
    int shift;
    cin >> shift;
	BitString shiftLeftResultBS3 = shiftLeft(bs3, shift);
    cout << "После сдвига: \n";
	cout << "Это: ";
	printBinary(shiftLeftResultBS3);
	cout << endl;
	display(shiftLeftResultBS3);

	return 0;
}
