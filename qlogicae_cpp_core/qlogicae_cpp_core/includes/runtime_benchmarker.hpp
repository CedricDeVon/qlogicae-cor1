#pragma once

#include "abstract_class.hpp"
#include "runtime_benchmarker_test_case.hpp"
#include "runtime_benchmarker_test_suite.hpp"
#include "runtime_benchmarker_configurations.hpp"
#include "runtime_benchmarker_epoch_iteration_pair.hpp"

namespace
	QLogicae::Cor::V1
{    
    class
		RuntimeBenchmarker :
			public AbstractClass<RuntimeBenchmarkerConfigurations>
    {
    public:        
		RuntimeBenchmarker();

        bool
            execute(
                const RuntimeBenchmarkerTestSuite&
                    test_suite
        );
    };    
}

