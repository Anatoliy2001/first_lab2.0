[![Coverage Status](https://coveralls.io/repos/github/Anatoliy2001/first_lab2.0/badge.svg?branch=main)](https://coveralls.io/github/Anatoliy2001/first_lab2.0?branch=main)
[![CI/CD GitHub Actions](https://github.com/Anatoliy2001/first_lab2.0/actions/workflows/test-action.yml/badge.svg)](https://github.com/Anatoliy2001/first_lab2.0/actions/workflows/test-action.yml)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Anatoliy2001_first_lab2.01&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=Anatoliy2001_first_lab2.0)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=Anatoliy2001_first_lab2.0&metric=bugs)](https://sonarcloud.io/summary/new_code?id=Anatoliy2001_first_lab2.0)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?projectAnatoliy2001_first_lab2.0&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=Anatoliy2001_first_lab2.0)

# Пример работы связки cmake + Google Test (gtest)

Для подгрузки gtest необходимо выполнить команды:
```
git submodule init
git submodule update
```

# План тестирования

## Аттестационные тесты

* Тест А1 (позитивный)
+ Начальное состояние: Открытый терминал
+ Действие: Запуск программы с аргументами 1, -5, 6
+ Ожидаемы результат:
    ```
    Корни уравнения: 3.00, 5.00

    Числа Фибоначчи по порядковому номеру:
    a(1.00) - 1
    b(-5.00) - 0
    c(6.00) - 8
    ```

* Тест А2 (позитивный)
+ Начальное состояние: Открытый терминал
+ Действие: Запуск программы с аргументами 1, 2, 1
+ Ожидаемы результат:
    ```
    Корни уравнения: -1.00, nan

    Числа Фибоначчи по порядковому номеру:
    a(1.00) - 1
    b(2.00) - 2
    c(1.00) - 1
    ```

* Тест А3 (позитивный)
+ Начальное состояние: Открытый терминал
+ Действие: Запуск программы с аргументами 1, 1, 1
+ Ожидаемы результат:
    ```
    Корни уравнения: nan, nan

    Числа Фибоначчи по порядковому номеру:
    a(1.00) - 1
    b(1.00) - 1
    c(1.00) - 1
    ```

* Тест А4 (негативный)
+ Начальное состояние: Открытый терминал
+ Действие: Запуск программы с аргументами 1, -5
+ Ожидаемы результат:
    ```
    Используйте: ./ctest a b c
    ```

* Тест А5 (негативный)
+ Начальное состояние: Открытый терминал
+ Действие: Запуск программы с аргументами 1
+ Ожидаемы результат:
    ```
    Используйте: ./ctest a b c
    ```

* Тест А6 (негативный)
+ Начальное состояние: Открытый терминал
+ Действие: Запуск программы без аргументов 
+ Ожидаемы результат:
    ```
    Используйте: ./ctest a b c
    ```

* Тест А7 (негативный)
+ Начальное состояние: Открытый терминал
+ Действие: Запуск программы с аргументами gg, rr, tt
+ Ожидаемы результат:
    ```
    Введите целые и/или дробные числа, отличные от нуля
    ```

* Тест А8 (негативный)
+ Начальное состояние: Открытый терминал
+ Действие: Запуск программы с аргументами 0, 6, tt
+ Ожидаемы результат:
    ```
    Введите целые и/или дробные числа, отличные от нуля
    ```

## Блочное тестирование (класс my_func)

### Метод int fibonachi(int num)

* Тест Б1.1 (позитивный)
+ Входные данные: 0
+ Ожидаемы результат: 0
+ Входные данные: 1
+ Ожидаемы результат: 1
+ Входные данные: 2
+ Ожидаемы результат: 2

* Тест Б1.2 (позитивный)
+ Входные данные: 5
+ Ожидаемы результат: 5
+ Входные данные: 10
+ Ожидаемы результат: 55

* Тест Б1.3 (негативный)
+ Входные данные: -1
+ Ожидаемы результат: 0

### Метод double* myfunc(double a, double b, double c)

* Тест Б2.1 (позитивный)
+ Входные данные: 4, -1, -5
+ Ожидаемы результат: 1.25, -1.00

* Тест Б1.2 (позитивный)
+ Входные данные: 1, 12, 36
+ Ожидаемы результат: -6.00, nan

* Тест Б1.3 (негативный)
+ Входные данные: 2, 1, 67
+ Ожидаемы результат: nan, nan

## Интеграционное тестирование

* Тест И1 (позитивный)
+ Методы: double* myfunc(double a, double b, double c), int fibonachi(int num)
+ Описание: Поиск чисел Фибоначчи от найденных корней квадратного уравнения
+ Входные данные: myfunc(1, -6, 9)
+ Ожидаемый результат: 2
