#include <benchmark/benchmark.h>

#include "add.hpp"

static void BM_Add(benchmark::State& state)
{
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(add(123, 456));
    }
}

BENCHMARK(BM_Add);

BENCHMARK_MAIN();