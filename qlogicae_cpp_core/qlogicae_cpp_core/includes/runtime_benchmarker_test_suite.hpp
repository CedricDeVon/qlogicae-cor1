#pragma once

#include "runtime_benchmarker_test_case.hpp"
#include "runtime_benchmarker_epoch_iteration_pair.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RuntimeBenchmarkerTestSuite
    {
        std::string
            name =
                default_configurations
					.name;

        size_t
            warmup_count =
                default_configurations
					.warmup_count;

        bool
            is_relative =
                default_configurations
					.is_relative;

        std::vector<RuntimeBenchmarkerEpochIterationPair>
            epoch_iteration_pairs =
                default_configurations
					.epoch_iteration_pairs;

        std::vector<RuntimeBenchmarkerTestCase>
            test_cases =
                default_configurations
					.test_cases;

        std::function<void()>
            before_test_suite_callback =
                default_configurations
					.before_test_suite_callback;

        std::function<void()>
            before_test_case_callback =
                default_configurations
					.before_test_case_callback;

        std::function<void()>
            before_test_case_iteration_callback =
                default_configurations
					.before_test_case_iteration_callback;

        std::function<void()>
            after_test_suite_callback =
                default_configurations
					.after_test_suite_callback;

        std::function<void()>
            after_test_case_callback =
                default_configurations
					.after_test_case_callback;

        std::function<void()>
            after_test_case_iteration_callback =
                default_configurations
					.after_test_case_iteration_callback;



		static RuntimeBenchmarkerTestSuite
			initial_configurations;

		static RuntimeBenchmarkerTestSuite
			default_configurations;
    };
}
