#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;

class PrimeChecker {
public:
    // Перебор от 2 до N
    bool isPrimeBasic(int n, int& opCount) {
        opCount = 0;
        if (n < 2) return false;
        for (int i = 2; i < n; ++i) {
            opCount++;  // Считаем каждую проверку
            if (n % i == 0) return false;
        }
        return true;
    }

    // Перебор с учётом чётных и нечетных чисел
    bool isPrimeEven(int n, int& opCount) {
        opCount = 0;
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) {
            opCount++;  // Проверка на чётность
            return false;
        }
        for (int i = 3; i < n; i += 2) {
            opCount++;  // Считаем каждую проверку делимости
            if (n % i == 0) return false;
        }
        return true;
    }

    // Перебор до sqrt(N)
    bool isPrimeSqrt(int n, int& opCount) {
        opCount = 0;
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); ++i) {
            opCount++;  // Считаем каждую проверку
            if (n % i == 0) return false;
        }
        return true;
    }

    // Перебор нечетных чисел до sqrt(N)
    bool isPrimeOdd(int n, int& opCount) {
        opCount = 0;
        if (n == 2) return true;
        if (n < 2 || n % 2 == 0) {
            opCount++;  // Проверка на делимость на 2
            return false;
        }
        for (int i = 3; i <= sqrt(n); i += 2) {
            opCount++;  // Считаем каждую проверку
            if (n % i == 0) return false;
        }
        return true;
    }
};

class Experiment {
public:
    void runPrimeExperiments(const vector<int>& numbers) {
        PrimeChecker primeChecker;

        cout << setw(10) << "N"
            << setw(25) << "Время (базовый)"
            << setw(20) << "Операции (базовый)"
            << setw(25) << "Время (чётные)"
            << setw(20) << "Операции (чётные)"
            << setw(25) << "Время (sqrt)"
            << setw(20) << "Операции (sqrt)"
            << setw(25) << "Время (нечётные)"
            << setw(20) << "Операции (нечётные)" << endl;

        for (int n : numbers) {
            int opCountBasic = 0, opCountEven = 0, opCountSqrt = 0, opCountOdd = 0;

            auto startTime = chrono::high_resolution_clock::now();
            primeChecker.isPrimeBasic(n, opCountBasic);
            auto endTime = chrono::high_resolution_clock::now();
            double timeBasic = chrono::duration<double>(endTime - startTime).count();

            startTime = chrono::high_resolution_clock::now();
            primeChecker.isPrimeEven(n, opCountEven);
            endTime = chrono::high_resolution_clock::now();
            double timeEven = chrono::duration<double>(endTime - startTime).count();

            startTime = chrono::high_resolution_clock::now();
            primeChecker.isPrimeSqrt(n, opCountSqrt);
            endTime = chrono::high_resolution_clock::now();
            double timeSqrt = chrono::duration<double>(endTime - startTime).count();

            startTime = chrono::high_resolution_clock::now();
            primeChecker.isPrimeOdd(n, opCountOdd);
            endTime = chrono::high_resolution_clock::now();
            double timeOdd = chrono::duration<double>(endTime - startTime).count();

            cout << setw(10) << n
                << setw(25) << fixed << setprecision(10) << timeBasic
                << setw(20) << opCountBasic
                << setw(25) << timeEven
                << setw(20) << opCountEven
                << setw(25) << timeSqrt
                << setw(20) << opCountSqrt
                << setw(25) << timeOdd
                << setw(20) << opCountOdd << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Experiment experiment;

    cout << "Эксперименты по проверке числа на простоту:" << endl;

    // Используем список чисел, среди которых есть простые и составные
    vector<int> numbers = { 997, 1009, 1013, 2003, 3001, 4003, 5003, 6007, 7001, 8009, 9001, 10007 };

    experiment.runPrimeExperiments(numbers);

    return 0;
}
