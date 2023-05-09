#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
const int M = 5;
const int N = 4;

int main() {
    // Відкриваємо файл для зчитування
    ifstream file("F1.txt");

    // Перевіряємо, чи відкрився файл
    if (!file.is_open()) {
        cout << "Помилка відкриття файлу!\n";
        return 0;
    }

    // Зчитуємо матрицю з файлу
    vector<vector<double>> matrix;
    double num;
    while (file >> num) {
        if (matrix.empty() || matrix.back().size() > 0) {
            matrix.emplace_back();
        }
        matrix.back().push_back(num);
        if (file.peek() == '\n') {
            file.ignore();
        }
    }
////
    // Обчислюємо суму елементів з четних рядків
    double sum = 0.0;
    for (int i = 0; i < matrix.size(); i += 2) {
        for (int j = 0; j < matrix[i].size(); j++) {
            sum += matrix[i][j];
        }
    }
//....
    // Виводимо результат
    cout << "Сума елементів з четних рядків: " << sum << endl;

    // Закриваємо файл
    file.close();

    return 0;
}
