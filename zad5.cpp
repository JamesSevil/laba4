// вариант 5(RC4)
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> RC4(int n, int GeneratingOutput) {

    // Инициализация таблиц
    vector<int> S; // Таблица S
    for (int i = 0; i < pow(2, n); i++) { // таблица замен S
        S.push_back(i);
    }
    vector<int> K; // Таблица K
    int k = 1; // Значение ключа
    for (int i = 0; i < pow(2, n); i++) { // Таблица K с ключом от 1 до 6
        if (k != 6) { // Записываем в таблицу K значения от 1 до 6
            K.push_back(k);
            k++;
        } else {
            K.push_back(k);
            k = 1;
        }
    }
    int j = 0;
    for (int i = 0; i < pow(2, n); i++) { // перестановка
        j = (j + S[i] + K[i]) % (int(pow(2, n)));
        swap(S[i], S[j]);
    }

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
    cout << "Введите число n: ";
    cin >> n;
    int k;
    cout << "Введите необходимое кол-во рандомных чисел: ";
    cin >> k;

    cout << "Рандомные числа:" << endl;
    vector<int> randomnums = RC4(n, k);
    for (int i : randomnums) {
        cout << i << " ";
    }

    return 0;
}