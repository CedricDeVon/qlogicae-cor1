#include "pch.hpp"

#include "main.hpp"

namespace Experiment10 // pure
{
    static std::string benchmark_value = "0";

    namespace Cache
    {
        static std::string pure_static_string_input_value = benchmark_value;

        static std::string pure_static_string_output_value = "";

        struct StructStringSample
        {
            inline static std::string struct_static_string_input_value = benchmark_value;

            inline static std::string struct_static_string_output_value = "";
        };

        class ClassStringSample
        {
        public:
            inline static std::string class_static_string_input_value = benchmark_value;

            inline static std::string class_static_string_output_value = "";
        };
    };

    extern std::string extern_static_string_input_value;

    extern std::string extern_static_string_output_value;

    static std::string pure_static_string_input_value = benchmark_value;

    static std::string pure_static_string_output_value = "";

    struct StructStringSample
    {
        inline static std::string struct_static_string_input_value = benchmark_value;

        inline static std::string struct_static_string_output_value = "";
    };

    class ClassStringSample
    {
    public:
        inline static std::string class_static_string_input_value = benchmark_value;

        inline static std::string class_static_string_output_value = "";
    };

    void extern_static_string()
    {
        extern_static_string_output_value =
            extern_static_string_input_value +
            extern_static_string_input_value;
    }

    void pure_namespace_static_string()
    {
        Cache::pure_static_string_output_value =
            Cache::pure_static_string_input_value +
            Cache::pure_static_string_input_value;
    }

    void pure_static_string()
    {
        pure_static_string_output_value =
            pure_static_string_input_value +
            pure_static_string_input_value;
    }

    void struct_static_string()
    {
        StructStringSample::struct_static_string_output_value =
            StructStringSample::struct_static_string_input_value +
            StructStringSample::struct_static_string_input_value;
    }

    void class_static_string()
    {
        ClassStringSample::class_static_string_output_value =
            ClassStringSample::class_static_string_input_value +
            ClassStringSample::class_static_string_input_value;
    }

    static std::string pure_static_double_input_value = benchmark_value;

    static std::string pure_static_double_output_value = "";

    struct StructDoubleSample
    {
        inline static std::string struct_static_double_input_value = benchmark_value;

        inline static std::string struct_static_double_output_value = "";
    };

    class ClassDoubleSample
    {
    public:
        inline static std::string class_static_double_input_value = benchmark_value;

        inline static std::string class_static_double_output_value = "";
    };

    void pure_static_double()
    {
        pure_static_double_output_value =
            pure_static_double_input_value +
            pure_static_double_input_value;
    }

    void struct_static_double()
    {
        StructDoubleSample::struct_static_double_output_value =
            StructDoubleSample::struct_static_double_input_value +
            StructDoubleSample::struct_static_double_input_value;
    }

    void class_static_double()
    {
        ClassDoubleSample::class_static_double_output_value =
            ClassDoubleSample::class_static_double_input_value +
            ClassDoubleSample::class_static_double_input_value;
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
                    .epochs = 10'000'000,
                    .iterations = 1
                },
                {
                    .epochs = 1'000'000,
                    .iterations = 10
                },
                {
                    .epochs = 100'000,
                    .iterations = 100
                },
                {
                    .epochs = 10'000,
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
                    .name = "extern_static_string",
                    .callback = extern_static_string
                },
                {
                    .name = "struct_static_string",
                    .callback = struct_static_string
                },
                {
                    .name = "class_static_string",
                    .callback = class_static_string
                },
                {
                    .name = "pure_namespace_static_string",
                    .callback = pure_namespace_static_string
                },
                {
                    .name = "pure_static_string",
                    .callback = pure_static_string
                }
            }
        };

        QLogicaeCppCore::RuntimeBenchmarker__singleton
            .execute(
                test_suite_1
            );

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
