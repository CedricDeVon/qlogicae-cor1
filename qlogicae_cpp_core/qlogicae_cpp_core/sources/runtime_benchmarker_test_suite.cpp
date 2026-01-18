#include "pch.hpp"

#include "../includes/runtime_benchmarker_test_suite.hpp"

namespace
	QLogicaeCppCore
{
	RuntimeBenchmarkerTestSuite
		RuntimeBenchmarkerTestSuite
			::initial_configurations =
				{
					.name =
						"",
					
					.warmup_count =
						1,
					
					.is_relative =
						true,
					
					.epoch_iteration_pairs =
						{},
					
					.test_cases =
						{},
					
					.before_test_suite_callback =
						[]() {},
					
					.before_test_case_callback =
						[]() {},
					
					.before_test_case_iteration_callback =
						[]() {},
					
					.after_test_suite_callback =
						[]() {},
					
					.after_test_case_callback =
						[]() {},
					
					.after_test_case_iteration_callback =
						[]() {},
				};

	RuntimeBenchmarkerTestSuite
		RuntimeBenchmarkerTestSuite
			::default_configurations =
				RuntimeBenchmarkerTestSuite
					::initial_configurations;
}

