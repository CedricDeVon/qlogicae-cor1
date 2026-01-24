#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "regular_expression_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RegularExpressionManager :
			public AbstractClass<RegularExpressionManagerConfigurations>
    {
    public:
		static RegularExpressionManager&
			singleton;

		RegularExpressionManager();

		~RegularExpressionManager();

		bool
			construct();

		bool
			destruct();

		bool
			is_direct_pattern_matched(
				const std::string&
					value,
				const std::string&
					pattern
			);

		bool
			is_direct_pattern_matched(
				const std::string&
					value
			);

		bool
			is_pattern_matched(
				const std::string&
					value,
				pcre2_code*
					error_code
			);
	};
}
