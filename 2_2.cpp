#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BinarySearch {
private:
    int comparisons;

public:
    BinarySearch() : comparisons(0) {}

    void sort(int arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    int search(int arr[], int size, int x) {
        comparisons = 0; 
        int left = 0, right = size - 1;

        while (left <= right) {
            comparisons++;
            int middle = left + (right - left) / 2;

            if (arr[middle] == x) {
                return middle;
            }

            if (arr[middle] < x) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return -1; 
    }

    int getComparisons() const {
        return comparisons;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    const int size = 100;
    int arr[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 30 + 1;
    }

    BinarySearch binSearch;
    binSearch.sort(arr, size);

    int element;
    cout << "Введите число для поиска: ";
    cin >> element;

    int index = binSearch.search(arr, size, element);

    if (index != -1) {
        cout << "Элемент найден на индексе " << index << endl;
    }
    else {
        cout << "Элемент не найден." << endl;
    }

    cout << "Число сравнений: " << binSearch.getComparisons() << endl;

    return 0;
}
