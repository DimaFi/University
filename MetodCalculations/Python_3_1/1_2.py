import numpy as np

# Данные из таблицы
x = np.array([0, 1, 2, 3])
V = 12.0  # Можно заменить на любое значение для V
y = np.array([V, 1 + V, 8 + V, 27 + V])

# Функция для вычисления полинома Лагранжа
def lagrange_polynomial(x, y, x_values):
    n = len(x)
    result = []
    for x_val in x_values:
        L_n = 0
        for i in range(n):
            l_i = 1
            for j in range(n):
                if i != j:
                    l_i *= (x_val - x[j]) / (x[i] - x[j])
            L_n += l_i * y[i]
        result.append(L_n)
    return result

# Точки, в которых хотим вычислить значение функции
x_values_to_interpolate = [0.5, 1.5, 2.5]

# Вычисляем интерполированные значения
interpolated_values = lagrange_polynomial(x, y, x_values_to_interpolate)

# Выводим результаты
for x_val, y_val in zip(x_values_to_interpolate, interpolated_values):
    print(f"Приближенное значение функции в точке x = {x_val}: y = {y_val}")
