#include "pch.hpp"

#include "../includes/runtime_benchmarker.hpp"

namespace QLogicaeCppCore
{
	RuntimeBenchmarker&
        RuntimeBenchmarker::singleton =
            SingletonManager::get_singleton<RuntimeBenchmarker>();

    RuntimeBenchmarker::RuntimeBenchmarker()
    {
        _construct();
    }

    RuntimeBenchmarker::~RuntimeBenchmarker()
    {
        _destruct();
    }

    bool
        RuntimeBenchmarker::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    bool
        RuntimeBenchmarker::destruct()
    {
        _destruct();

        return
            ValueCache::boolean_1;
    }

    bool
        RuntimeBenchmarker::setup()
    {
        _setup();

        return
            ValueCache::boolean_1;
    }

    bool
        RuntimeBenchmarker::reset()
    {
        _reset();

        return
            ValueCache::boolean_1;
    }

    bool
        RuntimeBenchmarker::execute(
            const RuntimeBenchmarkerTestSuite&
                test_suite
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

    void
        RuntimeBenchmarker::_construct()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        RuntimeBenchmarker::_destruct()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        RuntimeBenchmarker::_setup()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        RuntimeBenchmarker::_reset()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
