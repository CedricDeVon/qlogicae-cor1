#pragma once

#include "abstract_class.hpp"
#include "text_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		TextManager :
			public AbstractClass<TextManagerConfigurations>
    {
    public:
		TextManager();

		~TextManager();

		bool
			construct();

		bool
			destruct();

		std::string
			replace_text_tokens(
				const std::string&
					text,
				const std::unordered_map<std::string, std::string>&
					dictionary
			);

		std::string
			replace_text_tokens(
				const std::string&
					text
			);

		std::vector<std::string>
			split_text(
				const std::string&
					text,
				const std::string&
					delimeter
			);	

		std::vector<std::string>
			split_text(
				const std::string&
					text
			);	

		template <typename InputType, typename OutputType> OutputType
			convert_text(
				InputType
					text
			);
	};

	template <typename InputType, typename OutputType> OutputType
		TextManager::
			convert_text(
				InputType
					text
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					OutputType {};
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

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
							return OutputType{};
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
							return OutputType{};
						}

						std::string result(
							static_cast<std::size_t>(required_size),
							'\0'
						);

						WideCharToMultiByte(
							CP_UTF8,
							0,
							wide.c_str(),
							static_cast<int>(wide.size()),
							&result[0],
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
							return OutputType{};
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
							return OutputType{};
						}

						std::wstring result(
							static_cast<std::size_t>(required_size),
							L'\0'
						);

						MultiByteToWideChar(
							CP_UTF8,
							0,
							narrow.c_str(),
							static_cast<int>(narrow.size()),
							&result[0],
							required_size
						);

						return result;
					}
				}
				else
				{
					return OutputType{};
				}
			}
			else
			{
				return OutputType{};
			}
		}
		catch
		(
			const std::exception& 
				exception
		)
		{
			handle_error_outputs(
				exception
			);


			return
				OutputType{};
		}
	}
}

