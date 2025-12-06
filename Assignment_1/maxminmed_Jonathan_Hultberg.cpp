//Jonathan Hultberg
//Datum: 241118
//Kurs: DT178G
//Laboration 1

#include <iostream> 


int main(){
    int tal; 
    int antal = 0;
    int summa = 0; 
    int maximum; 
    int minimum;

    std::cout << "Mata in heltal (avsluta med Ctrl+D):" << std::endl;

    //while loop som läser in värden från tangenbord tills användera trycker Ctrl+D
    while (std::cin>>tal) 
    {
        if(antal==0){
            maximum = minimum = tal;
        }

        if(tal>maximum){
            maximum=tal;
        }  

        if(tal<minimum){
            minimum = tal;
        }
        
        summa += tal; 
        ++antal; 
    }

    // säkerhetskontroll för att kolla så minst ett tal har matats in (kollar att antal inte är 0)
    if(antal==0) 
    {
        std::cout << "Inga tal har matats in!" << std::endl; 
        return -1; 
    }
    

    std::cout << "Medelvärdet: " << static_cast<double>(summa)/antal << std::endl; 
    std::cout << "Max: " << maximum << " Min: " << minimum << std::endl; 
    return 0;
}