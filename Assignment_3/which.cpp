#include "which.h"

void which(bool& statSort1,bool& statSort2)
{
    if(!statSort1 && !statSort2)
    {
        std::cout << "Båda filerna är INTE sorterade" << std::endl;
    }
    
    if (!statSort1 && statSort2)
    {
        std::cout << "inFile1 är INTE sorterad" << std::endl;
    }

    if (statSort1 && !statSort2)
    {
        std::cout << "inFile2 är INTE sorterad" << std::endl;
    }

}