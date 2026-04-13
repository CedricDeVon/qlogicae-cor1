#pragma once

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
