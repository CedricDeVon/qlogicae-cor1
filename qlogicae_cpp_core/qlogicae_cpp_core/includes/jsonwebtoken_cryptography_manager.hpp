#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "jsonwebtoken_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		JsonWebTokenCryptographyManager :
			public AbstractClass<JsonWebTokenCryptographyManagerConfigurations>
    {
    public:
        static JsonWebTokenCryptographyManager&
            singleton;

		JsonWebTokenCryptographyManager();

		~JsonWebTokenCryptographyManager();

		bool
			construct();

		bool
			destruct();		

		std::string
			sign(
				const std::string&
					text,
				const std::string&
					public_key,
				const std::string&
					private_key
			);

		std::string
			verify(
				const std::string&
					text,
				const std::string&
					public_key,
				const std::string&
					private_key
			);
    };
}
