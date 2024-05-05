import random

def sotr(round_number, self_choices, enemy_choices): # Всегда сотрудничает
    return True

def pred(round_number, self_choices, enemy_choices): # Всегда предает
    return False

def notrepeat(round_number, self_choices, enemy_choices): # Сначала сотрудничает, а далее не повторяет выбор соперника за предыдущих ход
    if round_number == 0: return True  # первый раунд - сотрудничает
    elif enemy_choices[round_number - 1]: return False  # не повторяет предыдущий ход соперника
    else: return True
    
# Игра 1(Мы всегда сотрудничаем, противник всегда не повторяет)
rounds = random.randint(100, 200)
self_choices = [] # свои решения
enemy_choices = [] # решения противника
for i in range(rounds):
    a_choice = sotr(i, self_choices, enemy_choices)
    b_choice = notrepeat(i, enemy_choices, self_choices)

    if a_choice and b_choice: # оба сотрудничают
        self_choices.append(True)
        enemy_choices.append(True)
    elif not a_choice and not b_choice: # оба предают
        self_choices.append(False)
        enemy_choices.append(False)
    elif a_choice and not b_choice: # А - сотрудничает, B - не сотрудничает
        self_choices.append(True)
        enemy_choices.append(False)
    else: # A - не сотрудничает, B - сотрудничает
        self_choices.append(False)
        enemy_choices.append(True)
# Подсчет очков
score_a = 0
score_b = 0
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
print(f"Игра 1.\nКол-во раундов: {rounds}\nАлгоритм A: {score_a}\nАлгоритм B: {score_b}\n")

# Игра 2(Мы всегда предаём, противник всегда не повторяет)
rounds = random.randint(100, 200)
self_choices = [] # свои решения
enemy_choices = [] # решения противника
for i in range(rounds):
    a_choice = pred(i, self_choices, enemy_choices)
    b_choice = notrepeat(i, enemy_choices, self_choices)

    if a_choice and b_choice:
        self_choices.append(True)
        enemy_choices.append(True)
    elif not a_choice and not b_choice:
        self_choices.append(False)
        enemy_choices.append(False)
    elif a_choice and not b_choice:
        self_choices.append(True)
        enemy_choices.append(False)
    else:
        self_choices.append(False)
        enemy_choices.append(True)
# Подсчет очков
score_a = 0
score_b = 0
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
print(f"Игра 2.\nКол-во раундов: {rounds}\nАлгоритм A: {score_a}\nАлгоритм B: {score_b}\n")

# Игра 3(Мы всегда не повторяем, противник всегда не повторяет)
rounds = random.randint(100, 200)
self_choices = [] # свои решения
enemy_choices = [] # решения противника
for i in range(rounds):
    a_choice = notrepeat(i, self_choices, enemy_choices)
    b_choice = notrepeat(i, enemy_choices, self_choices)

    if a_choice and b_choice:
        self_choices.append(True)
        enemy_choices.append(True)
    elif not a_choice and not b_choice:
        self_choices.append(False)
        enemy_choices.append(False)
    elif a_choice and not b_choice:
        self_choices.append(True)
        enemy_choices.append(False)
    else:
        self_choices.append(False)
        enemy_choices.append(True)
# Подсчет очков
score_a = 0
score_b = 0
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
print(f"Игра 3.\nКол-во раундов: {rounds}\nАлгоритм A: {score_a}\nАлгоритм B: {score_b}\n")