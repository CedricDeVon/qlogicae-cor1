#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "abstract_class.hpp"
#include "kyber_cryptography_algorithm_enum_manager.hpp"
#include "kyber_cryptography_manager_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		KyberCryptographyManager :
			public QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<KyberCryptographyManagerConfigurations>
    {
    public:
		KyberCryptographyManager();

		bool
			generate_keypair(
				const KyberCryptographyAlgorithm&
					algorithm,
				std::vector<uint8_t>&
					public_key,
				std::vector<uint8_t>&
					private_key
			);

		bool
			encrypt_text(
				const KyberCryptographyAlgorithm&
					algorithm,
				const std::vector<uint8_t>&
					public_key,
				std::vector<uint8_t>&
					ciphertext,
				std::vector<uint8_t>&
					shared_secret
			);

		bool
			decrypt_text(
				const KyberCryptographyAlgorithm&
					algorithm,
				const std::vector<uint8_t>&
					private_key,
				const std::vector<uint8_t>&
					ciphertext,
				std::vector<uint8_t>&
					shared_secret
			);

		bool
			generate_keypair(
				std::vector<uint8_t>&
					public_key,
				std::vector<uint8_t>&
					private_key
			);

		bool
			encrypt_text(
				const std::vector<uint8_t>&
					public_key,
				std::vector<uint8_t>&
					ciphertext,
				std::vector<uint8_t>&
					shared_secret
			);

		bool
			decrypt_text(
				const std::vector<uint8_t>&
					private_key,
				const std::vector<uint8_t>&
					ciphertext,
				std::vector<uint8_t>&
					shared_secret
			);
	};
}

#endif


/*

#include "post_quantum_crypto.hpp"

#include <oqs/oqs.h>

bool PostQuantumCrypto::dilithium_generate_keypair(
    const std::string& algorithm,
    std::vector<uint8_t>& public_key,
    std::vector<uint8_t>& private_key
)
{
    OQS_SIG* sig = OQS_SIG_new(algorithm.c_str());
    if (sig == nullptr)
    {
        return false;
    }

    public_key.resize(sig->length_public_key);
    private_key.resize(sig->length_secret_key);

    if (OQS_SIG_keypair(sig, public_key.data(), private_key.data()) != OQS_SUCCESS)
    {
        OQS_SIG_free(sig);
        return false;
    }

    OQS_SIG_free(sig);
    return true;
}

bool PostQuantumCrypto::dilithium_sign(
    const std::string& algorithm,
    const std::vector<uint8_t>& private_key,
    const std::vector<uint8_t>& message,
    std::vector<uint8_t>& signature
)
{
    OQS_SIG* sig = OQS_SIG_new(algorithm.c_str());
    if (sig == nullptr)
    {
        return false;
    }

    signature.resize(sig->length_signature);
    size_t signature_len = 0;

    if (OQS_SIG_sign(
        sig,
        signature.data(),
        &signature_len,
        message.data(),
        message.size(),
        private_key.data()
    ) != OQS_SUCCESS)
    {
        OQS_SIG_free(sig);
        return false;
    }

    signature.resize(signature_len);

    OQS_SIG_free(sig);
    return true;
}

bool PostQuantumCrypto::dilithium_verify(
    const std::string& algorithm,
    const std::vector<uint8_t>& public_key,
    const std::vector<uint8_t>& message,
    const std::vector<uint8_t>& signature
)
{
    OQS_SIG* sig = OQS_SIG_new(algorithm.c_str());
    if (sig == nullptr)
    {
        return false;
    }

    OQS_STATUS status = OQS_SIG_verify(
        sig,
        message.data(),
        message.size(),
        signature.data(),
        signature.size(),
        public_key.data()
    );

    OQS_SIG_free(sig);

    return status == OQS_SUCCESS;
}

*/ 
