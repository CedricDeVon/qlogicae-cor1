#include "pch.hpp"

#include "../includes/text_case_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{   
    TextCaseManager
		::TextCaseManager() :
			AbstractClass<TextCaseManagerConfigurations>()
	{
				
	}
	
	std::string
		TextCaseManager
			::convert_text(
				const std::string&
					text,
				const TextCase&
					target_type
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						text.empty() ||
						target_type == TextCase::NONE
					)
				)
			)
			{
				return
					text;
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

			std::string result = text;
			if (configurations.is_specified_length_enabled)
			{
				result.resize(
					configurations.specified_length
				);
			}

			switch (target_type)
			{
				case TextCase::LOWERCASE:
				{					
					for (char& character : result)
					{
						character =
								static_cast<char>(
									std::tolower(static_cast<unsigned char>(
										character
									)
								)
							);
					}

					return result;
				}

				case TextCase::UPPERCASE:
				{
					for (char& character : result)
					{
						character =
								static_cast<char>(
									std::toupper(static_cast<unsigned char>(
										character
									)
								)
							);
					}

					return result;
				}

				case TextCase::CAPITALIZE:
				{
					bool done = false;

					for (char& character : result)
					{
						if (std::isalpha(static_cast<unsigned char>(character)))
						{
							character =
								static_cast<char>(
									std::toupper(static_cast<unsigned char>(
										character
									)
								)
							);
							done = true;
							break;
						}
					}

					return result;
				}

				case TextCase::TITLE:
				{
					bool capitalize_next = true;

					for (char& character : result)
					{
						if (std::isspace(static_cast<unsigned char>(character)))
						{
							capitalize_next = true;
							continue;
						}

						if (capitalize_next && std::isalpha(static_cast<unsigned char>(character)))
						{
							character =
								static_cast<char>(
									std::toupper(static_cast<unsigned char>(character))
								);
								capitalize_next = false;
							}
						else
						{
							character =
								static_cast<char>(
									std::tolower(static_cast<unsigned char>(character))
								);
							}
						}

					return result;
				}

				case TextCase::SENTENCE:
				{
					bool capitalize_next = true;

					for (char& character : result)
					{
						if (capitalize_next && std::isalpha(static_cast<unsigned char>(character)))
						{
							character =
								static_cast<char>(
									std::toupper(static_cast<unsigned char>(character))
								);
								capitalize_next = false;
							}
						else
						{
							character =
								static_cast<char>(
									std::tolower(static_cast<unsigned char>(character))
								);
							}

						if (character == '.' || character == '!' || character == '?')
						{
							capitalize_next = true;
						}
					}

					return result;
				}

				default:
				{
					return result;
				}
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
				"";
        }
	}
		
	std::string
		TextCaseManager
			::convert_text(
				const std::string&
					text
			)
	{
		return
			convert_text(
				text,
				configurations
					.target_type
			);
	}
}
