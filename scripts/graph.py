import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import make_interp_spline

# Данные измерений
sizes = np.array([100, 200, 300, 400, 1000, 2000, 4000, 10000])
times = np.array([0.000573, 0.003869, 0.012829, 0.033208, 1.067853, 34.219271, 449.660521, 7409.165449])

# Данные из таблицы (ожидаемое время)
table_sizes = np.array([100, 200, 400, 1000, 2000, 4000, 10000])
table_times = np.array([0.01, 0.08, 0.64, 8, 64, 8.5*60, 2.2*3600])  # конвертируем минуты и часы в секунды

# Создаем сглаженную линию для ожидаемого времени
sizes_smooth = np.linspace(table_sizes.min(), table_sizes.max(), 300)
spline = make_interp_spline(table_sizes, table_times, k=3)
table_times_smooth = spline(sizes_smooth)

plt.figure(figsize=(12, 8))

# Измеренные данные
plt.plot(sizes, times, color='b', linewidth=2, label='Фактическое время умножения')
plt.scatter(sizes, times, color='b', edgecolor='k', s=50, zorder=5, label='Измеренные точки')

# Сглаженное ожидаемое время из таблицы
plt.plot(sizes_smooth, table_times_smooth, color='r', linestyle='--', linewidth=2, label='Ожидаемое время (сглаженное)')
plt.scatter(table_sizes, table_times, color='r', edgecolor='k', s=50, zorder=5, label='Табличные значения')

# Подписи и оформление
plt.xlabel('Размер матрицы (N x N)', fontsize=12)
plt.ylabel('Время выполнения (секунды)', fontsize=12)
plt.title('Сравнение фактического и ожидаемого времени умножения матриц', fontsize=14)
plt.grid(True, alpha=0.3)
plt.legend(fontsize=11)

# Линейные оси
plt.yscale('linear')
plt.xscale('linear')

# Настройка осей с правильными подписями и поворотом на 90 градусов
plt.xticks([100, 200, 400, 1000, 2000, 4000, 10000],
           ['100', '200', '400', '1000', '2000', '4000', '10000'],
           rotation=90)

# Устанавливаем разумные пределы для осей
plt.xlim(0, 11000)
plt.ylim(-100, 8000)  # Ограничиваем до 8000 секунд для лучшей видимости

plt.tight_layout()
plt.show()