#include <iostream>
#include <string>
#include <CSV2Eigen.h>

int main(){
    std::vector<size_t> endpoints{0,3,6,9,12};
    std::vector<char> typ{'d','v','v','v','v'};
    C2ESpec specs(endpoints,typ);

    size_t numHeadLines = 1;
    std::string path{"example.csv"} ;

    std::vector<C2EContainer> container = CSV2Eigen::C2EExtract( path,specs,numHeadLines );

    /////////////////////////////////////////////////////////////////////////////
    
    std::cout << "Container Size: "<< container.size() << std::endl;

    std::cout <<  "First double: " << ( container[0] ).doubles[0] << "\n" << 
                  "Last double: " << ( container.back() ).doubles[0] << std::endl;

    std::cout <<   "First-First vector: \n" << (container[0] ).vectors[0] << "\n" << 
                    "Last-First Vector: \n" << ( container.back() ).vectors[0] << std::endl;

    std::cout <<    "First-Last vector: \n" << (container[0] ).vectors.back() << "\n" << 
                    "Last-Last Vector: \n" << ( container.back() ).vectors.back() << std::endl;


    return 0;
}