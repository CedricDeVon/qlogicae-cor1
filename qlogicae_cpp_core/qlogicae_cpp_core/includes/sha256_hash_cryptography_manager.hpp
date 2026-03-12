#pragma once

#include "text_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "sha256_hash_cryptography_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		Sha256HashCryptographyManager :
			public AbstractClass<Sha256HashCryptographyManagerConfigurations>
    {
    public:
		boost::mutex
			feature_handling_mutex_2;

        static Sha256HashCryptographyManager&
            singleton;

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
