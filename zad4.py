import random

def sotr():  # Всегда сотрудничает
    return True

def pred():  # Всегда предает
    return False

def notrepeat(round_number, enemy_choices):  # Сначала сотрудничает, затем не повторяет выбор соперника за предыдущий ход
    if round_number == 0:
        return True  # первый раунд - сотрудничает
    else:
        return not enemy_choices[round_number - 1]  # не повторяет предыдущий ход соперника

def play(rounds, a_choices):
    self_choices = []  # Свои решения
    enemy_choices = []  # Решения противника
    score_a = 0
    score_b = 0

    for i in range(rounds):
        if a_choices == "Сотрудничает":
            a_choice = sotr()
        elif a_choices == "Предаёт":
            a_choice = pred()
        elif a_choices == "Не повторяет":
            a_choice = notrepeat(i, enemy_choices)

        b_choice = notrepeat(i, self_choices)

        self_choices.append(a_choice)
        enemy_choices.append(b_choice)

    for i in range(rounds):
        if self_choices[i] and enemy_choices[i]:
            score_a += 24
            score_b += 24
        elif not self_choices[i] and not enemy_choices[i]:
            score_a += 4
            score_b += 4
        elif self_choices[i] and not enemy_choices[i]:
            score_a += 0
            score_b += 20
        else:
            score_a += 20
            score_b += 0

    return score_a, score_b


# Игра 1 (Мы всегда сотрудничаем, противник всегда не повторяет)
rounds = 100 + random.randint(0, 100)
score_a, score_b = play(rounds, "Сотрудничает")
print(f"Игра 1.\nКол-во раундов: {rounds}\nАлгоритм A: {score_a}\nАлгоритм B: {score_b}\n")

# Игра 2 (Мы всегда предаём, противник всегда не повторяет)
rounds = 100 + random.randint(0, 100)
score_a, score_b = play(rounds, "Предаёт")
print(f"Игра 2.\nКол-во раундов: {rounds}\nАлгоритм A: {score_a}\nАлгоритм B: {score_b}\n")

# Игра 3 (Мы всегда не повторяем, противник всегда не повторяет)
rounds = 100 + random.randint(0, 100)
score_a, score_b = play(rounds, "Не повторяет")
print(f"Игра 3.\nКол-во раундов: {rounds}\nАлгоритм A: {score_a}\nАлгоритм B: {score_b}")