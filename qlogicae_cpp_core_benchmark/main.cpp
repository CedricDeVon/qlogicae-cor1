#include "pch.hpp"

// #include "main.hpp"

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


int main(int argc, char** argv)
{
	ConfigurationsManager::singleton.setup<AbstractConfigurations>(
		AbstractConfigurations
		{
			.is_enabled = false
		}
	);

	std::cout << AbstractConfigurations::default_configurations.is_enabled << "\n";

	return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}

/*



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
