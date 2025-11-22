#include <iostream>

// Шаблонная функция для подсчёта количества уникальных элементов
template <typename T>
int countUnique(const T* arr, int size) {
    int uniqueCount = 0;

    for (int i = 0; i < size; ++i) {
        bool isUnique = true;

        // Проверяем, встречался ли элемент ранее
        for (int j = 0; j < i; ++j) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
            uniqueCount++;
    }

    return uniqueCount;
}

int main() {
    int intArray[] = {1, 2, 3, 2, 4, 1, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Количество уникальных элементов (int): "
              << countUnique(intArray, intSize) << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 2.2, 1.1};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Количество уникальных элементов (double): "
              << countUnique(doubleArray, doubleSize) << std::endl;

    std::string strArray[] = {"apple", "banana", "apple", "cherry", "banana"};
    int strSize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Количество уникальных элементов (string): "
              << countUnique(strArray, strSize) << std::endl;

    return 0;
}