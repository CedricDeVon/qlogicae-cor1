#include "pch.hpp"

#include "main.hpp"

#include "qlogicae/cor1/includes/singleton_manager.hpp"
// #include "qlogicae/cor1/includes/onnx_api_manager.hpp"

using namespace QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME;

int main(int argc, char** argv)
{	
	// OnnxApiManager m = OnnxApiManager();

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

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_SANDBOX_NAMESPACE_NAME
{

}
