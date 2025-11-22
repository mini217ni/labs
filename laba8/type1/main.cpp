#include <iostream>
#include <set> // для хранения уникальных элементов

// Шаблонная функция для подсчёта количества уникальных элементов
template <typename T>
int countUnique(const T* arr, int size) {
    std::set<T> uniqueElements; // контейнер, автоматически хранит только уникальные значения

    for (int i = 0; i < size; ++i) {
        uniqueElements.insert(arr[i]);
    }

    return uniqueElements.size();
}

int main() {
    // Пример с целыми числами
    int intArray[] = {1, 2, 3, 2, 4, 1, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Количество уникальных элементов (int): "
              << countUnique(intArray, intSize) << std::endl;

    // Пример с вещественными числами
    double doubleArray[] = {1.1, 2.2, 3.3, 2.2, 1.1};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Количество уникальных элементов (double): "
              << countUnique(doubleArray, doubleSize) << std::endl;

    // Пример со строками
    std::string strArray[] = {"apple", "banana", "apple", "cherry", "banana"};
    int strSize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Количество уникальных элементов (string): "
              << countUnique(strArray, strSize) << std::endl;

    return 0;
}