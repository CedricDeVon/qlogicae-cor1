#pragma once

#include "qlogicae_cpp_core_sandbox/includes/application.hpp"

#include "qlogicae_cpp_core/includes/error_manager.hpp"
#include "qlogicae_cpp_core/includes/asynchronous_manager.hpp"

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
