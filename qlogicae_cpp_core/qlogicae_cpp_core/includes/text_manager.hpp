#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		TextManager :
			public AbstractClass<TextManagerConfigurations>
    {
    public:
		static TextManager&
			singleton;

		TextManager();

		~TextManager();

		bool
			construct();

		bool
			destruct();

		template <typename InputType, typename OutputType> OutputType
			convert_text(
				InputType
					text
			);

		std::string
			replace_text_tokens(
				const std::string&
					text,
				const std::unordered_map<std::string, std::string>&
					dictionary
			);

		std::vector<std::string>
			split_text(
				const std::string&
					text,
				const std::string&
					delimeter
			);	
	};

	template <typename InputType, typename OutputType> OutputType
		TextManager::
			convert_text(
				InputType
					text
			)
	{
		using input_type  = std::decay_t<InputType>;
		using output_type = std::decay_t<OutputType>;

		if constexpr (
			std::is_same_v<output_type, std::string> ||
			std::is_same_v<output_type, std::wstring>
		)
		{
			if constexpr (
				std::is_same_v<input_type, std::wstring> ||
				std::is_same_v<input_type, wchar_t*> ||
				std::is_same_v<input_type, const wchar_t*>
			)
			{
				std::wstring wide =
					std::is_same_v<input_type, std::wstring>
						? text
						: (!text.empty() ? std::wstring(text) : std::wstring());

				if constexpr (std::is_same_v<output_type, std::wstring>)
				{
					return wide;
				}
				else
				{
					if (wide.empty())
					{
						return {};
					}

					int required_size =
						WideCharToMultiByte(
							CP_UTF8,
							0,
							wide.data(),
							static_cast<int>(wide.size()),
							nullptr,
							0,
							nullptr,
							nullptr
						);

					if (required_size <= 0)
					{
						return {};
					}

					std::string result(required_size, '\0');

					WideCharToMultiByte(
						CP_UTF8,
						0,
						wide.data(),
						static_cast<int>(wide.size()),
						result.data(),
						required_size,
						nullptr,
						nullptr
					);

					return result;
				}
			}
			else if constexpr (
				std::is_same_v<input_type, std::string> ||
				std::is_same_v<input_type, char*> ||
				std::is_same_v<input_type, const char*>
			)
			{
				std::string narrow =
					std::is_same_v<input_type, std::string>
						? text
						: (!text.empty() ? std::string(text) : std::string());

				if constexpr (std::is_same_v<output_type, std::string>)
				{
					return narrow;
				}
				else
				{
					if (narrow.empty())
					{
						return {};
					}

					int required_size =
						MultiByteToWideChar(
							CP_UTF8,
							0,
							narrow.data(),
							static_cast<int>(narrow.size()),
							nullptr,
							0
						);

					if (required_size <= 0)
					{
						return {};
					}

					std::wstring result(required_size, L'\0');

					MultiByteToWideChar(
						CP_UTF8,
						0,
						narrow.data(),
						static_cast<int>(narrow.size()),
						result.data(),
						required_size
					);

					return result;
				}
			}
			else
			{
				return {};
			}
		}
		else
		{
			return {};
		}
	}
}
