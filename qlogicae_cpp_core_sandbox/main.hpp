#pragma once

#include "qlogicae_cpp_core_sandbox/includes/application.hpp"

#include "qlogicae_cpp_core/includes/singleton_manager.hpp"
#include "qlogicae_cpp_core/includes/error_manager_configurations.hpp"
#include "qlogicae_cpp_core/includes/file_system_manager_utilities.hpp"
#include "qlogicae_cpp_core/includes/singleton_manager_configurations.hpp"

int main(int, char**);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE,
    LPSTR,
    int
)
{
    return main(__argc, __argv);
}

namespace QLogicaeCppCoreSandbox
{

}
