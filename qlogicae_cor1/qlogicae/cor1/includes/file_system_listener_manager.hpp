#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "abstract_class.hpp"
#include "file_system_listener_manager_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		FileSystemListenerManager :
			public QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<FileSystemListenerManagerConfigurations>
    {
    public:
		FileSystemListenerManager();
    };
}

#endif
