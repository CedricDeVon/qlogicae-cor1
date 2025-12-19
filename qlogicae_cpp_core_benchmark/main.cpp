#include "pch.hpp"

#include "main.hpp"

inline static QLogicaeCppCore::Result<bool> static_boolean_result;

void experiment__outptut_result__1()
{
    static_boolean_result.set_to_good_status_with_value(
        true
    );
}

void experiment__outptut_result__2(
    QLogicaeCppCore::Result<bool>& boolean_result
)
{
    boolean_result.set_value(
        true
    );
}


int main(int argc, char** argv)
{       
    ankerl::nanobench::Bench bench_a;
    bench_a.minEpochIterations(100'000'000);
    bench_a.relative(true);
    QLogicaeCppCore::Result<bool> instance_boolean_result;
    bench_a.run("experiment__outptut_result__1_1 | 1", [&]
        {
            experiment__outptut_result__1();
        }
    );
    bench_a.run("experiment__outptut_result__2_1 | 1", [&]
        {            
            experiment__outptut_result__2(
                instance_boolean_result
            );
        }
    );

    ankerl::nanobench::Bench bench_b;
    bench_b.minEpochIterations(100'000);
    bench_b.relative(true);
    bench_b.run("experiment__outptut_result__1_2 | 1'000", [&]
        {
            for (size_t i1 = 0; i1 < 1'000; ++i1)
            {
                experiment__outptut_result__1();
            }
        }
    );
    bench_b.run("experiment__outptut_result__2_2 | 1'000", [&]
        {            
            for (size_t i2 = 0; i2 < 1'000; ++i2)
            {
                experiment__outptut_result__2(
                    instance_boolean_result
                );
            }
        }
    );


    ankerl::nanobench::Bench bench_c;
    bench_c.minEpochIterations(100);
    bench_c.relative(true);
    bench_c.run("experiment__outptut_result__1_3 | 1'000'000", [&]
        {
            for (size_t i1 = 0; i1 < 1'000'000; ++i1)
            {
                experiment__outptut_result__1();
            }
        }
    );
    bench_c.run("experiment__outptut_result__2_3 | 1'000'000", [&]
        {
            for (size_t i2 = 0; i2 < 1'000'000; ++i2)
            {
                experiment__outptut_result__2(
                    instance_boolean_result
                );
            }
        }
    );



    ankerl::nanobench::Bench bench_d;
    bench_d.minEpochIterations(1);
    bench_d.relative(true);
    bench_d.run("experiment__outptut_result__1_4 | 1'000'000'000", [&]
        {
            for (size_t i1 = 0; i1 < 1'000'000'000; ++i1)
            {
                experiment__outptut_result__1();
            }
        }
    );
    bench_d.run("experiment__outptut_result__2_4 | 1'000'000'000", [&]
        {
            for (size_t i2 = 0; i2 < 1'000'000'000; ++i2)
            {
                experiment__outptut_result__2(
                    instance_boolean_result
                );
            }
        }
    );


    bool exit_code;
    std::cin >> exit_code;

    return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}

/*

ankerl::nanobench::Bench bench;

    bench.minEpochIterations(1);
    bench.relative(true);

    size_t n = 100'000'000;

    bench.run("'string_view' Concatenation", [&]
        {
            std::string result;
            for (size_t i = 0; i < n; ++i)
            {
                result = std::string_view("a");
            }
        }
    );
    bench.run("'string' Concatenation", [&]
        {
            std::string result;
            for (size_t i = 0; i < n; ++i)
            {
                result = std::string("a");
            }
        }
    );


*/