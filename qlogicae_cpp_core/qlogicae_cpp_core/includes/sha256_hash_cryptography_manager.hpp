#pragma once

#include "text_manager.hpp"
#include "abstract_class.hpp"
#include "sha256_hash_cryptography_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		Sha256HashCryptographyManager :
			public AbstractClass<Sha256HashCryptographyManagerConfigurations>
    {
    public:
		QLOGICAE_COR_V1__INSTANCE__HPP__MUTEX_LAYER_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_2
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
