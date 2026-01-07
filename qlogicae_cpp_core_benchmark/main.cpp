#include "pch.hpp"

#include "main.hpp"


namespace Experiment11 // while, ranged_based_for_loop
{   
    static size_t index = 0, size = 10;

    static char output_value;

    static std::string data(size, '0');

    void for_loop()
    {
        for (index = 0; index < size; ++index)
        {
            output_value = data[index];
        }
    }

    void while_loop()
    {
        index = 0;
        while (index < size)
        {
            output_value = data[index];
            ++index;
        }
    }

    void do_while_loop()
    {
        index = 0;
        do
        {
            output_value = data[index];
            ++index;

        }
        while (index < size);
    }

    void ranged_based_for_loop()
    {
        for (const char& datum : data)
        {
            output_value = datum;
        }
    }

    void for_each_loop_1()
    {
        std::ranges::for_each(
            data.begin(),
            data.end(),
            [](const char datum)
            {
                output_value = datum;
            }
        );
    }

    void for_each_loop_2()
    {
        std::ranges::for_each(
            data,
            [](const char datum)
            {
                output_value = datum;
            }
        );
    }

    void execute()
    {
        QLogicaeCppCore::RuntimeBenchmarkerTestSuite test_suite_1
        {
            .name = "loops",
            .warmup_count = 1,
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 100000000,
                    .iterations = 1
                },
                {
                    .epochs = 10000000,
                    .iterations = 10
                },
                {
                    .epochs = 1000000,
                    .iterations = 100
                },
                {
                    .epochs = 100000,
                    .iterations = 1000
                },
                {
                    .epochs = 100,
                    .iterations = 1000000
                }
            },

            .test_cases =
            {                
                {
                    .name = "for_loop",
                    .callback = for_loop
                },
                {
                    .name = "while_loop",
                    .callback = while_loop
                },
                {
                    .name = "do_while_loop",
                    .callback = do_while_loop
                },
                {
                    .name = "ranged_based_for_loop",
                    .callback = ranged_based_for_loop
                },
                {
                    .name = "for_each_loop_1",
                    .callback = for_each_loop_1
                },
                {
                    .name = "for_each_loop_2",
                    .callback = for_each_loop_2
                }
            }
        };

        QLogicaeCppCore::RuntimeBenchmarker::singleton
            .execute(
                test_suite_1
            );

        bool exit_code;
        std::cin >> exit_code;
    }
}

int main(int argc, char** argv)
{              
    Experiment11::execute();

    return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}
