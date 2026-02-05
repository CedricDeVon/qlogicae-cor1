#include "pch.hpp"

#include "../includes/qlogicae_application_manager.hpp"

namespace
	QLogicaeCppCore
{
    QLogicaeApplicationManager&
        QLogicaeApplicationManager
			::singleton =
				SingletonManager
					::get_singleton<QLogicaeApplicationManager>();



	QLogicaeApplicationManager
		::QLogicaeApplicationManager() :
			AbstractClass<QLogicaeApplicationManagerConfigurations>()
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

    QLogicaeApplicationManager
		::~QLogicaeApplicationManager()
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
        QLogicaeApplicationManager
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
        QLogicaeApplicationManager
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

