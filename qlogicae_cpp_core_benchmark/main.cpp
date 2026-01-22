#include "pch.hpp"

// #include "main.hpp"

#include "qlogicae_cpp_core/includes/singleton_manager.hpp"
#include "qlogicae_cpp_core/includes/runtime_benchmarker.hpp"

int main(int argc, char** argv)
{
	return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}

/*
ConfigurationsManager::singleton.setup<AbstractConfigurations>(
	AbstractConfigurations
	{
		.is_enabled = false
	}
);

std::cout << AbstractConfigurations::default_configurations.is_enabled << "\n";
*/

/*

AbstractConfigurations a;

	ImplementationConfigurations i;

	std::cout << a.is_enabled << " " << i.is_enabled << "\n";


class ConfigurationsManager
{
public:
	static ConfigurationsManager
		singleton;

	template <typename Type> void
		setup(
			const Type& configurations = {}
		);
};

ConfigurationsManager
	ConfigurationsManager::singleton;


template <typename Type>
void ConfigurationsManager::setup(
	const Type& configurations
)
{
	Type::default_configurations = configurations;
}



struct AbstractConfigurations
{
	bool is_enabled =
		default_configurations.is_enabled;

	static AbstractConfigurations
		default_configurations;
};

AbstractConfigurations
	AbstractConfigurations::default_configurations =
	{
		.is_enabled = true
	};


struct ImplementationConfigurations :
	AbstractConfigurations
{
	bool is_enabled =
		default_configurations.is_enabled;

	static ImplementationConfigurations
		default_configurations;
};

ImplementationConfigurations
	ImplementationConfigurations::default_configurations =
	{
		.is_enabled = false
	};

struct AbstractConfigurations
{
	bool is_enabled =
		default_configurations.is_enabled;

	static AbstractConfigurations
		default_configurations;
};

AbstractConfigurations
	AbstractConfigurations::default_configurations;


	AbstractConfigurations a;

	AbstractConfigurations::setup(a);

*/
