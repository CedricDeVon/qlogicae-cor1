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

			HKEY raw_key = nullptr;
			if (RegOpenKeyExW(root_key, sub_key.data(),
				0, KEY_READ | KEY_SET_VALUE, &raw_key) != ERROR_SUCCESS)
			{
				return L"";
			}

			DWORD hkey_value_type = 0, hkey_value_size = 0;
			std::unique_ptr<
				std::remove_pointer<HKEY>::type,
				RegularKeyDeleteHandler> hKey(raw_key);
			if (RegQueryValueExW(hKey.get(), name_key.empty() ?
				nullptr : name_key.data(), nullptr,
				&hkey_value_type, nullptr, &hkey_value_size) !=
				ERROR_SUCCESS || hkey_value_type != REG_SZ)
			{
				return L"";
			}

			if (hkey_value_size > (1 << 16))
			{
				return L"";
			}

			std::vector<wchar_t> hkey_value_buffer(
				(hkey_value_size / sizeof(wchar_t)) + 1);
			if (!(RegQueryValueExW(hKey.get(), name_key.empty() ?
				nullptr : name_key.data(), nullptr, &hkey_value_type,
				reinterpret_cast<LPBYTE>(
					hkey_value_buffer.data()), &hkey_value_size) ==
				ERROR_SUCCESS && hkey_value_type == REG_SZ))
			{
				return L"";
			}

			hkey_value_buffer.back() = L'\0';

			return
				std::wstring(hkey_value_buffer.data());
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

			HKEY raw_key = nullptr;
			if (RegCreateKeyExW(root_key, sub_key.data(), 0, nullptr, 0,
				KEY_SET_VALUE, nullptr, &raw_key, nullptr) != ERROR_SUCCESS)
			{
				return false;
			}
			std::unique_ptr<
				std::remove_pointer<HKEY>::type, RegularKeyDeleteHandler>
					hKey(
						raw_key
					);

			return
					RegSetValueExW(hKey.get(), name_key.data(), 0, REG_SZ,
				reinterpret_cast<const BYTE*>(value.data()),
				static_cast<DWORD>(
					(value.size() + 1) * sizeof(wchar_t))) == ERROR_SUCCESS;
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

			HKEY raw_key = nullptr;
			if (RegOpenKeyExW(root_key, sub_key.data(), 0, KEY_READ, &raw_key) != ERROR_SUCCESS)
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
					result.emplace(name, value);
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
				const std::wstring&
					sub_key,
				const std::wstring&
					name_key
			)
	{
		try
        {		
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

			HKEY raw_key = nullptr;
			if (RegOpenKeyExW(root_key, sub_key.data(), 0,
				KEY_SET_VALUE, &raw_key) != ERROR_SUCCESS)
			{
				return false;
			}
			std::unique_ptr<
				std::remove_pointer<HKEY>::type,
				RegularKeyDeleteHandler> hKey(raw_key);

			return
				RegDeleteValueW(
					hKey.get(),
					name_key.data()
				) == ERROR_SUCCESS;
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
