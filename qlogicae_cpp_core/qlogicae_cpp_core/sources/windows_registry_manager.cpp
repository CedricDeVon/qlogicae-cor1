#include "pch.hpp"

#include "../includes/windows_registry_manager.hpp"

namespace
	QLogicaeCppCore
{
	WindowsRegistryManager&
        WindowsRegistryManager
			::singleton =
				SingletonManager
					::get_singleton<WindowsRegistryManager>();



    WindowsRegistryManager
		::WindowsRegistryManager() :
			AbstractClass<WindowsRegistryManagerConfigurations>()
	{
		try
		{
			construct();
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
		}		
	}

	WindowsRegistryManager
		::~WindowsRegistryManager()
	{
		try
		{
			destruct();
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
		}		
	}
    
    bool
        WindowsRegistryManager
			::construct()
    {
        try
        {			
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

    bool
        WindowsRegistryManager
			::destruct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

	std::wstring
		WindowsRegistryManager
			::get_value(
				const HKEY&
					root_key,
				const std::wstring&
					sub_key,
				const std::wstring&
					name_key
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
						sub_key.empty() ||
						name_key.empty()
					)
				)
			)
			{
				return
					L"";
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

			HKEY hKey = nullptr;
			if (RegOpenKeyExW(root_key, sub_key.c_str(), 0, KEY_READ, &hKey)
				!= ERROR_SUCCESS)
				return L"";

			std::unique_ptr<std::remove_pointer<HKEY>::type, RegularKeyDeleteHandler>
				key_ptr(hKey);

			DWORD type = 0, size = 0;
			if (RegQueryValueExW(hKey, name_key.c_str(), nullptr, &type, nullptr, &size)
				!= ERROR_SUCCESS || type != REG_SZ)
				return L"";

			std::vector<wchar_t> buffer(size / sizeof(wchar_t));
			if (RegQueryValueExW(hKey, name_key.c_str(), nullptr, &type,
				reinterpret_cast<BYTE*>(buffer.data()), &size) != ERROR_SUCCESS)
				return L"";

			if (!buffer.empty() && buffer.back() == L'\0') buffer.pop_back();
			return std::wstring(buffer.data(), buffer.size());
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
				L"";
        }
	}

	bool
		WindowsRegistryManager
			::set_value(
				const HKEY&
					root_key,
				const std::wstring&
					sub_key,
				const std::wstring&
					name_key,
				const std::wstring&
					value
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
						sub_key.empty() ||
						name_key.empty() ||
						value.empty()
					)
				)
			)
			{
				return
					false;
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
			
			HKEY hKey = nullptr;
			if (RegCreateKeyExW(root_key, sub_key.c_str(), 0, nullptr, 0,
				KEY_WRITE, nullptr, &hKey, nullptr) != ERROR_SUCCESS)
				return false;

			std::unique_ptr<std::remove_pointer<HKEY>::type, RegularKeyDeleteHandler>
				key_ptr(hKey);

			return RegSetValueExW(hKey, name_key.c_str(), 0, REG_SZ,
				reinterpret_cast<const BYTE*>(value.c_str()),
				static_cast<DWORD>((value.size() + 1) * sizeof(wchar_t))) == ERROR_SUCCESS;
		}
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	std::unordered_map<std::wstring, std::wstring>
		WindowsRegistryManager
			::get_values(
				const HKEY&
					root_key,
				const std::wstring&
					sub_key
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
						sub_key.empty()
					)
				)
			)
			{
				return
					{};
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
	
			std::unordered_map<std::wstring, std::wstring> result;
			HKEY hKey = nullptr;
			if (RegOpenKeyExW(root_key, sub_key.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS)
				return result;

			std::unique_ptr<std::remove_pointer<HKEY>::type, ValueEnumKeyDeleteHandler>
				key_ptr(hKey);

			DWORD index = 0;
			while (true)
			{
				wchar_t name[32767] = {};
				DWORD name_len = 32767;
				DWORD type = 0;
				BYTE data[65535] = {};
				DWORD data_len = 65535;

				LONG ret = RegEnumValueW(hKey, index++, name, &name_len, nullptr, &type, data, &data_len);
				if (ret == ERROR_NO_MORE_ITEMS) break;

				if (ret == ERROR_SUCCESS && type == REG_SZ)
				{
					std::wstring key_name(name, name_len);
					std::wstring key_value(reinterpret_cast<wchar_t*>(data), data_len / sizeof(wchar_t));
					if (!key_value.empty() && key_value.back() == L'\0') key_value.pop_back();
					result.emplace(key_name, key_value);
				}
			}

			return result;
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
				{};
        }
	}

	bool
		WindowsRegistryManager
			::remove_value(
				const HKEY&
					root_key,
				const std::wstring&
					sub_key,
				const std::wstring&
					name_key
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
						sub_key.empty() ||
						name_key.empty()
					)
				)
			)
			{
				return
					false;
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

			HKEY hKey = nullptr;
			if (RegOpenKeyExW(root_key, sub_key.c_str(), 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS)
				return false;

			std::unique_ptr<std::remove_pointer<HKEY>::type, RegularKeyDeleteHandler>
				key_ptr(hKey);

			return RegDeleteValueW(hKey, name_key.c_str()) == ERROR_SUCCESS;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		WindowsRegistryManager
			::is_path_found(
				const HKEY&
					root_key,
				const std::wstring&
					sub_key,
				const std::wstring&
					name_key
			)
	{
		try
        {		
			return
				!get_value(
					root_key,
					sub_key,
					name_key
				).empty();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	std::string
		WindowsRegistryManager
			::get_value(
				const HKEY&
					root_key,
				const std::string&
					sub_key,
				const std::string&
					name_key
			)
	{
		try
        {		
			return
				TextManager
					::singleton
						.convert_text<std::wstring, std::string>(
							get_value(
								root_key,
								TextManager
									::singleton
										.convert_text<std::string, std::wstring>(
											sub_key
										),
								TextManager
									::singleton
										.convert_text<std::string, std::wstring>(
											name_key
										)					
							)
						);
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

	bool
		WindowsRegistryManager
			::set_value(
				const HKEY&
					root_key,
				const std::string&
					sub_key,
				const std::string&
					name_key,
				const std::string&
					value
		)
	{
		try
        {		
			return
				set_value(
					root_key,
					TextManager
						::singleton
							.convert_text<std::string, std::wstring>(
								sub_key
							),
					TextManager
						::singleton
							.convert_text<std::string, std::wstring>(
								name_key
							),
					TextManager
						::singleton
							.convert_text<std::string, std::wstring>(
								value
							)					
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	std::unordered_map<std::string, std::string>
		WindowsRegistryManager
			::get_values(
				const HKEY&
					root_key,
				const std::string&
					sub_key
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
						sub_key.empty()
					)
				)
			)
			{
				return
					{};
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

			std::unordered_map<std::string, std::string> result;
			std::wstring wstring_sub_key =
				TextManager
					::singleton
						.convert_text<std::string, std::wstring>(
							sub_key
						);

			HKEY raw_key = nullptr;
			if (RegOpenKeyExW(root_key, wstring_sub_key.data(), 0, KEY_READ, &raw_key) != ERROR_SUCCESS)
			{
				return result;
			}

			std::unique_ptr<std::remove_pointer<HKEY>::type, ValueEnumKeyDeleteHandler> hkey(raw_key);

			DWORD index = 0;
			wchar_t value_name[32767] = { 0 };
			DWORD value_name_size = 32767;
			DWORD value_type = 0;
			BYTE value_data[65535] = { 0 };
			DWORD value_data_size = 65535;

			while (true)
			{
				value_name_size = 32767;
				value_data_size = 65535;

				LONG enum_result = RegEnumValueW(
					hkey.get(),
					index++,
					value_name,
					&value_name_size,
					nullptr,
					&value_type,
					value_data,
					&value_data_size);

				if (enum_result == ERROR_NO_MORE_ITEMS)
				{
					break;
				}

				if (enum_result == ERROR_SUCCESS && value_type == REG_SZ)
				{
					std::wstring name(value_name, value_name_size);
					std::wstring value(reinterpret_cast<wchar_t*>(value_data));
					result.emplace(
						TextManager
							::singleton
								.convert_text<std::wstring, std::string>(
									name
								),
						TextManager
							::singleton
								.convert_text<std::wstring, std::string>(
									value
								)						
					);
				}
			}

			return
				result;
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
				{};
        }
	}

	bool
		WindowsRegistryManager
			::remove_value(
				const HKEY&
					root_key,
				const std::string&
					sub_key,
				const std::string&
					name_key
			)
	{
		try
        {		
			return
				remove_value(
					root_key,
					TextManager
						::singleton
							.convert_text<std::string, std::wstring>(
								sub_key
							),
					TextManager
						::singleton
							.convert_text<std::string, std::wstring>(
								name_key
							)			
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		WindowsRegistryManager
			::is_path_found(
				const HKEY&
					root_key,
				const std::string&
					sub_key,
				const std::string&
					name_key
			)
	{
		try
        {		
			return
				is_path_found(
					root_key,
					TextManager
						::singleton
							.convert_text<std::string, std::wstring>(
								sub_key
							),
					TextManager
						::singleton
							.convert_text<std::string, std::wstring>(
								name_key
							)					
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	std::wstring
		WindowsRegistryManager
			::get_value_via_wstring()
	{
		try
        {		
			return
				get_value(
					configurations.root_key,
					configurations.sub_key,
					configurations.name_key
				);
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
				L"";
        }
	}

	bool
		WindowsRegistryManager
			::set_value_via_wstring(
				const std::wstring&
					value
		)
	{
		try
        {		
			return
				set_value(
					configurations.root_key,
					configurations.sub_key,
					configurations.name_key,
					value
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	std::unordered_map<std::wstring, std::wstring>
		WindowsRegistryManager
			::get_values_via_wstring()
	{
		try
        {		
			return
				get_values(
					configurations.root_key,
					configurations.sub_key
				);
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
				{};
        }
	}

	bool
		WindowsRegistryManager
			::remove_value_via_wstring()
	{
		try
        {		
			return
				remove_value(
					configurations.root_key,
					configurations.sub_key,
					configurations.name_key
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		WindowsRegistryManager
			::is_path_found_via_wstring()
	{
		try
        {		
			return
				is_path_found(
					configurations.root_key,
					configurations.sub_key,
					configurations.name_key
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}



	std::string
		WindowsRegistryManager
			::get_value_via_string()
	{
		try
        {		
			return
				TextManager
					::singleton
						.convert_text<std::wstring, std::string>(
							get_value(
								configurations.root_key,
								configurations.sub_key,
								configurations.name_key
							)
						);
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

	bool
		WindowsRegistryManager
			::set_value_via_string(
				const std::string&
					value
		)
	{
		try
        {		
			return
				set_value(
					configurations.root_key,
					configurations.sub_key,
					configurations.name_key,
					TextManager
						::singleton
							.convert_text<std::string, std::wstring>(
								value
							)					
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	std::unordered_map<std::string, std::string>
		WindowsRegistryManager
			::get_values_via_string()
	{
		try
        {		
			return
				get_values(
					configurations.root_key,
					TextManager
						::singleton
							.convert_text<std::wstring, std::string>(
								configurations.sub_key
							)					
				);				
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
				{};
        }
	}

	bool
		WindowsRegistryManager
			::remove_value_via_string()
	{
		try
        {		
			return
				remove_value(
					configurations.root_key,
					configurations.sub_key,
					configurations.name_key
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		WindowsRegistryManager
			::is_path_found_via_string()
	{
		try
        {		
			return
				is_path_found(
					configurations.root_key,
					configurations.sub_key,
					configurations.name_key
				);		
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}
}
