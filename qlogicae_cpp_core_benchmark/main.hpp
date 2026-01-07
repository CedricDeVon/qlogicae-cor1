#pragma once

#include "qlogicae_cpp_core_benchmark/includes/application.hpp"

#include "qlogicae_cpp_core/includes/runtime_benchmarker.hpp"

int main(int, char**);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE,
    LPSTR,
    int
)
{
    return main(__argc, __argv);
}

namespace QLogicaeCppCoreBenchmark
{

}


struct NanobenchBenchmarkEpochIterationPair
{
    std::size_t epochs = 1;

    std::size_t iterations = 1;
};

struct NanobenchBencchmarkingTestCase
{
    std::string name = "";

    std::function<void()> callback = []() {};

    std::function<void()> before_test_callback = []() {};

    std::function<void()> after_test_callback = []() {};
};

struct NanobenchBencchmarkingTestSuite
{
    std::string name = "";

    size_t warmup_count = 1;

    bool is_relative = true;

    std::vector<NanobenchBenchmarkEpochIterationPair> epoch_iteration_pairs = {};

    std::vector<NanobenchBencchmarkingTestCase> test_cases = {};

    std::function<void()> before_test_suite_callback = []() {};

    std::function<void()> before_test_case_callback = []() {};

    std::function<void()> before_test_case_iteration_callback = []() {};

    std::function<void()> after_test_suite_callback = []() {};

    std::function<void()> after_test_case_callback = []() {};

    std::function<void()> after_test_case_iteration_callback = []() {};
};

void execute_nanobenchmark(
    const NanobenchBencchmarkingTestSuite& test_suite
)
{
    const std::string test_suite_name =
        test_suite.name;

    const std::size_t test_suite_epoch_pair_count =
        test_suite.epoch_iteration_pairs.size();

    const std::size_t test_suite_case_count =
        test_suite.test_cases.size();

    const std::size_t test_suite_warmup_count =
        test_suite.warmup_count;

    const bool test_suite_is_relative =
        test_suite.is_relative;

    const std::function<void()>& before_test_suite_callback =
        test_suite.before_test_suite_callback;

    const std::function<void()>& after_test_suite_callback =
        test_suite.after_test_suite_callback;

    const std::function<void()>& before_test_case_callback =
        test_suite.before_test_case_callback;

    const std::function<void()>& after_test_case_callback =
        test_suite.after_test_case_callback;

    const std::function<void()>& before_test_case_iteration_callback =
        test_suite.before_test_case_iteration_callback;

    const std::function<void()>& after_test_case_iteration_callback =
        test_suite.after_test_case_iteration_callback;

    before_test_suite_callback();

    for (std::size_t epoch_index = 0;
        epoch_index < test_suite_epoch_pair_count;
        ++epoch_index)
    {
        before_test_case_callback();

        const auto& epoch_iteration_pair =
            test_suite.epoch_iteration_pairs[epoch_index];

        const std::size_t epochs =
            epoch_iteration_pair.epochs;

        const std::size_t iterations =
            epoch_iteration_pair.iterations;

        ankerl::nanobench::Bench benchmarker;
        benchmarker.minEpochIterations(epochs);
        benchmarker.warmup(test_suite_warmup_count);
        benchmarker.relative(test_suite_is_relative);

        for (std::size_t test_index = 0;
            test_index < test_suite_case_count;
            ++test_index)
        {
            const auto& test_case =
                test_suite.test_cases[test_index];

            const std::string test_case_name =
                test_case.name;

            const std::string benchmark_name =
                test_suite_name + "__" + test_case_name + "__" + std::to_string(iterations);

            const std::function<void()>& callback =
                test_case.callback;

            const std::function<void()>& before_test_callback =
                test_case.before_test_callback;

            const std::function<void()>& after_test_callback =
                test_case.after_test_callback;

            before_test_case_iteration_callback();

            before_test_callback();

            benchmarker.run(
                benchmark_name,
                [callback, iterations]()
                {
                    for (std::size_t index_3 = 0;
                        index_3 < iterations;
                        ++index_3
                        )
                    {
                        callback();
                    }
                }
            );

            after_test_callback();

            after_test_case_iteration_callback();
        }

        std::cout << "\n";

        after_test_case_callback();
    }

    after_test_suite_callback();
}


/*

std::future<bool>
    construct_asynchronously(
        const std::function<void(const bool& result)>&
        callback = nullptr
    );

std::future<bool>
    destruct_asynchronously(
        const std::function<void(const bool& result)>&
            callback = nullptr
    );

*/

/*

namespace Experiment1 // double, any raw value
{
    inline static QLogicaeCppCore::Result<double> static_result_1;

    inline static char static_char_output = 1;

    inline static int static_int_output = 1;

    inline static short int static_short_int_output = 1;

    inline static long int static_long_int_output = 1;

    inline static long long int static_long_long_int_output = 1;

    inline static int8_t static_int8_t_output = 1;

    inline static int16_t static_int16_t_output = 1;

    inline static int32_t static_int32_t_output = 1;

    inline static int64_t static_int64_t_output = 1;

    inline static size_t static_size_t_output = 1;

    inline static float static_float_output = 1.0;

    inline static double static_double_output = 1.0;

    void add__static__char_output()
    {
        static_char_output +=
            static_char_output * 1 * 2;
        static_char_output +=
            static_char_output * 1 * 2;
    }

    void add__static__short_int_output()
    {
        static_short_int_output +=
            static_short_int_output * 1 * 2;
        static_short_int_output +=
            static_short_int_output * 1 * 2;
    }

    void add__static__int_output()
    {
        static_int_output +=
            static_int_output * 1 * 2;
        static_int_output +=
            static_int_output * 1 * 2;
    }

    void add__static__long_int_output()
    {
        static_long_int_output +=
            static_long_int_output * 1 * 2;
        static_long_int_output +=
            static_long_int_output * 1 * 2;
    }

    void add__static__long_long_int_output()
    {
        static_long_long_int_output +=
            static_long_long_int_output * 1 * 2;
        static_long_long_int_output +=
            static_long_long_int_output * 1 * 2;
    }

    void add__static__int8_t_output()
    {
        static_int8_t_output +=
            static_int8_t_output * 1 * 2;
        static_int8_t_output +=
            static_int8_t_output * 1 * 2;
    }

    void add__static__int16_t_output()
    {
        static_int16_t_output +=
            static_int16_t_output * 1 * 2;
        static_int16_t_output +=
            static_int16_t_output * 1 * 2;
    }

    void add__static__int32_t_output()
    {
        static_int32_t_output +=
            static_int32_t_output * 1 * 2;
        static_int32_t_output +=
            static_int32_t_output * 1 * 2;
    }

    void add__static__int64_t_output()
    {
        static_int64_t_output +=
            static_int64_t_output * 1 * 2;
        static_int64_t_output +=
            static_int64_t_output * 1 * 2;
    }

    void add__static__size_t_output()
    {
        static_size_t_output +=
            static_size_t_output * 1 * 2;
        static_size_t_output +=
            static_size_t_output * 1 * 2;
    }

    void add__static__float_output()
    {
        static_float_output +=
            static_float_output * 1.0 * 2.0;
        static_float_output +=
            static_float_output * 1.0 * 2.0;
    }

    void add__static__double_output()
    {
        static_double_output +=
            static_double_output * 1.0 * 2.0;
        static_double_output +=
            static_double_output * 1.0 * 2.0;
    }

    void add__static__result_output()
    {
        static_result_1.set_to_good_status_with_value(
            static_result_1.get_value() * 1.0 * 2.0
        );
        static_result_1.set_to_good_status_with_value(
            static_result_1.get_value() * 1.0 * 2.0
        );
    }

    void execute(
        int argc, char** argv
    )
    {
        folly::Init
            init(&argc, &argv);

        std::size_t
            index_1,
            size_1,
            current_warmup_count,
            current_epoch_count,
            current_iteration_count,
            size_t_value;

        std::vector<std::size_t>
            epoch_counts,
            iteration_counts;

        QLogicaeCppCore::Result<size_t>
            instance_result;

        current_warmup_count = 1;
        epoch_counts = { 100'000'000, 100'000, 100, 1 };
        iteration_counts = { 1, 1'000, 1'000'000, 1'000'000'000 };
        size_1 = iteration_counts.size();

        for (index_1 = 0; index_1 < size_1; ++index_1)
        {
            current_epoch_count = epoch_counts[index_1];
            current_iteration_count = iteration_counts[index_1];

            ankerl::nanobench::Bench benchmarker;
            benchmarker.minEpochIterations(current_epoch_count);
            benchmarker.warmup(current_warmup_count);
            benchmarker.relative(true);

            if (current_iteration_count > 1)
            {
                benchmarker.run("add__static__result_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__result_output();
                        }
                    }
                );

                benchmarker.run("add__static__char_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__char_output();
                        }
                    }
                );

                benchmarker.run("add__static__short_int_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__short_int_output();
                        }
                    }
                );

                benchmarker.run("add__static__int_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__int_output();
                        }
                    }
                );

                benchmarker.run("add__static__long_int_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__long_int_output();
                        }
                    }
                );

                benchmarker.run("add__static__long_long_int_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__long_long_int_output();
                        }
                    }
                );

                benchmarker.run("add__static__int8_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__int8_t_output();
                        }
                    }
                );

                benchmarker.run("add__static__int16_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__int16_t_output();
                        }
                    }
                );

                benchmarker.run("add__static__int32_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__int32_t_output();
                        }
                    }
                );

                benchmarker.run("add__static__int64_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__int64_t_output();
                        }
                    }
                );

                benchmarker.run("add__static__size_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__size_t_output();
                        }
                    }
                );

                benchmarker.run("add__static__float_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__float_output();
                        }
                    }
                );

                benchmarker.run("add__static__double_output | " + std::to_string(current_iteration_count), [&]
                    {
                        for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                        {
                            add__static__double_output();
                        }
                    }
                );
            }
            else
            {
                benchmarker.run("add__static__result_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__result_output();
                    }
                );

                benchmarker.run("add__static__char_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__char_output();
                    }
                );

                benchmarker.run("add__static__short_int_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__short_int_output();
                    }
                );

                benchmarker.run("add__static__int_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__int_output();
                    }
                );

                benchmarker.run("add__static__long_int_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__long_int_output();
                    }
                );

                benchmarker.run("add__static__long_long_int_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__long_long_int_output();
                    }
                );

                benchmarker.run("add__static__int8_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__int8_t_output();
                    }
                );

                benchmarker.run("add__static__int16_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__int16_t_output();
                    }
                );

                benchmarker.run("add__static__int32_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__int32_t_output();
                    }
                );

                benchmarker.run("add__static__int64_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__int64_t_output();
                    }
                );
                benchmarker.run("add__static__size_t_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__size_t_output();
                    }
                );

                benchmarker.run("add__static__float_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__float_output();
                    }
                );

                benchmarker.run("add__static__double_output | " + std::to_string(current_iteration_count), [&]
                    {
                        add__static__double_output();
                    }
                );
            }
        }

        bool exit_code;
        std::cin >> exit_code;
    }
}

namespace Experiment3 // all
{
    inline static double static_double_output = 1;

    void layer_0()
    {
        static_double_output +=
            static_double_output * 1.0 * 2.0;
        static_double_output +=
            static_double_output * 1.0 * 2.0;
    }

    namespace Layer1
    {
        void layer_1()
        {
            static_double_output +=
                static_double_output * 1.0 * 2.0;
            static_double_output +=
                static_double_output * 1.0 * 2.0;
        }

        namespace Layer2
        {
            void layer_2()
            {
                static_double_output +=
                    static_double_output * 1.0 * 2.0;
                static_double_output +=
                    static_double_output * 1.0 * 2.0;
            }

            namespace Layer3
            {
                void layer_3()
                {
                    static_double_output +=
                        static_double_output * 1.0 * 2.0;
                    static_double_output +=
                        static_double_output * 1.0 * 2.0;
                }

                namespace Layer4
                {
                    void layer_4()
                    {
                        static_double_output +=
                            static_double_output * 1.0 * 2.0;
                        static_double_output +=
                            static_double_output * 1.0 * 2.0;
                    }

                    namespace Layer5
                    {
                        void layer_5()
                        {
                            static_double_output +=
                                static_double_output * 1.0 * 2.0;
                            static_double_output +=
                                static_double_output * 1.0 * 2.0;
                        }
                    }
                }
            }
        }
    }

    void execute()
    {
        std::size_t
            index_1,
            size_1,
            current_warmup_count,
            current_epoch_count,
            current_iteration_count,
            size_t_value;

        std::vector<std::size_t>
            epoch_counts,
            iteration_counts;

        QLogicaeCppCore::Result<size_t>
            instance_result;

        current_warmup_count = 1;
        epoch_counts = { 100'000'000, 10'000'000, 1'000'000, 100'000, 100, 1 };
        iteration_counts = { 1, 10, 100, 1'000, 1'000'000, 1'000'000'000 };
        size_1 = iteration_counts.size();

        for (index_1 = 0; index_1 < size_1; ++index_1)
        {
            current_epoch_count = epoch_counts[index_1];
            current_iteration_count = iteration_counts[index_1];

            ankerl::nanobench::Bench benchmarker;
            benchmarker.minEpochIterations(current_epoch_count);
            benchmarker.warmup(current_warmup_count);
            benchmarker.relative(true);

            benchmarker.run("layer_0 | " + std::to_string(current_iteration_count), [&]
                {
                    for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                    {
                        layer_0();
                    }
                }
            );

            benchmarker.run("layer_1 | " + std::to_string(current_iteration_count), [&]
                {
                    for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                    {
                        Layer1::layer_1();
                    }
                }
            );

            benchmarker.run("layer_2 | " + std::to_string(current_iteration_count), [&]
                {
                    for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                    {
                        Layer1::Layer2::layer_2();
                    }
                }
            );

            benchmarker.run("layer_3 | " + std::to_string(current_iteration_count), [&]
                {
                    for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                    {
                        Layer1::Layer2::Layer3::layer_3();
                    }
                }
            );

            benchmarker.run("layer_4 | " + std::to_string(current_iteration_count), [&]
                {
                    for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                    {
                        Layer1::Layer2::Layer3::Layer4::layer_4();
                    }
                }
            );

            benchmarker.run("layer_5 | " + std::to_string(current_iteration_count), [&]
                {
                    for (size_t index_1 = 0; index_1 < current_iteration_count; ++index_1)
                    {
                        Layer1::Layer2::Layer3::Layer4::Layer5::layer_5();
                    }
                }
            );

            std::cout << "\n";
        }

        bool exit_code;
        std::cin >> exit_code;
    }
}


namespace Experiment4 // string_view
{
    inline static std::string static_string_input = "a";

    inline static std::string static_string_output = "";

    inline static std::string_view static_string_view_input = "a";

    inline static std::string_view static_string_view_output = "";

    void string_concatenation()
    {
        static_string_output =
            static_string_input;
    }

    void string_view_concatenation()
    {
        static_string_view_output =
            static_string_view_input;
    }

    void execute()
    {
        NanobenchBencchmarkingTestSuite test_suite
        {
            .name = "string_value_passing",
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 10'000,
                    .iterations = 1
                },
                {
                    .epochs = 1'000,
                    .iterations = 10
                },
                {
                    .epochs = 100,
                    .iterations = 100
                },
                {
                    .epochs = 10,
                    .iterations = 1'000
                },
                {
                    .epochs = 1,
                    .iterations = 1'000'000
                },
                {
                    .epochs = 1,
                    .iterations = 10'000'000
                },
                {
                    .epochs = 1,
                    .iterations = 100'000'000
                }
            },
            .test_cases =
            {
                {
                    .name = "string",
                    .callback = string_concatenation
                },
                {
                    .name = "string_view",
                    .callback = string_view_concatenation
                }
            }
        };

        execute_nanobenchmark(
            test_suite
        );

        bool exit_code;
        std::cin >> exit_code;
    }
}


namespace Experiment5 // boost_async
{
    inline static std::shared_ptr<boost::asio::thread_pool> THREAD_POOL;

    void boost_async()
    {
        boost::asio::post(
            *THREAD_POOL,
            []()
            {

            }
        );
    }

    void std_async()
    {
        std::async(
            std::launch::async,
            []()
            {

            }
        );
    }

    void execute()
    {
        std::cout << std::thread::hardware_concurrency() << "\n";

        THREAD_POOL =
            std::make_shared<boost::asio::thread_pool>(
                std::thread::hardware_concurrency()
            );

        NanobenchBencchmarkingTestSuite test_suite
        {
            .name = "asynchronous",
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 100'000,
                    .iterations = 1
                },
                {
                    .epochs = 10'000,
                    .iterations = 10
                },
                {
                    .epochs = 1'000,
                    .iterations = 100
                },
                {
                    .epochs = 100,
                    .iterations = 1'000
                },
                {
                    .epochs = 1,
                    .iterations = 1'000'000
                }
            },
            .test_cases =
            {
                {
                    .name = "boost_async",
                    .callback = boost_async
                },
                {
                    .name = "std_async",
                    .callback = std_async
                }
            }
        };

        execute_nanobenchmark(
            test_suite
        );

        bool exit_code;
        std::cin >> exit_code;
    }
}




namespace Experiment6 // read (fast_io), write and append (fstream)
{
    inline static std::string file_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    inline static std::string file_output_1 = "";

    inline static std::string file_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    inline static std::string file_output_2 = "";

    inline static std::string file_path_1 = "output_1.txt";

    inline static std::string file_path_2 = "output_2.txt";

    inline static fast_io::native_file fast_io_write_file(file_path_1, fast_io::open_mode::out);

    inline static fast_io::native_file fast_io_append_file(file_path_1, fast_io::open_mode::app);

    inline static fast_io::native_file_loader fast_io_read_file(file_path_1);

    inline static std::ofstream ofstream_write_file(file_path_2, std::ios::out);

    inline static std::ofstream ofstream_append_file(file_path_2, std::ios::app);

    inline static std::ifstream ifstream_read_file(file_path_2, std::ios::in);

    inline static std::fstream fstream_write_file(file_path_2, std::ios::out);

    inline static std::fstream fstream_append_file(file_path_2, std::ios::app);

    inline static std::fstream fstream_read_file(file_path_2, std::ios::in);

    inline static folly::File folly_write_file(file_path_1, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    inline static folly::File folly_append_file(file_path_1, O_WRONLY | O_CREAT | O_APPEND, 0644);

    inline static folly::File folly_read_file(file_path_1, O_RDONLY);

    inline static boost::iostreams::stream<boost::iostreams::file_sink> boost_write_file(
        file_path_1,
        std::ios::trunc
    );

    inline static boost::iostreams::stream<boost::iostreams::file_sink> boost_append_file(
        file_path_1,
        std::ios::app
    );

    inline static boost::iostreams::stream<boost::iostreams::file_source> boost_read_file(
        file_path_1
    );

    void libuv_file_write()
    {
        uv_loop_t* loop = uv_default_loop();
        uv_fs_t open_req;
        uv_fs_open(loop, &open_req, file_path_1.c_str(),
            O_WRONLY | O_CREAT | O_TRUNC, 0644, nullptr);

        if (open_req.result < 0)
        {
            return;
        }

        uv_file file = static_cast<uv_file>(open_req.result);
        uv_fs_req_cleanup(&open_req);

        uv_buf_t buf = uv_buf_init(const_cast<char*>(file_input_1.data()), file_input_1.size());
        uv_fs_t write_req;
        uv_fs_write(loop, &write_req, file, &buf, 1, 0, nullptr);
        uv_fs_req_cleanup(&write_req);

        uv_fs_t close_req;
        uv_fs_close(loop, &close_req, file, nullptr);
        uv_fs_req_cleanup(&close_req);
    }

    void libuv_file_append()
    {
        uv_loop_t* loop = uv_default_loop();
        uv_fs_t open_req;
        uv_fs_open(loop, &open_req, file_path_1.c_str(),
            O_WRONLY | O_CREAT | O_APPEND, 0644, nullptr);

        if (open_req.result < 0)
        {
            return;
        }

        uv_file file = static_cast<uv_file>(open_req.result);
        uv_fs_req_cleanup(&open_req);

        uv_buf_t buf = uv_buf_init(const_cast<char*>(file_input_1.data()), file_input_1.size());
        uv_fs_t write_req;
        uv_fs_write(loop, &write_req, file, &buf, 1, -1, nullptr);
        uv_fs_req_cleanup(&write_req);

        uv_fs_t close_req;
        uv_fs_close(loop, &close_req, file, nullptr);
        uv_fs_req_cleanup(&close_req);
    }

    void libuv_file_read()
    {
        uv_loop_t* loop = uv_default_loop();
        uv_fs_t open_req;
        uv_fs_open(loop, &open_req, file_path_1.c_str(), O_RDONLY, 0, nullptr);

        if (open_req.result < 0)
        {
            return;
        }

        uv_file file = static_cast<uv_file>(open_req.result);
        uv_fs_req_cleanup(&open_req);

        uv_fs_t stat_req;
        uv_fs_fstat(loop, &stat_req, file, nullptr);
        size_t size = stat_req.statbuf.st_size;
        uv_fs_req_cleanup(&stat_req);

        std::string data(size, '\0');
        uv_buf_t buf = uv_buf_init(data.data(), size);
        uv_fs_t read_req;
        uv_fs_read(loop, &read_req, file, &buf, 1, 0, nullptr);
        uv_fs_req_cleanup(&read_req);

        uv_fs_t close_req;
        uv_fs_close(loop, &close_req, file, nullptr);
        uv_fs_req_cleanup(&close_req);
    }

    void folly_file_write()
    {
        const char* buf = file_input_1.data();
        size_t remaining = file_input_1.size();
        while (remaining > 0)
        {
            int written = _write(folly_write_file.fd(), buf, static_cast<unsigned int>(remaining));
            if (written <= 0) break;
            remaining -= written;
            buf += written;
        }
    }

    void folly_file_append()
    {
        const char* buf = file_input_1.data();
        size_t remaining = file_input_1.size();
        while (remaining > 0)
        {
            int written = _write(folly_append_file.fd(), buf, static_cast<unsigned int>(remaining));
            if (written <= 0) break;
            remaining -= written;
            buf += written;
        }
    }

    void folly_file_read()
    {
        long size = _lseek(folly_read_file.fd(), 0, SEEK_END);
        _lseek(folly_read_file.fd(), 0, SEEK_SET);

        std::string buffer(size, '\0');
        char* buf = buffer.data();
        long remaining = size;

        while (remaining > 0)
        {
            int readBytes = _read(folly_read_file.fd(), buf, static_cast<unsigned int>(remaining));
            if (readBytes <= 0) break;
            remaining -= readBytes;
            buf += readBytes;
        }
    }

    void boost_file_write()
    {
        boost_write_file.write(file_input_1.data(), file_input_1.size());
        boost_write_file.flush();
    }

    void boost_file_append()
    {
        boost_append_file.write(file_input_1.data(), file_input_1.size());
        boost_append_file.flush();
    }

    void boost_file_read()
    {
        std::string output;

        boost_read_file.seekg(0, std::ios::end);
        output.resize(static_cast<size_t>(boost_read_file.tellg()));
        boost_read_file.seekg(0, std::ios::beg);
        boost_read_file.read(output.data(), output.size());
    }

    void fast_io_file_write()
    {
        fast_io::io::print(
            fast_io_write_file,
            file_input_1.data(),
            file_input_1.size()
        );

    }

    void fast_io_file_append()
    {
        fast_io::io::print(
            fast_io_append_file,
            file_input_1.data(),
            file_input_1.size()
        );
    }

    void fast_io_file_read()
    {
        std::string output
        {
            fast_io_read_file.begin(),
            fast_io_read_file.end()
        };
    }

    void ofstream_file_write()
    {
        ofstream_write_file << file_input_2;
    }

    void ofstream_file_append()
    {
        ofstream_append_file << file_input_2;
    }

    void ifstream_file_read()
    {
        ifstream_read_file >> file_output_2;
    }

    void fstream_file_write()
    {
        fstream_write_file << file_input_2;
    }

    void fstream_file_append()
    {
        fstream_append_file << file_input_2;
    }

    void fstream_file_read()
    {
        fstream_read_file >> file_output_2;
    }

    void before_test_case_iteration_callback()
    {
        file_output_1 = "";
        file_output_2 = "";

        ofstream_write_file.close();
        ofstream_append_file.close();
        ifstream_read_file.close();
        fstream_write_file.close();
        fstream_append_file.close();
        fstream_read_file.close();

        std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
        ofstream_write_file_temp_1 << "";

        std::ofstream ofstream_write_file_temp_2(file_path_2, std::ios::out);
        ofstream_write_file_temp_2 << "";
    }

    void after_test_case_iteration_callback()
    {
        ofstream_write_file.close();
        ofstream_append_file.close();
        ifstream_read_file.close();
        fstream_write_file.close();
        fstream_append_file.close();
        fstream_read_file.close();

        std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
        ofstream_write_file_temp_1 << "";

        std::ofstream ofstream_write_file_temp_2(file_path_2, std::ios::out);
        ofstream_write_file_temp_2 << "";
    }

    void execute()
    {
        NanobenchBencchmarkingTestSuite test_suite
        {
            .name = "file_io",
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 10'000,
                    .iterations = 1
                },
                {
                    .epochs = 1'000,
                    .iterations = 10
                },
                {
                    .epochs = 100,
                    .iterations = 100
                },
                {
                    .epochs = 10,
                    .iterations = 1'000
                }

            },

            .test_cases =
            {
                {
                    .name = "folly_file_write",
                    .callback = folly_file_write
                },
                {
                    .name = "folly_file_append",
                    .callback = folly_file_append
                },
                {
                    .name = "folly_file_read",
                    .callback = folly_file_read,
                    .before_test_callback = []()
                    {
                        std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
                        ofstream_write_file_temp_1 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
                    }
                },
                {
                    .name = "fast_io_file_write",
                    .callback = fast_io_file_write
                },
                {
                    .name = "fast_io_file_append",
                    .callback = fast_io_file_append
                },
                {
                    .name = "fast_io_file_read",
                    .callback = fast_io_file_read,
                    .before_test_callback = []()
                    {
                        std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
                        ofstream_write_file_temp_1 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
                    }
                },
                {
                    .name = "boost_file_write",
                    .callback = boost_file_write
                },
                {
                    .name = "boost_file_append",
                    .callback = boost_file_append
                },
                {
                    .name = "boost_file_read",
                    .callback = boost_file_read,
                    .before_test_callback = []()
                    {
                        std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
                        ofstream_write_file_temp_1 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
                    }
                },
                {
                    .name = "ofstream_file_write",
                    .callback = ofstream_file_write
                },
                {
                    .name = "ofstream_file_append",
                    .callback = ofstream_file_append
                },
                {
                    .name = "ifstream_file_read",
                    .callback = ifstream_file_read,
                    .before_test_callback = []()
                    {
                        std::ofstream ofstream_write_file_temp_2(file_path_2, std::ios::out);
                        ofstream_write_file_temp_2 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
                    }
                },
                {
                    .name = "fstream_file_write",
                    .callback = fstream_file_write
                },
                {
                    .name = "fstream_file_append",
                    .callback = fstream_file_append
                },
                {
                    .name = "fstream_file_read",
                    .callback = fstream_file_read,
                    .before_test_callback = []()
                    {
                        std::ofstream ofstream_write_file_temp_2(file_path_2, std::ios::out);
                        ofstream_write_file_temp_2 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
                    }
                }
            },

            .before_test_case_iteration_callback =
                before_test_case_iteration_callback,

            .after_test_case_iteration_callback =
                after_test_case_iteration_callback

        };

        execute_nanobenchmark(
            test_suite
        );

        bool exit_code;
        std::cin >> exit_code;
    }
}

*/

/*
{
                    .name = "libuv_file_write",
                    .callback = libuv_file_write
                },
                {
                    .name = "libuv_file_append",
                    .callback = libuv_file_append
                },
                {
                    .name = "libuv_file_read",
                    .callback = libuv_file_read,
                    .before_test_callback = []()
                    {
                        std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
                        ofstream_write_file_temp_1 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
                    }
                },
            std::ofstream json_file(
                benchmark_name + ".json"
            );
            ankerl::nanobench::render(
                ankerl::nanobench::templates::json(),
                benchmarker,
                json_file
            );

            std::ofstream csv_file(
                benchmark_name + ".csv"
            );
            ankerl::nanobench::render(
                ankerl::nanobench::templates::csv(),
                benchmarker,
                csv_file
            );


namespace Experiment8 // nested_try_catch_block. all are proficient
{
    inline static double output_1 = 0.0;

    inline static double input_1 = 1.0;

    void nested_try_catch_block()
    {
        try
        {
            try
            {
                try
                {
                    try
                    {
                        try
                        {
                            try
                            {
                                try
                                {
                                    try
                                    {
                                        try
                                        {
                                            try
                                            {
                                                output_1 =
                                                    input_1 + input_1;
                                            }
                                            catch (...)
                                            {

                                            }
                                        }
                                        catch (...)
                                        {

                                        }
                                    }
                                    catch (...)
                                    {

                                    }
                                }
                                catch (...)
                                {

                                }
                            }
                            catch (...)
                            {

                            }
                        }
                        catch (...)
                        {

                        }
                    }
                    catch (...)
                    {

                    }
                }
                catch (...)
                {

                }
            }
            catch (...)
            {

            }
        }
        catch (std::exception& exception)
        {
            output_1 = 0.0;
        }
        catch (...)
        {

        }
    }

    void with_try_catch_block()
    {
        try
        {
            output_1 =
                input_1 + input_1;
        }
        catch (std::exception& exception)
        {
            output_1 = 0.0;
        }
        catch (...)
        {

        }
    }

    void no_try_catch_block()
    {
        output_1 =
            input_1 + input_1;
    }

    void before_test_case_iteration_callback()
    {
        output_1 = 0.0;
    }

    void execute()
    {
        NanobenchBencchmarkingTestSuite test_suite
        {
            .name = "try_catch",
            .warmup_count = 2,
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 10'000'000,
                    .iterations = 1
                },
                {
                    .epochs = 1'000'000,
                    .iterations = 10
                },
                {
                    .epochs = 100'000,
                    .iterations = 100
                },
                {
                    .epochs = 10'000,
                    .iterations = 1'000
                },
                {
                    .epochs = 1'000,
                    .iterations = 10'000
                },
                {
                    .epochs = 100,
                    .iterations = 100'000
                },
                {
                    .epochs = 10,
                    .iterations = 1'000'000
                },
                {
                    .epochs = 1,
                    .iterations = 10'000'000
                }
            },

            .test_cases =
            {
                {
                    .name = "nested_try_catch_block",
                    .callback = nested_try_catch_block
                },
                {
                    .name = "no_try_catch_block",
                    .callback = no_try_catch_block
                },
                {
                    .name = "with_try_catch_block",
                    .callback = with_try_catch_block
                }
            },

            .before_test_case_iteration_callback =
                before_test_case_iteration_callback
        };

        execute_nanobenchmark(
            test_suite
        );

        bool exit_code;
        std::cin >> exit_code;
    }
}

namespace Experiment7 // no arguments
{
    std::string sum_raw_instance_1_output = "0";

    std::string sum_raw_instance_1_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    std::string sum_raw_instance_1_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    void sum_raw_instance_1()
    {
        sum_raw_instance_1_output =
            sum_raw_instance_1_input_1 +
            sum_raw_instance_1_input_2;
    }

    std::string sum_raw_instance_2_output = "0";

    void sum_raw_instance_2_func(
        std::string input_1,
        std::string input_2
    )
    {
        sum_raw_instance_2_output =
            input_1 + input_2;
    }

    void sum_raw_instance_2()
    {
        sum_raw_instance_2_func(
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        );
    }

    std::string sum_raw_instance_3_func()
    {
        sum_raw_instance_1_output =
            sum_raw_instance_1_input_1 +
            sum_raw_instance_1_input_2;

        return sum_raw_instance_1_output;
    }

    void sum_raw_instance_3()
    {
        sum_raw_instance_3_func();
    }

    inline static std::string sum_raw_static_1_output = "0";

    inline static std::string sum_raw_static_1_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    inline static std::string sum_raw_static_1_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    void sum_raw_static_1()
    {
        sum_raw_static_1_output =
            sum_raw_static_1_input_1 +
            sum_raw_static_1_input_2;
    }

    inline static std::string sum_raw_static_2_output = "0";

    void sum_raw_static_2_func(
        std::string input_1,
        std::string input_2
    )
    {
        sum_raw_static_2_output =
            input_1 + input_2;
    }

    void sum_raw_static_2()
    {
        sum_raw_static_2_func(
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        );
    }

    std::string sum_raw_static_3_func()
    {
        sum_raw_static_1_output =
            sum_raw_static_1_input_1 +
            sum_raw_static_1_input_2;

        return sum_raw_static_1_output;
    }

    void sum_raw_static_3()
    {
        sum_raw_static_3_func();
    }

    class Instance
    {
    public:
        std::string sum_object_instance_1_output = "0";

        std::string sum_object_instance_1_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

        std::string sum_object_instance_1_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

        void sum_object_instance_1()
        {
            sum_object_instance_1_output =
                sum_object_instance_1_input_1 +
                sum_object_instance_1_input_2;
        }

        std::string sum_object_instance_2_output = "0";

        void sum_object_instance_2(
            std::string input_1,
            std::string input_2
        )
        {
            sum_object_instance_2_output =
                input_1 + input_2;
        }

        std::string sum_object_instance_3_func()
        {
            sum_object_instance_1_output =
                sum_object_instance_1_input_1 +
                sum_object_instance_1_input_2;

            return sum_object_instance_1_output;
        }

        void sum_object_instance_3()
        {
            sum_object_instance_3_func();
        }

        inline static std::string sum_object_static_1_output = "0";

        inline static std::string sum_object_static_1_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

        inline static std::string sum_object_static_1_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

        inline static void sum_object_static_1()
        {
            sum_object_static_1_output =
                sum_object_static_1_input_1 +
                sum_object_static_1_input_2;
        }

        inline static std::string sum_object_static_2_output = "0";

        inline static void sum_object_static_2(
            std::string input_1,
            std::string input_2
        )
        {
            sum_object_static_2_output =
                input_1 + input_2;
        }

        inline static std::string sum_object_static_3_func()
        {
            sum_object_static_1_output =
                sum_object_static_1_input_1 +
                sum_object_static_1_input_2;

            return sum_object_static_1_output;
        }

        inline static void sum_object_static_3()
        {
            sum_object_static_3_func();
        }
    };

    Instance object;

    void sum_object_instance_1()
    {
        object.sum_object_instance_1();
    }

    void sum_object_instance_2()
    {
        object.sum_object_instance_2(
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        );
    }

    void sum_object_instance_3()
    {
        object.sum_object_instance_3();
    }

    void sum_object_static_1()
    {
        Instance::sum_object_static_1();
    }

    void sum_object_static_2()
    {
        Instance::sum_object_static_2(
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        );
    }

    void sum_object_static_3()
    {
        Instance::sum_object_static_3();
    }

    void execute()
    {
        NanobenchBencchmarkingTestSuite test_suite
        {
            .name = "object_instance_or_object_static",
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 1'000'000,
                    .iterations = 1
                },
                {
                    .epochs = 100'000,
                    .iterations = 10
                },
                {
                    .epochs = 10'000,
                    .iterations = 100
                },
                {
                    .epochs = 1'000,
                    .iterations = 1'000
                },
                {
                    .epochs = 1,
                    .iterations = 1'000'000
                }
            },

            .test_cases =
            {
                {
                    .name = "sum_raw_instance_1",
                    .callback = sum_raw_instance_1
                },
                {
                    .name = "sum_raw_instance_2",
                    .callback = sum_raw_instance_2
                },
                {
                    .name = "sum_raw_instance_3",
                    .callback = sum_raw_instance_3
                },
                {
                    .name = "sum_raw_static_1",
                    .callback = sum_raw_static_1
                },
                {
                    .name = "sum_raw_static_2",
                    .callback = sum_raw_static_2
                },
                {
                    .name = "sum_raw_static_3",
                    .callback = sum_raw_static_3
                },
                {
                    .name = "sum_object_instance_1",
                    .callback = sum_object_instance_1
                },
                {
                    .name = "sum_object_instance_2",
                    .callback = sum_object_instance_2
                },
                {
                    .name = "sum_object_instance_3",
                    .callback = sum_object_instance_3
                },
                {
                    .name = "sum_object_static_1",
                    .callback = sum_object_static_1
                },
                {
                    .name = "sum_object_static_2",
                    .callback = sum_object_static_2
                },
                {
                    .name = "sum_object_static_3",
                    .callback = sum_object_static_3
                }
            }
        };

        execute_nanobenchmark(
            test_suite
        );

        bool exit_code;
        std::cin >> exit_code;
    }
}



namespace Experiment9 // folly and boost
{
    static folly::MicroSpinLock micro_spin_lock;

    static std::mutex std_mutex;

    static boost::mutex boost_mutex;

    static std::unordered_map<std::string, folly::MicroSpinLock>
        folly_micro_spin_lock_collection;

    void lock_without_map()
    {
        micro_spin_lock.lock();
        micro_spin_lock.unlock();
    }

    void lock_without_map_2()
    {
        try
        {
            micro_spin_lock.lock();
            micro_spin_lock.unlock();
        }
        catch (...)
        {
        }
    }

    void lock_with_map()
    {
        folly_micro_spin_lock_collection["static"].lock();
        folly_micro_spin_lock_collection["static"].unlock();
    }

    void lock_with_std_mutex()
    {
        std::unique_lock<std::mutex> lock(std_mutex);
    }

    void lock_with_boost_mutex()
    {
        boost::unique_lock<boost::mutex> lock(boost_mutex);
    }

    void execute()
    {
        NanobenchBencchmarkingTestSuite test_suite
        {
            .name = "object_instance_or_object_static",
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 1'000'000,
                    .iterations = 1
                },
                {
                    .epochs = 100'000,
                    .iterations = 10
                },
                {
                    .epochs = 10'000,
                    .iterations = 100
                },
                {
                    .epochs = 1'000,
                    .iterations = 1'000
                },
                {
                    .epochs = 1,
                    .iterations = 1'000'000
                }
            },

            .test_cases =
            {
                {
                    .name = "lock_without_map",
                    .callback = lock_without_map
                },
                {
                    .name = "lock_without_map_2",
                    .callback = lock_without_map_2
                },
                {
                    .name = "lock_with_map",
                    .callback = lock_with_map
                },{
                    .name = "lock_with_std_mutex",
                    .callback = lock_with_std_mutex
                },
                {
                    .name = "lock_with_boost_mutex",
                    .callback = lock_with_boost_mutex
                }
            }
        };

        execute_nanobenchmark(
            test_suite
        );

        bool exit_code;
        std::cin >> exit_code;
    }
}



namespace Experiment10 // pure
{
    static std::string benchmark_value = "00000000";

    static std::string pure_static_string_input_value = benchmark_value;

    static std::string pure_static_string_output_value = "";

    struct StructStringSample
    {
        inline static std::string struct_static_string_input_value = benchmark_value;

        inline static std::string struct_static_string_output_value = "";
    };

    class ClassStringSample
    {
    public:
        inline static std::string class_static_string_input_value = benchmark_value;

        inline static std::string class_static_string_output_value = "";
    };

    void pure_static_string()
    {
        pure_static_string_output_value =
            pure_static_string_input_value +
            pure_static_string_input_value;
    }

    void struct_static_string()
    {
        StructStringSample::struct_static_string_output_value =
            StructStringSample::struct_static_string_input_value +
            StructStringSample::struct_static_string_input_value;
    }

    void class_static_string()
    {
        ClassStringSample::class_static_string_output_value =
            ClassStringSample::class_static_string_input_value +
            ClassStringSample::class_static_string_input_value;
    }

    static std::string pure_static_double_input_value = benchmark_value;

    static std::string pure_static_double_output_value = "";

    struct StructDoubleSample
    {
        inline static std::string struct_static_double_input_value = benchmark_value;

        inline static std::string struct_static_double_output_value = "";
    };

    class ClassDoubleSample
    {
    public:
        inline static std::string class_static_double_input_value = benchmark_value;

        inline static std::string class_static_double_output_value = "";
    };

    void pure_static_double()
    {
        pure_static_double_output_value =
            pure_static_double_input_value +
            pure_static_double_input_value;
    }

    void struct_static_double()
    {
        StructDoubleSample::struct_static_double_output_value =
            StructDoubleSample::struct_static_double_input_value +
            StructDoubleSample::struct_static_double_input_value;
    }

    void class_static_double()
    {
        ClassDoubleSample::class_static_double_output_value =
            ClassDoubleSample::class_static_double_input_value +
            ClassDoubleSample::class_static_double_input_value;
    }


    void execute()
    {
        QLogicaeCppCore::RuntimeBenchmarkerTestSuite test_suite_1
        {
            .name = "pure_static_vs_struct_static_vs_class_static",
            .warmup_count = 2,
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 10'000'000,
                    .iterations = 1
                },
                {
                    .epochs = 1'000'000,
                    .iterations = 10
                },
                {
                    .epochs = 100'000,
                    .iterations = 100
                },
                {
                    .epochs = 10'000,
                    .iterations = 1'000
                },
                {
                    .epochs = 1,
                    .iterations = 1'000'000
                }
            },

            .test_cases =
            {
                {
                    .name = "pure_static_string",
                    .callback = pure_static_string
                },
                {
                    .name = "struct_static_string",
                    .callback = struct_static_string
                },
                {
                    .name = "class_static_string",
                    .callback = class_static_string
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


*/