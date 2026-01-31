#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "runtime_benchmarker_test_case.hpp"
#include "runtime_benchmarker_test_suite.hpp"
#include "runtime_benchmarker_configurations.hpp"
#include "runtime_benchmarker_epoch_iteration_pair.hpp"

namespace
	QLogicaeCppCore
{    
    class
		RuntimeBenchmarker :
			public AbstractClass<RuntimeBenchmarkerConfigurations>
    {
    public:        
        static RuntimeBenchmarker&
            singleton;

		RuntimeBenchmarker();

		~RuntimeBenchmarker();

		bool
			construct();

		bool
			destruct();

        bool
            execute(
                const RuntimeBenchmarkerTestSuite&
                    test_suite
        );
    };    
}

