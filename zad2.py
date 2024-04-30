import random

def find_long_seq(nums): # Самая длинная последовательность массива
    long_seq = []
    current_seq = []
    
    for i in range(len(nums)):
        if not current_seq or nums[i] > current_seq[-1]:
            current_seq.append(nums[i])
        else:
            if len(current_seq) > len(long_seq):
                long_seq = current_seq
            current_seq = [nums[i]]
    
    if len(current_seq) > len(long_seq):
        long_seq = current_seq
    
    return long_seq

# Блок 1
n = 0
while n > 10 or n <= 0:
    n = int(input("1. Введите размерность массива рандомных чисел(не больше 10): "))
nums = []
min1 = 1000
min2 = 1000
for i in range(n):
    randnums = 10 + random.randint(0, 100) # Генерирую число, записываю его в контейнер
    nums.append(randnums)
    if randnums < min1: # нахожу 2 минимальных
        min2 = min1
        min1 = randnums
    elif randnums < min2 and randnums != min1:
        min2 = randnums
print("Рандомные числа:", end=" ")
for i in nums:
    print(i, end=" ")
print("\n")

# Блок 2
print("2. Минимальные числа:", min1, min2)
sumost = 0
for i in nums: # считаю сумма отсатков при делении элементов массива на минимальное число
    sumost += (i % min1)
print("Сумма остатков:", sumost, "\n")

# Блок 3
n = 0
while n > 10 or n <= 0:
    print("3. Введите размерность массива чисел(не больше 10): ", end="")
    n = int(input())
nums2 = [0] * n
print("Введите массив чисел: ")
for i in range(n):
    nums2[i] = int(input())
LongSeq = find_long_seq(nums2)  # функция нахождения самой длинной последовательности массива
print("Самая длинная последовательность массива: ", end="")
for i in LongSeq:
    print(i, end=" ")
print("\n\n")

# Блок 4
n = 0
while n <= 0 or n > 10:
    print("4. Введите кол-во столбцов в массиве(Не больше 10): ", end="")
    n = int(input())
print("Массив: ")
n *= 8
count = 2
nums3 = [0] * n
nums3[0] = 2000
print(nums3[0], end=" ")
for i in range(1, n):
    nums3[i] = nums3[i - 1] + 10
    print(nums3[i], end=" ")
    if count % 8 == 0:
        print()
    count += 1