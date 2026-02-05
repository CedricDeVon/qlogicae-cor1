#include "pch.hpp"

#include "../includes/qlogicae_file_system_manager.hpp"

namespace
	QLogicaeCppCore
{
    QLogicaeFileSystemManager&
        QLogicaeFileSystemManager
			::singleton =
				SingletonManager
					::get_singleton<QLogicaeFileSystemManager>();



	QLogicaeFileSystemManager
		::QLogicaeFileSystemManager() :
			AbstractClass<QLogicaeFileSystemManagerConfigurations>()
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

    QLogicaeFileSystemManager
		::~QLogicaeFileSystemManager()
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
        QLogicaeFileSystemManager
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
        QLogicaeFileSystemManager
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
}

