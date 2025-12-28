#pragma once

namespace QLogicaeCppCore
{
    struct ExceptionManagerConfigurations
    {
        bool is_enabled = true;
        
        bool is_console_output_enabled = false;

        bool is_file_output_enabled = false;

        bool is_exception_throwing_enabled = false;        
    };
}
