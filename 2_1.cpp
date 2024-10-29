#include <iostream>
#include <cstdlib> 
#include <ctime>  

using namespace std;

class SequentialSearch {
private:
    int comparisons;

public:
    SequentialSearch() : comparisons(0) {}

    int search(int arr[], int size, int x) {
        comparisons = 0; //обнуление счетчика
        for (int i = 0; i < size; ++i) {
            comparisons++;
            if (arr[i] == x) {
                return i;
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

    SequentialSearch seqSearch;
    int element;
    cout << "Введите число для поиска: ";
    cin >> element;

    int index = seqSearch.search(arr, size, element);

    if (index != -1) {
        cout << "Элемент найден на индексе " << index << endl;
    }
    else {
        cout << "Элемент не найден." << endl;
    }

    cout << "Число сравнений: " << seqSearch.getComparisons() << endl;

    return 0;
}
