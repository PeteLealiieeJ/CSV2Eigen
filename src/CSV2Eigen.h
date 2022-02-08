#pragma once 

#include <Eigen/Dense>
#include <string>
#include <iostream>
#include <vector>

// FILE MANAGEMENT
#include <fstream>

//STRING STREAM
#include <sstream>

// I USE THE SAME ERROR HANDLER SET UP ACROSS MULTIPLE REPOS
// SO WE'LL "GUARD" THIS 
#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

    class errorHandler{
        public:
            size_t id;  // ERROR HANDLER ID
            std::string msg;    // ERROR MESSAGE
            errorHandler( size_t, std::string );
    };

#endif 

class C2EContainer{
    public:
        std::vector<double> doubles;    // VECTOR OF DOUBLES
        std::vector<Eigen::VectorXd> vectors;   // VECTOR OF EIGEN::VECTORS
        std::vector<Eigen::MatrixXd> matrices;  // VECTOR OF EIGEN::MATRICES
        C2EContainer( std::vector<double>,
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
        static void C2EExtract(
            std::string, // FILEPATH
            std::vector<C2EContainer>&,     //EXPORT CONTAINER
            C2ESpec,    // SPECIFICATIONI CONTAINER
            size_t = 0  // NUMBER OF HEADLINES
            );

};