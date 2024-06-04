#include <iostream>
#include <random>
#include <vector>
#include <math.h>

using namespace std;

vector<int> GenerateVector(int n) { // ф-ия заполнения массива рандомными числами
    random_device generator;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int randnums = 10 + generator() % 90;
        nums.push_back(randnums);
    }
    return nums;
}

float X2(vector<int> arr, int n) {
    const int iter = 25;
    int sum[iter] = { 0 };
    int mat = 0;
    for (int i = 0; i < n; ++i) { // делим интервалы и подсчитываем значения в них
        sum[arr[i] * iter / 101]++;
        mat += arr[i];
    }
    float x = 0;
    cout << "Кол-во i элементов в 25 интервалах" << endl;
    for (int i : sum) {
        cout << i << " ";
        x += float((i - (n/iter)) * (i-(n/iter))) / (n / iter); // xi^2
    }
    cout << endl << "Мат. ожидание 50,5, реальность: " << mat/n << endl;
    return x;
}

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    random_device generator;

    // Генерирую числа для каждого массива
    vector<int> arr50 = GenerateVector(50);
    vector<int> arr100 = GenerateVector(100);
    vector<int> arr1000 = GenerateVector(1000);

    // Результаты проверки гипотезы
    float krit = 44.314;
    cout << "Для массива на 50 элементов: " << endl;
    float x = X2(arr50, 50);
    cout << "x^2: " << x << endl;
    if (x < krit) {
        cout << "Гипотеза о нормальном распределении принимается." << endl;
    } else {
        cout << "Гипотеза о нормальном распределении отклоняется." << endl;
    }

    cout << "Для массива на 100 элементов: " << endl;
    x = X2(arr100, 50);
    cout << "x^2: " << x << endl;
    if (x < krit) {
        cout << "Гипотеза о нормальном распределении принимается." << endl;
    } else {
        cout << "Гипотеза о нормальном распределении отклоняется." << endl;
    }

    cout << "Для массива на 1000 элементов: " << endl;
    x = X2(arr1000, 50);
    cout << "x^2: " << x << endl;
    if (x < krit) {
        cout << "Гипотеза о нормальном распределении принимается." << endl;
    } else {
        cout << "Гипотеза о нормальном распределении отклоняется." << endl;
    }

    return 0;
}