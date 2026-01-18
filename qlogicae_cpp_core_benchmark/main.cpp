#include "pch.hpp"

// #include "main.hpp"

template <typename Derived>
struct AbstractConfigurations
{
	bool is_enabled =
			Derived::default_configurations.is_enabled;
};

struct ImplementationConfigurations :
	AbstractConfigurations<ImplementationConfigurations>
{
	bool is_thread_safe_enabled =
			default_configurations.is_thread_safe_enabled;

	static ImplementationConfigurations
		initial_configurations;

	static ImplementationConfigurations
		default_configurations;
};

ImplementationConfigurations
	ImplementationConfigurations::initial_configurations = []()
	{
		ImplementationConfigurations c;
		c.AbstractConfigurations::is_enabled = true;
		c.is_thread_safe_enabled = true;

		return c;
	}();

ImplementationConfigurations
	ImplementationConfigurations::default_configurations =
		ImplementationConfigurations::initial_configurations;



int main(int argc, char** argv)
{
	ImplementationConfigurations ic;

	std::cout << ic.is_enabled << "\n";
	std::cout << ic.is_thread_safe_enabled << "\n";

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
