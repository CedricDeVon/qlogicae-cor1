#include "pch.hpp"

#include "../includes/json_text_manager.hpp"

namespace
	QLogicaeCppCore
{        
	JsonTextManager&
		JsonTextManager
			::singleton = 
				SingletonManager
					::get_singleton<JsonTextManager>();	


	
	JsonTextManager
		::JsonTextManager() :
			AbstractClass<JsonTextManagerConfigurations>()
    {
        
    }

	
	std::string
		JsonTextManager
			::get_text(
				const std::string&
					file_path
			)
	{

	}

	bool
		JsonTextManager
			::set_text(
				const std::string&
					file_path,
				const std::string&
					value
			)
	{

	}

	std::string
		JsonTextManager
			::build_text(
				const std::string&
					file_path,
				const std::string&
					value
			)
	{

	}

	bool
		JsonTextManager
			::is_valid(
				const std::string&
					file_path
			)
	{

	}

	bool
		JsonTextManager
			::is_key_path_valid(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{

	}

	std::string
		JsonTextManager
			::get_raw_json(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{

	}

	std::string
		JsonTextManager
			::get_string(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{

	}

	double
		JsonTextManager
			::get_double(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{

	}

	bool
		JsonTextManager
			::get_boolean(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{

	}

	std::nullptr_t
		JsonTextManager
			::get_null(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{

	}

	bool
		JsonTextManager
			::set_raw_json(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{

	}

	bool
		JsonTextManager
			::set_string(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{

	}

	bool
		JsonTextManager
			::set_double(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			)
	{

	}

	bool
		JsonTextManager
			::set_boolean(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			)
	{

	}

	bool
		JsonTextManager
			::set_null(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
					value
			)
	{

	}

	bool
		JsonTextManager
			::append_raw_json(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{

	}

	bool
		JsonTextManager
			::append_string(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{

	}

	bool
		JsonTextManager
			::append_double(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			)
	{

	}

	bool
		JsonTextManager
			::append_boolean(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			)
	{

	}

	bool
		JsonTextManager
			::append_null(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
					value
			)
	{

	}

	bool
		JsonTextManager
			::remove_value(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{

	}



	std::string
		JsonTextManager
			::get_text()
	{
		return
			get_text(
				configurations
					.file_path
			);
	}

	bool
		JsonTextManager
			::set_text(
				const std::string&
					value
			)
	{
		return
			set_text(
				configurations
					.file_path,
				value
			);
	}

	std::string
		JsonTextManager
			::build_text(
				const std::string&
					value
			)
	{
		return
			build_text(
				configurations
					.file_path,
				value
			);
	}

	bool
		JsonTextManager
			::is_valid()
	{
		return
			is_valid(
				configurations
					.file_path
			);
	}

	bool
		JsonTextManager
			::is_key_path_valid(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			is_key_path_valid(
				configurations
					.file_path,
				key_path
			);
	}

	std::string
		JsonTextManager
			::get_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_raw_json(
				configurations
					.file_path,
				key_path
			);
	}

	std::string
		JsonTextManager
			::get_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_string(
				configurations
					.file_path,
				key_path
			);
	}

	double
		JsonTextManager
			::get_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_double(
				configurations
					.file_path,
				key_path
			);
	}

	bool
		JsonTextManager
			::get_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_boolean(
				configurations
					.file_path,
				key_path
			);
	}

	std::nullptr_t
		JsonTextManager
			::get_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_null(
				configurations
					.file_path,
				key_path
			);
	}

	bool
		JsonTextManager
			::set_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		return
			set_raw_json(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::set_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		return
			set_string(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::set_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			)
	{
		return
			set_double(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::set_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			)
	{
		return
			set_boolean(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::set_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
					value
			)
	{
		return
			set_null(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::append_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		return
			append_raw_json(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::append_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		return
			append_string(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::append_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			)
	{
		return
			append_double(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::append_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			)
	{
		return
			append_boolean(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::append_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
					value
			)
	{
		return
			append_null(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonTextManager
			::remove_value(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			remove_value(
				configurations
					.file_path,
				key_path
			);
	}
}
