#include "pch.hpp"

#include "../includes/runtime_benchmarker.hpp"

namespace QLogicaeCppCore
{	    
    RuntimeBenchmarker&
        RuntimeBenchmarker::singleton =
            SingletonManager::get_singleton<RuntimeBenchmarker>();



    RuntimeBenchmarker::RuntimeBenchmarker()
    {
        try
        {
            RuntimeBenchmarkerConfigurations::cache_configurations =
                {};

            _handle_construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    RuntimeBenchmarker::~RuntimeBenchmarker()
    {
        try
        {
            RuntimeBenchmarkerConfigurations::cache_configurations =
                {};

            _handle_destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }

    bool
        RuntimeBenchmarker::construct(
            const RuntimeBenchmarkerConfigurations&
                configurations
        )
    {
        RuntimeBenchmarkerConfigurations::cache_configurations =
            configurations;

        _handle_construct();

        return
            RuntimeBenchmarkerUtilities::cache_boolean_1;
    }

    bool
        RuntimeBenchmarker::destruct(
            const RuntimeBenchmarkerConfigurations&
                configurations
        )
    {
        RuntimeBenchmarkerConfigurations::cache_configurations =
            configurations;

        _handle_destruct();

        return
            RuntimeBenchmarkerUtilities::cache_boolean_1;
    }

    bool
        RuntimeBenchmarker::setup(
            const RuntimeBenchmarkerConfigurations&
                configurations
        )
    {
        RuntimeBenchmarkerConfigurations::cache_configurations =
            configurations;

        _handle_setup();

        return
            RuntimeBenchmarkerUtilities::cache_boolean_1;
    }

    bool
        RuntimeBenchmarker::reset(
            const RuntimeBenchmarkerConfigurations&
                configurations
        )
    {
        RuntimeBenchmarkerConfigurations::cache_configurations =
            configurations;

        _handle_reset();

        return
            RuntimeBenchmarkerUtilities::cache_boolean_1;
    }

    bool
        RuntimeBenchmarker::execute(
            const RuntimeBenchmarkerTestSuite&
                test_suite,
            const RuntimeBenchmarkerConfigurations&
                configurations
        )
    {
        RuntimeBenchmarkerConfigurations::cache_configurations =
            configurations;
        RuntimeBenchmarkerConfigurations::_handle_setup_caches();

        if (!RuntimeBenchmarkerConfigurations::cache_is_enabled)
        {
            RuntimeBenchmarkerConfigurations::cache_configurations =
            {};
            RuntimeBenchmarkerConfigurations::_handle_setup_caches();
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
                false;

            return
                RuntimeBenchmarkerUtilities::cache_boolean_1;
        }

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
                    test_suite_name + "::" + test_case_name + "::" + std::to_string(iterations);

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

        RuntimeBenchmarkerConfigurations::cache_configurations =
            {};
        RuntimeBenchmarkerConfigurations::_handle_setup_caches();
    }

    void
        RuntimeBenchmarker::_handle_construct()
    {
        try
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        RuntimeBenchmarker::_handle_destruct()
    {
        try
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        RuntimeBenchmarker::_handle_setup()
    {
        try
        {
            RuntimeBenchmarkerUtilities::singleton._handle_setup();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        RuntimeBenchmarker::_handle_reset()
    {
        try
        {
            RuntimeBenchmarkerUtilities::singleton._handle_reset();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
