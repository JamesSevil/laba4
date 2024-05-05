#include <iostream>
#include <vector>

using namespace std;

bool sotr(int round_nubmber, vector<bool> self_choices, vector<bool> enemy_choices) { // Всегда сотрудничает
    return true;
}

bool pred(int round_number, vector<bool> self_choices, vector<bool> enemy_choices) { // Всегда предает
    return false;
}

bool notrepeat(int round_number, vector<bool> self_choices, vector<bool> enemy_choices) { // Сначала сотрудничает, а далее не повторяет выбор соперника за предыдущих ход
    if (round_number == 0) return true; // первый раунд - сотрудничает
    else if (enemy_choices[round_number - 1] == true) return false; // не повторяет предыдущий ход соперника
    else return true;
}

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    // Игра 1(Мы всегда сотрудничаем, противник всегда не повторяет)
    int rounds = 100 + rand() % 101;
    vector<bool> self_choices; // Свои решения
    vector<bool> enemy_choices; // решения противника
    for (int i = 0; i < rounds; i++) {
        bool a_choice = sotr(i, self_choices, enemy_choices);
        bool b_choice = notrepeat(i, enemy_choices, self_choices);

        if (a_choice == true && b_choice == true) { // оба сотрудничают
            self_choices.push_back(true);
            enemy_choices.push_back(true);
        } else if (a_choice == false && b_choice == false) { // оба предают
            self_choices.push_back(false);
            enemy_choices.push_back(false);
        } else if (a_choice == true && b_choice == false) { // a сотрудничает, b предает
            self_choices.push_back(true);
            enemy_choices.push_back(false);
        } else { // a предает, b сотрудничает
            self_choices.push_back(false);
            enemy_choices.push_back(true);
        }
    }
    // Подсчет очков
    int score_a = 0;
    int score_b = 0;
    for (int i = 0; i < rounds; i++) {
        if (self_choices[i] == true && enemy_choices[i] == true) {
            score_a += 24;
            score_b += 24;
        } else if (self_choices[i] == false && enemy_choices[i] == false) {
            score_a += 4;
            score_b += 4;
        } else if (self_choices[i] == true && enemy_choices[i] == false) {
            score_a += 0;
            score_b += 20;
        } else {
            score_a += 20;
            score_b += 0;
        }
    }
    cout << "Игра 1.\nКол-во раундов: " << rounds << "\nАлгоритм A: " << score_a << "\nАлгоритм B: " << score_b << endl;

    // Игра 2(Мы всегда предаём, противник всегда не повторяет)
    rounds = 100 + rand() % 101;
    self_choices.clear(); // Свои решения
    enemy_choices.clear(); // решения противника
    for (int i = 0; i < rounds; i++) {
        bool a_choice = pred(i, self_choices, enemy_choices);
        bool b_choice = notrepeat(i, enemy_choices, self_choices);

        if (a_choice == true && b_choice == true) { // оба сотрудничают
            self_choices.push_back(true);
            enemy_choices.push_back(true);
        } else if (a_choice == false && b_choice == false) { // оба предают
            self_choices.push_back(false);
            enemy_choices.push_back(false);
        } else if (a_choice == true && b_choice == false) { // a сотрудничает, b предает
            self_choices.push_back(true);
            enemy_choices.push_back(false);
        } else { // a предает, b сотрудничает
            self_choices.push_back(false);
            enemy_choices.push_back(true);
        }
    }
    // Подсчет очков
    score_a = 0;
    score_b = 0;
    for (int i = 0; i < rounds; i++) {
        if (self_choices[i] == true && enemy_choices[i] == true) {
            score_a += 24;
            score_b += 24;
        } else if (self_choices[i] == false && enemy_choices[i] == false) {
            score_a += 4;
            score_b += 4;
        } else if (self_choices[i] == true && enemy_choices[i] == false) {
            score_a += 0;
            score_b += 20;
        } else {
            score_a += 20;
            score_b += 0;
        }
    }
    cout << "Игра 2.\nКол-во раундов: " << rounds << "\nАлгоритм A: " << score_a << "\nАлгоритм B: " << score_b << endl;

    // Игра 3(Мы всегда не повторяем, противник всегда не повторяет)
    rounds = 100 + rand() % 101;
    self_choices.clear(); // Свои решения
    enemy_choices.clear(); // решения противника
    for (int i = 0; i < rounds; i++) {
        bool a_choice = notrepeat(i, self_choices, enemy_choices);
        bool b_choice = notrepeat(i, enemy_choices, self_choices);

        if (a_choice == true && b_choice == true) { // оба сотрудничают
            self_choices.push_back(true);
            enemy_choices.push_back(true);
        } else if (a_choice == false && b_choice == false) { // оба предают
            self_choices.push_back(false);
            enemy_choices.push_back(false);
        } else if (a_choice == true && b_choice == false) { // a сотрудничает, b предает
            self_choices.push_back(true);
            enemy_choices.push_back(false);
        } else { // a предает, b сотрудничает
            self_choices.push_back(false);
            enemy_choices.push_back(true);
        }
    }
    // Подсчет очков
    score_a = 0;
    score_b = 0;
    for (int i = 0; i < rounds; i++) {
        if (self_choices[i] == true && enemy_choices[i] == true) {
            score_a += 24;
            score_b += 24;
        } else if (self_choices[i] == false && enemy_choices[i] == false) {
            score_a += 4;
            score_b += 4;
        } else if (self_choices[i] == true && enemy_choices[i] == false) {
            score_a += 0;
            score_b += 20;
        } else {
            score_a += 20;
            score_b += 0;
        }
    }
    cout << "Игра 3.\nКол-во раундов: " << rounds << "\nАлгоритм A: " << score_a << "\nАлгоритм B: " << score_b << endl;   

    return 0;
}