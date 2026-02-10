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
                "";

        std::function<void()>
            callback =
				[]() {};

		std::function<void()>
			before_test_callback =
				[]() {};

		std::function<void()>
			after_test_callback =
				[]() {};
    };
}

