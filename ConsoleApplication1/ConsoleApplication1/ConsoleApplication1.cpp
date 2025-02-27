#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>

using namespace std;

// Функція для перевірки правильності вводу
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear(); // Очищуємо стан помилки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Пропускаємо неправильний ввід
            cout << "Error. Expected a valid real number." << endl;
        }
        else {
            return value;
        }
    }
}

