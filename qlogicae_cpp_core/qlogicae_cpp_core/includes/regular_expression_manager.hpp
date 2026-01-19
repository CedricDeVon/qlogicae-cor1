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
		std::unordered_map<std::string, std::pair<std::string, pcre2_code*>>
			compiled_patterns;

		static RegularExpressionManager&
			singleton;

		RegularExpressionManager();

		~RegularExpressionManager();

		bool
			construct();

		bool
			destruct();

		bool
			reset() override;

		std::string
			get_pattern(
				const std::string&
					name
			);

		bool
			is_pattern_found(
				const std::string&
					name
			);

		bool
			add_pattern(
				const std::string&
					name,
				const std::string&
					pattern
			);

		bool
			is_named_pattern_matched(
				const std::string&
					name,
				const std::string&
					pattern
			);

		bool
			is_direct_pattern_matched(
				const std::string&
					name,
				const std::string&
					pattern
			);

		bool
			remove_pattern(
				const std::string&
					name
			);

		void
			clear_all_patterns();
		
		bool is_match(
			const std::string&
				subject,
			pcre2_code*
				error_code
		);
	};
}
