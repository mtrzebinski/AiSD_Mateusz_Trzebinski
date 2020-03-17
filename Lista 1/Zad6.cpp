#include <iostream>
#include <fstream>
#include <vector>


int main()
{


    std::vector<int> liczbyA;
    std::vector<int> liczbyB;
    std::vector<int> liczbyC;

    std::ifstream plikA("a.txt");
    int znak;
    while(plikA >> znak){
            liczbyA.push_back(znak);
            }
    plikA.close();

    std::ifstream plikB("b.txt");
    while(plikB >> znak){
            liczbyB.push_back(znak);
            }
    plikB.close();

    for(int i=0; i < (liczbyA.size() + liczbyB.size() - 1) ; i++)
    {
        liczbyC.push_back(0);
    }

    for(int i=0; i < liczbyA.size(); i++)
        for(int j=0; j < liczbyB.size(); j++)
    {
        liczbyC.at(i+j) = liczbyC.at(i+j) + liczbyA.at(i)*liczbyB.at(j) ;
    }

    std::fstream plikC;
    plikC.open(( "c.txt"), std::ios::out);
    for( int i = 0; i < liczbyC.size(); i++ )
    {
        plikC << liczbyC.at(i) << " ";
    }
    plikC.close();


    return 0;
}
