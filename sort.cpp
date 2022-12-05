#include <iostream>


template <typename T>
void bubbleSort(T array[], int size) {
    // цикл для доступа к каждому элементу массива
    for (int step = 0; step < size; ++step) {

        // цикл для сравнения элементов массива
        for (int i = 0; i < size - step - 1; ++i) {

            // сравнение соседних элементов
            if (array[i] > array[i + 1]) {

                // меняем элементы массива местами, если не соответствуют нужному порядку
                T temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

template <typename T>
void selectionSort(T* arr, int size) {
    for (int i = 0; i < size; ++i) {
        // берем за минимальный элемент по текущему индексу i
        T mint = arr[i];
        int minIndex = i;
        // находим минимальный элемент в неотсортированной части массива
        for (int j = i; j < size; ++ j) {
            if (arr[j] < mint) {
                mint = arr[j];
                minIndex = j;
            }
        }
        // меняем текущий элемент и минимальный элемент неотсортированной части массива местами
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

template <typename T>
void insertionSort(T* arr, int size) {
    //цикл для доступа к каждому элементу массива
    for (int i = 0; i < size; ++i) {
        int x = i;
        //находим место для вставки элемента (пока элемент меньше предыдущего меняем их местами и уменьшаем индекс на 1)
        while (x > 0 && arr[x] < arr[x-1]) {
            T temp = arr[x];
            arr[x] = arr[x-1];
            arr[x-1] = temp;
            x--;
        }
    }
}

// функция для вывода итогового массива
template <typename T>
void printArray(T* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "  " << array[i];
    }
    std::cout << "\n" << std::endl;
}

int main() {

    // программа работает для массива любой длины, поэтому вводим длину массива
    std::cout << "input the length of array number 1" << std::endl;
    int length1;
    std::cin >> length1;

    // вводим массив
    std::cout << "input array number 1" << std::endl;
    auto *arr1 = new double[length1];
    for (size_t i = 0; i < length1; ++i) {
        std::cin >> arr1[i];
    }

    // вызываем бабл сортировку
    bubbleSort(arr1, length1);

    std::cout << "sorted array in ascending order:\n";
    printArray(arr1, length1);


    // программа работает для массива любой длины, поэтому вводим длину массива
    std::cout << "input the length of array number 2" << std::endl;
    int length2;
    std::cin >> length2;

    // вводим массив
    std::cout << "input array number 2" << std::endl;
    auto *arr2 = new double[length2];
    for (size_t i = 0; i < length2; ++i) {
        std::cin >> arr2[i];
    }
    // вызываем селекшн сортировку
    selectionSort(arr2, length2);

    std::cout << "sorted array in ascending order:\n";
    printArray(arr2, length2);


    // программа работает для массива любой длины, поэтому вводим длину массива
    std::cout << "input the length of array number 3" << std::endl;
    int length3;
    std::cin >> length3;

    // вводим массив
    std::cout << "input array number 3" << std::endl;
    auto *arr3 = new double[length3];
    for (size_t i = 0; i < length3; ++i) {
        std::cin >> arr3[i];
    }
    // вызываем инсершн сортировку
    insertionSort(arr3, length3);

    std::cout << "sorted array in ascending order:\n";
    printArray(arr3, length3);

    return 0;
}
