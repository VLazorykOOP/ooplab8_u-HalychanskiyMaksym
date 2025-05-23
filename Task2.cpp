#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm> // для std::swap
using namespace std;

// === Шаблонна функція швидкого сортування ===
template <typename T>
void quickSort(T arr[], int left, int right) {
    if (left >= right) return;
    T pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

// === Перевантаження для char* ===
void quickSort(char* arr[], int left, int right) {
    if (left >= right) return;
    char* pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (strcmp(arr[i], pivot) < 0) i++;
        while (strcmp(arr[j], pivot) > 0) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

// === Вивід масиву ===
template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;
}

void printArray(char* arr[], int size) {
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // === 1. Ввід з клавіатури (int) ===
    cout << "\n=== Сортування int з клавіатури ===\n";
    int arrInt[5];
    cout << "Введіть 5 чисел: ";
    for (int i = 0; i < 5; ++i) cin >> arrInt[i];
    quickSort(arrInt, 0, 4);
    cout << "Відсортовано: ";
    printArray(arrInt, 5);

    // === 2. Випадкові числа (double) ===
    cout << "\n=== Сортування випадкових double ===\n";
    double arrDouble[5];
    srand(time(0));
    for (int i = 0; i < 5; ++i)
        arrDouble[i] = rand() % 100 + 0.5;
    cout << "До: ";
    printArray(arrDouble, 5);
    quickSort(arrDouble, 0, 4);
    cout << "Після: ";
    printArray(arrDouble, 5);

    // === 3. Зчитування з файлу (int) ===
    cout << "\n=== Сортування int з файлу ===\n";
    int arrFile[5];
    ifstream fin("C:/Users/Maks/Desktop/Laba4/task2.txt");
    if (!fin) {
        cerr << "Не вдалося відкрити файл!\n";
    } else {
        for (int i = 0; i < 5 && fin >> arrFile[i]; ++i);
        fin.close();
        cout << "До: ";
        printArray(arrFile, 5);
        quickSort(arrFile, 0, 4);
        cout << "Після: ";
        printArray(arrFile, 5);
    }

    // === 4. Масив рядків (char*) ===
    cout << "\n=== Сортування рядків (char*) ===\n";
    char* names[] = { (char*)"Petro", (char*)"Ivan", (char*)"Olga", (char*)"Sergiy", (char*)"Anna" };
    cout << "До: ";
    printArray(names, 5);
    quickSort(names, 0, 4);
    cout << "Після: ";
    printArray(names, 5);

    return 0;
}
