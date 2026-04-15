#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "text_manager.hpp"
#include "abstract_class.hpp"
#include "sha256_hash_cryptography_manager_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		Sha256HashCryptographyManager :
			public QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<Sha256HashCryptographyManagerConfigurations>
    {
    public:
		QLOGICAE_COR1__INSTANCE__HPP__MUTEX_LAYER_TEMPLATE
		(
			QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_2
		);

		Sha256HashCryptographyManager();

		std::string
			hash_text(
				const std::string&
					text
			);

		bool
			verify_text(
				const std::string&
					text,
				const std::string&
					hash
			);
    };
}

#endif
