#include "pch.hpp"

#include "main.hpp"

struct DataSet
{
    double
        value_1 =
            default_value;

    double
        value_2 =
            default_value;

    double
        value_3 =
            default_value;

    static double
        default_value;

    static void setup();

    static DataSet
        cache;
};

double
    DataSet::default_value = 1.0;

DataSet
    DataSet::cache;

void
DataSet::setup()
{

}

int main(int argc, char** argv)
{		
    /*
    DataSet a =
        {
            .value_2 = 1.1,
            .value_3 = 1.1
        };

    */
    QLogicaeCppCore::SingletonManager::singleton.setup();
    QLogicaeCppCore::SingletonManager::singleton.setup();
    QLogicaeCppCore::SingletonManager::singleton.setup();
    QLogicaeCppCore::SingletonManager::singleton.setup();
    QLogicaeCppCore::SingletonManager::singleton.setup();
    
    int a;
	
    
    bool exit_code;
	std::cin >> exit_code;

    return 0;
}

namespace QLogicaeCppCoreSandbox
{

}
