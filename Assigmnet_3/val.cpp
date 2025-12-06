#include "val.h"

bool val(std::ifstream& file)
{
    int num = 0;
    if(!file.is_open())
    {
        std::cout << "Filen gick ej att öppna." << std::endl;
        return false;
    }

    if(!file>>num)
    {
        std::cout << "Filen är tom." << std::endl;
        return false;
    }

    file.clear();
    file.seekg(0);
    return true;

}