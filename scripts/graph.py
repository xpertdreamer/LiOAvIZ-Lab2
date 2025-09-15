import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import make_interp_spline

# Данные
sizes = np.array([100, 200, 300, 400, 1000, 2000, 4000, 10000])
times = np.array([ 0.000573, 0.003869, 0.012829, 0.033208, 1.067853, 34.219271, 449.660521, 7409.165449])

plt.figure(figsize=(10, 6))

# Сглаживание линии
sizes_smooth = np.linspace(sizes.min(), sizes.max(), 500)  # новые точки для плавности
spl = make_interp_spline(sizes, times, k=3)  # кубическая сплайн-интерполяция
times_smooth = spl(sizes_smooth)

# Плавная линия
plt.plot(sizes_smooth, times_smooth, color='b', label='Время умножения (плавно)')

# Оригинальные точки
plt.scatter(sizes, times, color='b', edgecolor='k', zorder=5, label='Измеренные точки')

# Плавная линия n^3
c = times[-1] / (sizes[-1]**3)
plt.plot(sizes_smooth, c * sizes_smooth**3, linestyle='--', color='r', label=r'$N^3$ (масштабировано)')

# Подписи и оформление
plt.xlabel('Размер матрицы (N x N)')
plt.ylabel('Время умножения (сек)')
plt.title('Время умножения матриц разных размеров')
plt.grid(True)
plt.legend()

# Настройка осей
plt.setp(plt.gca().get_xticklabels(), rotation=90, ha='right')
plt.xticks([100, 200, 300, 400, 1000, 2000, 4000, 10000])
plt.yticks([0, 0.1, 1, 10, 50, 100, 200])

plt.yscale('linear')
plt.show()
