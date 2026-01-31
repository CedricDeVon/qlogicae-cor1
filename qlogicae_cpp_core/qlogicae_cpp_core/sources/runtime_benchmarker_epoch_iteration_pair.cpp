#include "pch.hpp"

#include "../includes/runtime_benchmarker_epoch_iteration_pair.hpp"

namespace
	QLogicaeCppCore
{
	RuntimeBenchmarkerEpochIterationPair
		::RuntimeBenchmarkerEpochIterationPair()
	{
		epochs =
			1;

		iterations =
			1;
	}

	RuntimeBenchmarkerEpochIterationPair
		RuntimeBenchmarkerEpochIterationPair
			::initial_configurations;

	RuntimeBenchmarkerEpochIterationPair
		RuntimeBenchmarkerEpochIterationPair
			::default_configurations =
				RuntimeBenchmarkerEpochIterationPair
					::initial_configurations;
}
