#include <iostream>
#include <random>
#include <vector>
#include <math.h>

using namespace std;

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
    vector<int> arr50(50);
    vector<int> arr100(100);
    vector<int> arr1000(1000);
    for (int i = 0; i < 50; ++i) {
        arr50[i] = 10 + generator() % 90;
    }
    for (int i = 0; i < 100; ++i) {
        arr100[i] = 10 + generator() % 90;
    }
    for (int i = 0; i < 1000; ++i) {
        arr1000[i] = 10 + generator() % 90;
    }

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