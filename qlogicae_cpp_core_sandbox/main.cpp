#include "pch.hpp"

#include "main.hpp"

// #include "qlogicae_cpp_core/includes/gmail_api_manager.hpp"

using namespace QLogicae::Cor::V1;

int main(int argc, char** argv)
{	
	std::string input = "a";
	std::string password = "password_1234";

	do
	{
		std::cout << "Enter Password: ";
		std::cin >> input;
	}
	while (input != password);

	bool exit_code;
	std::cin >> exit_code;

	return 0;
}


