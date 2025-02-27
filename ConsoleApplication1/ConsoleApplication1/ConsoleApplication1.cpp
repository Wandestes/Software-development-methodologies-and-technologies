﻿#include <iostream>
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

// Функція для обчислення коренів
void solveEquation(double a, double b, double c) {
    cout << "Equation is: (" << a << ") x^2 + (" << b << ") x + (" << c << ") = 0" << endl;

    if (a == 0) {
        cout << "Error. a cannot be 0" << endl;
        return;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "There are 2 roots" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (discriminant == 0) {
        double x = -b / (2 * a);
        cout << "There are 1 roots" << endl;
        cout << "x1 = " << x << endl;
    }
    else {
        cout << "There are 0 roots" << endl;
    }
}

// Функція для інтерактивного режиму
void interactiveMode() {
    double a = getValidInput("a = ");
    double b = getValidInput("b = ");
    double c = getValidInput("c = ");
    solveEquation(a, b, c);
}
