#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// === Шаблон класу масиву ===
template <typename T>
class Array {
    T* data;
    int size;

public:
    Array(int s = 0) : size(s) {
        data = (s > 0) ? new T[s] : nullptr;
    }

    ~Array() {
        delete[] data;
    }

    Array(const Array& other) {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    Array operator+(const Array& other) const {
        Array result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] + other.data[i];
        return result;
    }

    Array operator-(const Array& other) const {
        Array result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] - other.data[i];
        return result;
    }

    Array& operator+=(const Array& other) {
        for (int i = 0; i < size; ++i)
            data[i] += other.data[i];
        return *this;
    }

    Array& operator-=(const Array& other) {
        for (int i = 0; i < size; ++i)
            data[i] -= other.data[i];
        return *this;
    }

    void input() {
        for (int i = 0; i < size; ++i) {
            cout << "arr[" << i << "] = ";
            cin >> data[i];
        }
    }

    void randomFill(int min = 0, int max = 100) {
        for (int i = 0; i < size; ++i)
            data[i] = min + rand() % (max - min + 1);
    }

    bool fillFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cerr << "Не вдалося відкрити файл: " << filename << endl;
            return false;
        }
        for (int i = 0; i < size && fin >> data[i]; ++i);
        fin.close();
        return true;
    }

    void print() const {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    int getSize() const { return size; }
};

// === Демонстрація ===
int main() {
    srand(time(0));
    int n = 5;

    cout << "--- Масив A1 (int, введення з клавіатури) ---\n";
    Array<int> A1(n);
    A1.input();

    cout << "--- Масив A2 (int, випадкові значення) ---\n";
    Array<int> A2(n);
    A2.randomFill(1, 10);
    A2.print();

    Array<int> sum = A1 + A2;
    Array<int> diff = A1 - A2;

    cout << "--- Сума A1 + A2 ---\n";
    sum.print();

    cout << "--- Різниця A1 - A2 ---\n";
    diff.print();

    cout << "--- A1 після A1 += A2 ---\n";
    A1 += A2;
    A1.print();

    cout << "--- A2 після A2 -= A2 ---\n";
    A2 -= A2;
    A2.print();

    // === Зчитування з файлу ===
    cout << "\n--- Масив A3 (зчитано з файлу) ---\n";
    Array<int> A3(n);
    if (A3.fillFromFile("C:/Users/Maks/Desktop/Laba4/task3.txt")) {
        A3.print();
    }

    // === double тип ===
    cout << "\n--- Масив B1 (double, випадкові значення) ---\n";
    Array<double> B1(n);
    for (int i = 0; i < n; ++i)
        B1[i] = (rand() % 100) / 10.0;
    B1.print();

    return 0;
}
