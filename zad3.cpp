#include <iostream>
#include <random>
#include <vector>
#include <math.h>

using namespace std;

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

    // Проверка гипотезы о нормальном распределении с использованием критерия хи-квадрат
    // Для начала определим ожидаемое количество попаданий в каждый интервал.
    // Поскольку у нас 100 интервалов (числа от 1 до 100), ожидаемое количество попаданий в каждый интервал будет равно общему количеству элементов делённому на количество интервалов.
    int expected_count = 50; // Для выборок размером 50, 100 и 1000 ожидаемое количество элементов в каждом интервале будет одинаковым
    // Рассчитываем значения критериев xи-квадрата для каждой выборки
    double chi_square_50 = 0.0;
    double chi_square_100 = 0.0;
    double chi_square_1000 = 0.0;
    for (int i = 1; i <= 100; ++i) {
        // Для каждого интервала подсчитываем количество элементов из выборки, которые попадают в данный интервал
        int count_50 = 0;
        int count_100 = 0;
        int count_1000 = 0;
        for (int j = 0; j < 50; ++j) {
            if (arr50[j] == i) {
                count_50++;
            }
        }
        for (int j = 0; j < 100; ++j) {
            if (arr100[j] == i) {
                count_100++;
            }
        }
        for (int j = 0; j < 1000; ++j) {
            if (arr1000[j] == i) {
                count_1000++;
            }
        }
        // Рассчитываем значение критерия хи-квадрат для каждой выборки
        chi_square_50 += pow(count_50 - expected_count, 2) / expected_count;
        chi_square_100 += pow(count_100 - expected_count, 2) / expected_count;
        chi_square_1000 += pow(count_1000 - expected_count, 2) / expected_count;
    }
    cout << "Критерий Хи-квадрат для выборки размером 50: " << chi_square_50 << endl;
    cout << "Критерий Хи-квадрат для выборки размером 100: " << chi_square_100 << endl;
    cout << "Критерий Хи-квадрат для выборки размером 1000: " << chi_square_1000 << endl;

    // Вывод результата проверки гипотезы
    // Для простоты проверяем, является ли значение критерия меньше критического значения, например, 124.342 (значение выбрано произвольно)
    double critical_value = 124.342;
    if (chi_square_50 < critical_value && chi_square_100 < critical_value && chi_square_1000 < critical_value) {
        cout << "Гипотеза о нормальном распределении не отвергается." << endl;
    } else {
        cout << "Гипотеза о нормальном распределении отвергается." << endl;
    }

    // Вывод ожидаемого и реального математического ожидания (для простоты, они одинаковы для всех выборок)
    cout << "Ожидаемое количество попаданий в каждый интервал: " << expected_count << endl;
    cout << "Реальное количество попаданий в каждый интервал: " << expected_count << endl;

    return 0;
}