/*#include <iostream>
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

// Функція для неінтерактивного режиму
void fileMode() {
    ifstream file;
    // Шлях до файлу вказано явно
    file.open("C:\\Users\\Wandestes\\source\\repos\\ConsoleApplication1\\x64\\Debug\\Test.txt");

    if (!file) {
        cout << "File does not exist or cannot be opened." << endl;
        exit(1);
    }

    double a, b, c;
    file >> a >> b >> c;
    if (file.fail() || !file.eof()) {
        cout << "Invalid file format" << endl;
        exit(1);
    }

    solveEquation(a, b, c);
}

// Головна функція з вибором режиму
int main() {
    int choice;
    cout << "Select mode:" << endl;
    cout << "1. Interactive mode" << endl;
    cout << "2. File mode" << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        interactiveMode();
    }
    else if (choice == 2) {
        fileMode();
    }
    else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Функція для обчислення та виведення коренів
void solveQuadraticEquation(double a, double b, double c) {
    cout << "Equation is: (" << a << ") x^2 + (" << b << ") x + (" << c << ") = 0\n";
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "There are 2 roots\n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
    else if (discriminant == 0) {
        double x = -b / (2 * a);
        cout << "There are 1 roots\n";
        cout << "x1 = " << x << "\n";
    }
    else {
        cout << "There are 0 roots\n";
    }
}

// Функція для файлового режиму
void fileMode(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "file " << filePath << " does not exist\n";
        exit(1);
    }

    double a, b, c;
    file >> a >> b >> c;
    if (file.fail() || !file.eof()) {
        cout << "Invalid file format\n";
        exit(1);
    }
    if (a == 0) {
        cout << "Error. a cannot be 0\n";
        exit(1);
    }

    solveQuadraticEquation(a, b, c);
}

// Функція для інтерактивного режиму
void interactiveMode() {
    double a, b, c;

    cout << "a = ";
    while (!(cin >> a) || a == 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Expected a valid real number, got invalid value\n";
        cout << "a = ";
    }

    cout << "b = ";
    while (!(cin >> b)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Expected a valid real number, got invalid value\n";
        cout << "b = ";
    }

    cout << "c = ";
    while (!(cin >> c)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Expected a valid real number, got invalid value\n";
        cout << "c = ";
    }

    solveQuadraticEquation(a, b, c);
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        // Якщо вказано шлях до файлу в командному рядку
        string filePath = argv[1];
        fileMode(filePath);
    }
    else {
        // Якщо не вказано аргументів, пропонуємо вибір режиму
        int choice;
        cout << "Select mode:\n";
        cout << "1. Interactive mode\n";
        cout << "2. File mode\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            interactiveMode();
        }
        else if (choice == 2) {
            string filePath;
            cout << "Enter file path: ";
            cin >> filePath;
            fileMode(filePath);
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
