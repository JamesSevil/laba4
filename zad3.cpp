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

void Hypothesis(vector<int> nums) { // Проверка гипотезы
    float krit = 44.314;
    cout << "Для массива на " << nums.size() << " элементов: " << endl;
    float x = X2(nums, nums.size());
    cout << "x^2: " << x << endl;
    if (x < krit) {
        cout << "Гипотеза о нормальном распределении принимается." << endl << endl;
    } else {
        cout << "Гипотеза о нормальном распределении отклоняется." << endl << endl;
    }
}

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    // Генерирую числа для каждого массива
    vector<int> arr50 = GenerateVector(50);
    vector<int> arr100 = GenerateVector(100);
    vector<int> arr1000 = GenerateVector(1000);

    // Результаты проверки гипотезы
    Hypothesis(arr50);
    Hypothesis(arr100);
    Hypothesis(arr1000);

    return 0;
}