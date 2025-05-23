#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

// === Загальний шаблон ===
template<typename T>
int searchLast(const T arr[], int size, const T& key) {
    int lastIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

// === Перевантаження для const char* ===
int searchLast(const char* arr[], int size, const char* key) {
    int lastIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (strcmp(arr[i], key) == 0) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

int main() {
    // === 1. Масив int з файлу ===
    cout << "\n=== ПОШУК У МАСИВІ З ФАЙЛУ (int) ===\n";
    int arrFromFile[5];
    ifstream fin("C:/Users/Maks/Desktop/Laba4/task1.txt");
    if (!fin) {
        cerr << "Помилка відкриття файлу!\n";
    } else {
        for (int i = 0; i < 5 && fin >> arrFromFile[i]; ++i);
        fin.close();

        cout << "Масив: ";
        for (int i = 0; i < 5; ++i) cout << arrFromFile[i] << " ";
        int key = arrFromFile[2];
        cout << "\nКлюч (3-й елемент): " << key << endl;
        cout << "Останній індекс: " << searchLast(arrFromFile, 5, key) << endl;
    }

    // === 2. Масив int з клавіатури ===
    cout << "\n=== ПОШУК У МАСИВІ З КЛАВІАТУРИ (int) ===\n";
    int arrInt[5];
    cout << "Введіть 5 цілих чисел: ";
    for (int i = 0; i < 5; ++i) cin >> arrInt[i];
    int keyInt;
    cout << "Введіть ключ для пошуку: ";
    cin >> keyInt;
    cout << "Масив: ";
    for (int i = 0; i < 5; ++i) cout << arrInt[i] << " ";
    cout << "\nОстанній індекс: " << searchLast(arrInt, 5, keyInt) << endl;

    // === 3. Масив double (випадкові значення) ===
    cout << "\n=== ПОШУК У ВИПАДКОВОМУ DOUBLE МАСИВІ ===\n";
    double arrDouble[5];
    srand(time(0));
    for (int i = 0; i < 5; ++i) {
        arrDouble[i] = rand() % 10 + 0.5;
        cout << arrDouble[i] << " ";
    }
    double keyDouble = arrDouble[2];
    cout << "\nКлюч (3-й елемент): " << keyDouble << endl;
    cout << "Останній індекс: " << searchLast(arrDouble, 5, keyDouble) << endl;

    // === 4. Масив рядків (char*) ===
    cout << "\n=== ПОШУК У МАСИВІ РЯДКІВ (char*) ===\n";
    const char* names[] = {"Ivan", "Olga", "Petro", "Ivan", "Sergiy"};
    const char* keyStr = "Ivan";
    cout << "Масив: ";
    for (int i = 0; i < 5; ++i) cout << names[i] << " ";
    cout << "\nКлюч: " << keyStr << endl;
    cout << "Останній індекс: " << searchLast(names, 5, keyStr) << endl;

    return 0;
}
