// Задание вариант 10 (Вариант алгоритма 10 (random_device))
#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> Generate_Vector(int n) { // ф-ия заполнения массива рандомными числами
    random_device generator;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int randnums = 10 + generator() % 90;
        nums.push_back(randnums);
    }
    return nums;
}

int find_mins(vector<int> nums, int& min1, int& min2) { // ф-ия нахождения 2 мин.чисел и суммы отсатков при / эл.массива на мин.число
    for (auto randnums : nums) {
        if (randnums < min1) { // нахожу 2 минимальных
            min2 = min1;
            min1 = randnums;
        } else if (randnums < min2 && randnums != min1) {
            min2 = randnums;
        }
    }
    int sumost = 0;
    for (auto elem : nums) {
        sumost += (elem % min1);
    }
    return sumost;
}

vector<int> FindLongSeq(vector<int> nums) { // ф-ия нахождения самой длинной последовательность массива
    vector<int> LongSeq;
    vector<int> CurrentSeq;
    for(int i = 0; i < nums.size(); ++i) {
        if (CurrentSeq.empty() || nums[i] > CurrentSeq.back()) {
            CurrentSeq.push_back(nums[i]);
        } else {
            if (CurrentSeq.size() > LongSeq.size()) {
                LongSeq = CurrentSeq;
            }
            CurrentSeq.clear();
            CurrentSeq.push_back(nums[i]);
        }
    }
    if (CurrentSeq.size() > LongSeq.size()) {
        LongSeq = CurrentSeq;
    }
    return LongSeq;
}

void matrix(int n) { // Ф-ия заполнения массива и его вывод по n кол-ву столбцов
    cout << "Массив: " << endl;
    n *= 8;
    int count = 2;
    vector<int> nums3(n);
    nums3[0] = 2000;
    cout << nums3[0] << " ";
    for (int i = 1; i < n; ++i) {
        nums3[i] = nums3[i-1] + 10;
        cout << nums3[i] << " ";
        if (count % 8 == 0) {
            cout << endl;
        }
        count++;
    }
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) { // перегрузка вывода вектора
    for (const auto& element : vec) {
        os << element << " ";
    }
    return os;
}


int main(){
    srand(time(0));
    setlocale(LC_ALL, "Rus");
    random_device generator;
    
    // Блок 1
    int n = 0;
    while (n > 10 || n <= 0) {
        cout << "1. Введите размерность массива рандомных чисел(не больше 10): ";
        cin >> n;
    }
    vector<int> nums = Generate_Vector(n);
    cout << "Вектор рандомных чисел: " << nums << endl << endl;

    // Блок 2
    int min1 = 1000, min2 = 1000;
    int sumost = find_mins(nums, min1, min2);
    cout << "2. Минимальные числа: " << min1 << " " << min2 << endl << "Сумма остатков: " << sumost << endl << endl;

    // Блок 3
    n = 0;
    while (n > 10 || n <= 0) {
        cout << "3. Введите размерность массива чисел(не больше 10): ";
        cin >> n;
    }
    vector<int> nums2(n);
    cout << "Введите массив чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }
    vector<int> LongSeq = FindLongSeq(nums2); // ф-ия нахождения самой длинной последовательности массива
    cout << "Самая длинная последовательность массива: ";
    for (int i : LongSeq) {
        cout << i << " ";
    }
    cout << endl << endl;;

    // Блок 4
    n = 0;
    while(n <= 0 || n > 10) {
        cout << "4. Введите кол-во столбцов в массиве(Не больше 10): ";
        cin >> n;
    }
    matrix(n);

    return 0;
}