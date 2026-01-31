#include "pch.hpp"

#include "../includes/runtime_benchmarker_test_case.hpp"

namespace
	QLogicaeCppCore
{
	RuntimeBenchmarkerTestCase
		::RuntimeBenchmarkerTestCase()
	{
		name =
			"";

		callback =
			[]() {};

		before_test_callback =
			[]() {};

		after_test_callback =
			[]() {};
	}

	RuntimeBenchmarkerTestCase
		RuntimeBenchmarkerTestCase
			::initial_configurations;

	RuntimeBenchmarkerTestCase
		RuntimeBenchmarkerTestCase
			::default_configurations =
				RuntimeBenchmarkerTestCase
					::initial_configurations;
}
