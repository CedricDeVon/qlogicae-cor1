#pragma once

#include "abstract_class.hpp"
#include "edsca_signature_cryptography_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		EdscaSignatureCryptographyManager :
			public AbstractClass<EdscaSignatureCryptographyManagerConfigurations>
    {
    public:
		EdscaSignatureCryptographyManager();

		bool
			construct();

		std::vector<std::uint8_t>
			sign(
				const std::vector<std::uint8_t>&
					text,
				const std::vector<std::uint8_t>&
					private_key
			);

		bool
			verify(
				const std::vector<std::uint8_t>&
					text,
				const std::vector<std::uint8_t>&
					public_key,
				const std::vector<std::uint8_t>&
					signature
			);

		std::string
			sign(
				const std::string&
					text,
				const std::string&
					private_key
			);

		bool
			verify(
				const std::string&
					text,
				const std::string&
					public_key,
				const std::string&
					signature
			);
    };
}

