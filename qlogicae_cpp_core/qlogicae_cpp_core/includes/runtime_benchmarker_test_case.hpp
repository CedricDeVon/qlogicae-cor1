#pragma once

namespace
	QLogicae::Cor::V1
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

