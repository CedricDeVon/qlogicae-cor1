#pragma once

#include "runtime_benchmarker_test_case.hpp"
#include "runtime_benchmarker_epoch_iteration_pair.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RuntimeBenchmarkerTestSuite
    {
	public:
        std::string
            name =
				"";

        size_t
            warmup_count =
                1;

        bool
            is_relative =
                true;

        std::vector<RuntimeBenchmarkerEpochIterationPair>
            epoch_iteration_pairs =
				{};

        std::vector<RuntimeBenchmarkerTestCase>
            test_cases =
				{};

        std::function<void()>
            before_test_suite_callback =
				[]() {};

		std::function<void()>
			before_test_case_callback =
				[]() {};

		std::function<void()>
			before_test_case_iteration_callback =
				[]() {};

		std::function<void()>
			after_test_suite_callback =
				[]() {};

		std::function<void()>
			after_test_case_callback =
				[]() {};

		std::function<void()>
			after_test_case_iteration_callback =
				[]() {};
    };
}

