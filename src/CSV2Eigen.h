#include <Eigen/Dense>
#include <string>
#include <iostream>
#include <vector>

// FILE MANAGEMENT
#include <fstream>

//STRING STREAM
#include <sstream>

class C2EerrorHandler{
    public:
        size_t id;  // ERROR HANDLER ID
        std::string msg;    // ERROR MESSAGE
        C2EerrorHandler( size_t, std::string );
};

class C2EExport{
    public:
        std::vector<double> doubles;    // VECTOR OF DOUBLES
        std::vector<Eigen::VectorXd> vectors;   // VECTOR OF EIGEN::VECTORS
        std::vector<Eigen::MatrixXd> matrices;  // VECTOR OF EIGEN::MATRICES
        C2EExport( std::vector<double>,
            std::vector<Eigen::VectorXd>,
            std::vector<Eigen::MatrixXd> );
};

class C2ESpec{
    public:
        std::vector<size_t> endIndices; // SECTION END-POINTS
        std::vector<char> types;    // SECTION TYPES (DOUBLE,VECTOR,MATRIX)
        C2ESpec(std::vector<size_t>,
                std::vector<char>);
};

class CSV2Eigen{
    public: 
        static void parseC2E(
            std::string, // FILEPATH
            std::vector<C2EExport>&,    //EXPORT CONTAINER
            C2ESpec,    // SPECIFICATIONI CONTAINER
            size_t = 0  // NUMBER OF HEADLINES
            );

};