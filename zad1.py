import math

# Метод Ньютона
def f(x):  # значение функции
    return 2*x + math.tan(x)

def fsh(x):  # значение производной функции
    return 2 + 1/(math.cos(x)**2)

def newton(x0, eps):
    x1 = x0 - f(x0) / fsh(x0)
    iternum = 1
    while abs(x1 - x0) > eps:
        print(f"{iternum:2d} {x0:15.10f} {x1:15.10f} {x1 - x0:15.10f}")
        x0 = x1
        x1 = x0 - f(x0) / fsh(x0)
        iternum += 1
    return x0

# Метод простых итераций
def phi(x):  # итерационная функция
    return x - f(x) / fsh(x)

def simple_iterations(x0, eps):
    x1 = phi(x0)
    iternum = 1
    while abs(x1 - x0) > eps:
        print(f"{iternum:2d} {x0:15.10f} {x1:15.10f} {x1 - x0:15.10f}")
        x0 = x1
        x1 = phi(x0)
        iternum += 1
    return x0

# Метод половинного деления
def bisection(a, b, eps):
    c = 0.0
    iternum = 1
    while abs(b - a) > eps:
        print(f"{iternum:2d} {a:15.10f} {b:15.10f} {b - a:15.10f}")
        c = (a + b) / 2
        if f(c) == 0.0:
            break
        elif f(c) * f(a) < 0:
            b = c
        else:
            a = c
        iternum += 1
    return c


# Метод Ньютона
print("Метод Ньютона:\nN\txn\txn+1\txn+1 - xn")
x0 = 1.5  # начальное приближение
eps = 0.0001  # точность решения
x = newton(x0, eps)
print(f"Корень: {x:.10f}\n")

# Метод простых итераций
print("Метод простых итераций:\nN\txn\txn+1\txn+1 - xn")
x0 = 1.5  # начальное приближение
eps = 0.0001  # точность решения
x = simple_iterations(x0, eps)
print(f"Корень: {x:.10f}\n")

# Метод половинного деления
print("Метод половинного деления:\nN\tan\tbn\tbn - an")
a = -10.0  # начальный интервал
b = 5.0
eps = 0.0001  # точность решения
x = bisection(a, b, eps)
print(f"Корень: {x:.10f}\n")