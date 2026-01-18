#pragma once

namespace
	QLogicaeCppCore
{
    struct
		RuntimeBenchmarkerTestCase
    {
	public:
        std::string
            name =
                default_configurations
					.name;

        std::function<void()>
            callback =
                default_configurations
					.callback;

        std::function<void()>
            before_test_callback =
                default_configurations
					.before_test_callback;

        std::function<void()>
            after_test_callback =
                default_configurations
					.after_test_callback;



		static RuntimeBenchmarkerTestCase
			initial_configurations;

		static RuntimeBenchmarkerTestCase
			default_configurations;
    };
}
