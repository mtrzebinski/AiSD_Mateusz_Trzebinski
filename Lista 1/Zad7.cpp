#include <iostream>
#include <fstream>



int main(int argc, char** argv)
{
    char znak;
    int Tablica[128] = {};

    std::ifstream plik(argv[1], std::ios::in );

    while(plik >> znak)
    {
            Tablica[znak]++;
    }
    plik.close();

    for(int i=0; i < 128 ; i++)
    {
        std::cout <<  Tablica[i] << "  " ;
        if(i%10 == 0)
        {
            std::cout << std::endl ;
        }
    }

    return 0;
}
