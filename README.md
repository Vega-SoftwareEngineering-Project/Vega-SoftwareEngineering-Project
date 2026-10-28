# Sample C++ Project

Небольшой учебный проект на C++17, который складывает два целых числа.
В проект входят unit-тесты GoogleTest, бенчмарк Google Benchmark
и документация Doxygen.

## Требования

- CMake 3.16 или новее
- Компилятор с поддержкой C++17
- Git

GoogleTest и Google Benchmark загружаются автоматически при настройке CMake.

## Сборка

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

## Запуск программы

```bash
./build/main 12 13
```

Ожидаемый результат:

```text
25
```

## Тесты

```bash
ctest --test-dir build --output-on-failure
```

## Бенчмарк

```bash
./build/benchmark_add --benchmark_min_time=0.1s
```

Бенчмарк выводит результаты измерений в терминал.
GitHub Actions запускает его автоматически.

## Документация

Doxygen генерирует документацию, а GitHub Actions публикует её
на GitHub Pages при каждом push в ветку main.

Ссылка:

https://github.com/Vega-SoftwareEngineering-Project/Vega-SoftwareEngineering-Project