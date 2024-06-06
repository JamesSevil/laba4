import random

def generate_vector(n):  # функция заполнения массива случайными числами
    nums = [random.randint(10, 99) for _ in range(n)]
    return nums

def find_mins(nums):  # функция нахождения 2 минимальных чисел и суммы остатков при делении элементов массива на минимальное число
    min1 = min(nums)
    min2 = min(x for x in nums if x != min1)
    sumost = sum(elem % min1 for elem in nums)
    return min1, min2, sumost

def find_long_seq(nums):  # функция нахождения самой длинной последовательности массива
    long_seq = []
    current_seq = []
    for num in nums:
        if not current_seq or num > current_seq[-1]:
            current_seq.append(num)
        else:
            if len(current_seq) > len(long_seq):
                long_seq = current_seq
            current_seq = [num]
    if len(current_seq) > len(long_seq):
        long_seq = current_seq
    return long_seq

def matrix(n):  # функция заполнения массива и его вывод по n количеству столбцов
    print("Массив:")
    n *= 8
    nums3 = [2000 + i * 10 for i in range(n)]
    for i, num in enumerate(nums3):
        print(f"{num} ", end='')
        if (i + 1) % 8 == 0:
            print()
    print()


# Блок 1
n = int(input("1. Введите размерность массива случайных чисел (не больше 10): "))
while n > 10 or n <= 0:
    n = int(input("Введите корректное значение: "))
nums = generate_vector(n)
print("Вектор случайных чисел:", nums, "\n")

# Блок 2
min1, min2, sumost = find_mins(nums)
print(f"2. Минимальные числа: {min1} {min2}\nСумма остатков: {sumost}\n")

# Блок 3
n = int(input("3. Введите размерность массива чисел (не больше 10): "))
while n > 10 or n <= 0:
    n = int(input("Введите корректное значение: "))
nums2 = [int(input()) for _ in range(n)]
long_seq = find_long_seq(nums2)
print("Самая длинная последовательность массива:", long_seq, "\n")

# Блок 4
n = int(input("4. Введите количество столбцов в массиве (Не больше 10): "))
while n <= 0 or n > 10:
    n = int(input("Введите корректное значение: "))
matrix(n)