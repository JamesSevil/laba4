import math

# Метод Ньютона
def f(x): return 2*x + math.tan(x) # значение ф-ии
def fsh(x): return 2 + 1/(math.cos(x)*math.cos(x)) # значение производной ф-ии
def newton(x0, eps):
    x1 = x0 - f(x0) / fsh(x0)
    iternum = 1
    while abs(x1 - x0) > eps:
        print(iternum, "{:15.6f}".format(x0), "{:15.6f}".format(x1), "{:15.6f}".format(x1 - x0))
        x0 = x1
        x1 = x0 - f(x0) / fsh(x0)
        iternum += 1
    return x1

# Метод простых итераций
def phi(x): return -0.5 * math.tan(x) # итерационная ф-ия
def SimpleIterations(x0, eps):
    x1 = phi(x0)
    iternum = 1
    while abs(x1 - x0) > eps:
        print(iternum, "{:15.6f}".format(x0), "{:15.6f}".format(x1), "{:15.6f}".format(x1 - x0))
        x0 = x1
        x1 = phi(x0)
        iternum += 1
    return x1

def bisection(a, b, eps):
    c = 0.0
    iternum = 1
    while abs(b - a) > eps:
        print(iternum, "{:15.6f}".format(a), "{:15.6f}".format(b), "{:15.6f}".format(b - a))
        c = (a + b) / 2
        if f(a) * f(c) < 0: b = c
        else: a = c
        iternum += 1
    return c


# Метод Ньютона
print("Метод Ньютона:")
print("N".ljust(15) + "xn".ljust(15) + "xn+1".ljust(15) + "xn+1 - xn")
x0 = 1.5  # начальное приближение
eps = 0.001  # точность решения
x = newton(x0, eps)
print("Корень:", x, "\n")

# Метод простых итераций
print("Метод простых итераций:")
print("N".ljust(15) + "xn".ljust(15) + "xn+1".ljust(15) + "xn+1 - xn")
x0 = 1.0  # начальное приближение
eps = 0.001  # точность решения
x = SimpleIterations(x0, eps)
print("Корень:", x, "\n")

# Метод половинного деления
print("Метод половинного деления:")
print("N".ljust(15) + "an".ljust(15) + "bn".ljust(15) + "bn - an")
a = -2.0  # начальный интервал
b = 2.0
eps = 0.001  # точность решения
x = bisection(a, b, eps)
print("Корень:", x, "\n")