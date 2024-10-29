#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberComparisons {
private:
    const int max_size = 100000;
    int k, last_x;

public:
    NumberComparisons() : k(100), last_x(0) {}

    void initializeArray(int arr[], int size) {
        arr[0] = 1000 + rand() % 9000;
        for (int i = 1; i < size; i++) {
            int x = arr[i - 1] + rand() % 100 + 1;
            arr[i] = x;
            last_x = x;
        }
    }

    void generate(int arr[], int& size) {
        if (size < max_size) {
            for (int i = 0; i < k && size < max_size; i++) {
                int x = last_x + rand() % 100 + 1;
                arr[size] = x;
                size++;
                last_x = x;
            }
        }
    }

    int sequential_search(int arr[], int size, int x, int& difficulty) {
        for (int i = 0; i < size; i++) {
            difficulty++;
            if (x == arr[i]) {
                return i;
            }
        }
        return -1;
    }

    int binary_search(int arr[], int size, int x, int& difficulty) {
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int pos = (left + right) / 2;
            difficulty++;
            if (x == arr[pos]) {
                return pos;
            }
            if (x > arr[pos]) {
                left = pos + 1;
            }
            else {
                right = pos - 1;
            }
        }
        return -1;
    }

    void twist_search(int arr[], int& size) {
        cout << "Размер массива\tИскомое число\tИндекс послед. поиска\tИндекс двоичного поиска\tПракт. сложн. посл. поиска\tПракт. сложн. двоич. поиска" << endl;

        while (size <= 10000) {
            int diffic_one = 0, diffic_two = 0;
            int x = 500 + rand() % 14501;

            int seq_result = sequential_search(arr, size, x, diffic_one);
            int bin_result = binary_search(arr, size, x, diffic_two);

            cout << size << "\t\t"
                << x << "\t\t"
                << seq_result << "\t\t\t"
                << bin_result << "\t\t\t"
                << diffic_one << "\t\t\t"
                << diffic_two << endl;

            generate(arr, size);
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));
    const int max_size = 10000;
    int arr[max_size];
    int size = 100;

    NumberComparisons test;
    test.initializeArray(arr, size);
    test.twist_search(arr, size);

    return 0;
}
