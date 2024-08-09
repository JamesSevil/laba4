// вариант 5(RC4)
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) { // перегрузка вывода вектора
    for (const auto& element : vec) {
        os << element << " ";
    }
    return os;
}

vector<int> RC4(int n, int GeneratingOutput) { // алгоритм псевдослучайной генерации чисел
    // Инициализация таблиц
    vector<int> S; // Таблица S
    for (int i = 0; i < pow(2, n); i++) { // таблица замен S
        S.push_back(i);
    }
    cout << endl << "Таблица S: " << S << endl;
    vector<int> K; // Таблица K
    int key = 1; // Значение ключа
    for (int i = 0; i < pow(2, n); i++) { // Таблица K с ключом от 1 до 6
        if (key != 6) { // Записываем в таблицу K значения от 1 до 6
            K.push_back(key);
            key++;
        } else {
            K.push_back(key);
            key = 1;
        }
    }
    cout << "Таблица K: " << K << endl;
    int j = 0;
    for (int i = 0; i < pow(2, n); i++) { // перестановка
        j = (j + S[i] + K[i]) % (int(pow(2, n)));
        swap(S[i], S[j]);
    }
    cout << "Перемешанная таблица S: " << S << endl;

    // Алгоритм псевдослучайной генерации
    vector<int> Z; // Рандомные числа
    int i = 0, t = 0, z = 0;
    j = 0;
    while (GeneratingOutput != 0) {
        i = (i + 1) % (int(pow(2, n)));
        j = (j + S[i]) % (int(pow(2, n)));
        swap(S[i], S[j]);
        t = (S[i] + S[j]) % (int(pow(2, n)));
        z = S[t];
        Z.push_back(z);
        GeneratingOutput--;
    }

    return Z;
}


int main(){
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "Введите число n(ограничение): ";
    cin >> n;
    int countRandNums;
    cout << "Введите необходимое кол-во рандомных чисел: ";
    cin >> countRandNums;

    vector<int> randomnums = RC4(n, countRandNums);
    cout << "Рандомные числа: " << randomnums << endl;

    return 0;
}