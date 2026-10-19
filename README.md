# Концепция языков программирования (Харитонов)

🇷🇺 [Русский](#русский) | 🇬🇧 [English](#english)

> ⚠️ Список заданий неполный и будет дополняться.
> The task list is incomplete and will be updated.

---

## Русский

### Структура репозитория

| Файл | Описание |
|------|----------|
| `Task1.cpp` | Решение задания №1 |

### Сборка и запуск

```bash
mkdir -p build
g++ -std=c++17 -Wall Task1.cpp -o build/Task1
./build/Task1
```

### Задание №1

Распечатать две последовательности чисел:

- $1 + \frac{1}{10^n}$
- $1 + \frac{1}{2^k}$

Остановиться и распечатать значения `n` и `k`, при которых результат становится равен 1.

Для каждого числа:

1. Рядом распечатать его побитовое представление.
2. Разобрать значение на знак, мантиссу и экспоненту.
3. Вычислить исходное число обратно из знака, мантиссы и экспоненты.

### Задание №2

*Язык: желательно C++ или C.*

Запрограммировать эффективный алгоритм вычисления аналитической функции (`sin`, `cos`, `exp`, `ln`, `tan` и т. д.) с максимальным уровнем точности, используя **только** операторы `+ - * /` и целые числа.

- Сравнить точность с функцией из стандартной математической библиотеки (`math`).
- Объяснить разницу между значениями функций, если она есть.
- Точность проверяется минимум в 100 точках числовой оси.
- Эффективность означает, что расчёт выбранным способом нельзя закончить раньше или выполнить быстрее.

> 💡 Подсказка: см. ряд Тейлора.

<!-- Шаблон для новых заданий:
### Задание №N

Текст задания.
-->

---

## English

### Repository structure

| File | Description |
|------|-------------|
| `Task1.cpp` | Solution to Task 1 |

### Build and run

```bash
mkdir -p build
g++ -std=c++17 -Wall Task1.cpp -o build/Task1
./build/Task1
```

### Task 1

Print two sequences of numbers:

- $1 + \frac{1}{10^n}$
- $1 + \frac{1}{2^k}$

Stop and print the values of `n` and `k` at which the result becomes equal to 1.

For each number:

1. Print its bit representation next to it.
2. Decompose the value into sign, mantissa, and exponent.
3. Reconstruct the original number from the sign, mantissa, and exponent.

### Task 2

*Language: preferably C++ or C.*

Implement an efficient algorithm that computes an analytic function (`sin`, `cos`, `exp`, `ln`, `tan`, etc.) with the highest possible precision, using **only** the `+ - * /` operators and integers.

- Compare the precision with the corresponding function from the standard math library (`math`).
- Explain the difference between the values, if there is any.
- Precision must be tested at no fewer than 100 points on the number line.
- Efficiency means that the computation cannot be finished earlier or performed faster with the chosen method.

> 💡 Hint: see the Taylor series.

<!-- Template for new tasks:
### Task N

Task description.
-->
