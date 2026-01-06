#include "pch.hpp"

#include "main.hpp"


namespace Experiment10 // pure, class
{   
    static std::string pure_static_input_value = "";

    static std::string pure_static_output_value = "";

    struct StructSample
    {
        inline static std::string struct_static_input_value = "";

        inline static std::string struct_static_output_value = "";
    };

    class ClassSample
    {
    public:
        inline static std::string class_static_input_value = "";

        inline static std::string class_static_output_value = "";
    };

    void pure_static()
    {
        pure_static_output_value =
            pure_static_input_value +
            pure_static_input_value;
    }

    void struct_static()
    {
        StructSample::struct_static_output_value =
            StructSample::struct_static_input_value +
            StructSample::struct_static_input_value;
    }

    void class_static()
    {
        ClassSample::class_static_output_value =
            ClassSample::class_static_input_value +
            ClassSample::class_static_input_value;
    }

    void execute()
    {
        QLogicaeCppCore::RuntimeBenchmarkerTestSuite test_suite_1
        {
            .name = "pure_static_vs_struct_static_vs_class_static",
            .warmup_count = 2,
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 1'000'000,
                    .iterations = 1
                },
                {
                    .epochs = 100'000,
                    .iterations = 10
                },
                {
                    .epochs = 10'000,
                    .iterations = 100
                },
                {
                    .epochs = 1'000,
                    .iterations = 1'000
                },                
                {
                    .epochs = 1,
                    .iterations = 1'000'000
                }
            },

            .test_cases =
            {                
                {
                    .name = "pure_static",
                    .callback = pure_static
                },
                {
                    .name = "struct_static",
                    .callback = struct_static
                },
                {
                    .name = "class_static",
                    .callback = class_static
                }
            }
        };

        QLogicaeCppCore::RuntimeBenchmarker::singleton
            .execute(
                test_suite_1
            );

        /*
        NanobenchBencchmarkingTestSuite test_suite_2
        {
            .name = "pure_static_vs_struct_static_vs_class_static",
            .warmup_count = 2,
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 1'000'000,
                    .iterations = 1
                },
                {
                    .epochs = 100'000,
                    .iterations = 10
                },
                {
                    .epochs = 10'000,
                    .iterations = 100
                },
                {
                    .epochs = 1'000,
                    .iterations = 1'000
                },
                {
                    .epochs = 1,
                    .iterations = 1'000'000
                }
            },

            .test_cases =
            {
                {
                    .name = "pure_static",
                    .callback = pure_static
                },
                {
                    .name = "struct_static",
                    .callback = struct_static
                },
                {
                    .name = "class_static",
                    .callback = class_static
                }
            }
        };

        execute_nanobenchmark(
            test_suite_2
        );
        */

        bool exit_code;
        std::cin >> exit_code;
    }
}



int main(int argc, char** argv)
{          
    
    Experiment10::execute();

    return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}
