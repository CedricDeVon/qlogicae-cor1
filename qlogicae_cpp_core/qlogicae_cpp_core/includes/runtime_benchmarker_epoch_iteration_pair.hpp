#pragma once

namespace
	QLogicaeCppCore
{
    struct
		RuntimeBenchmarkerEpochIterationPair
    {
	public:
        std::size_t
            epochs =
                default_configurations
					.epochs;

        std::size_t
            iterations =
                default_configurations
					.iterations;



		static RuntimeBenchmarkerEpochIterationPair
			initial_configurations;

		static RuntimeBenchmarkerEpochIterationPair
			default_configurations;
    };
}
