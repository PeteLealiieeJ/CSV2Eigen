#include "CSV2Eigen.h"

// ERROR HANDLER CONSTRUCTOR 
C2EerrorHandler::C2EerrorHandler(size_t idi, std::string msgi):
id(idi),msg(msgi){};

//////////////////////////////////////////////////////////////////////////////////

// 
C2EExport::C2EExport(std::vector<double> doublesi,
        std::vector<Eigen::VectorXd> vectorsi,
        std::vector<Eigen::MatrixXd> matricesi): 
        doubles(doublesi), vectors(vectorsi), matrices(matricesi){};

//////////////////////////////////////////////////////////////////////////////////

C2ESpec::C2ESpec(std::vector<size_t> endIi,std::vector<char> typi){
    try{
        if( endIi.size() != typi.size()){
            std::string msg{  
                "NUMBER OF TYPES AND NUMBER OF VECTORS DONT MATCH"
            };
            throw(C2EerrorHandler(1,msg));
        };
    }catch( C2EerrorHandler& e  ){
        std::cout << "ERROR CODE: " << e.id
                << " \n - " << e.msg << std::endl;
    }
    this -> endIndices = endIi;
    this -> types = typi;
}

//////////////////////////////////////////////////////////////////////////////////

void CSV2Eigen::parseC2E(   std::string file_path,   // FILE PATH
    std::vector<C2EExport>& eigenContainer,  // CONATINER FOR EXPORT CLASS
    C2ESpec spec,   // USER-INPUT SPECIFICATIONS
    size_t headLines    // NUMBER OF HEADER LINES DEF 0
){

    // DECLARE FILE POINTER
    std::fstream fin;

    // OPEN SPECIFIED FILE WITH FILE POINTER
    // fstream DOES NOT AUTP DECLARE ios::in
    fin.open( file_path, std::ios::in );

    if(!fin.is_open()){
        std::cout << "FILE DID NOT OPEN" << std::endl;
    }

    // STORAGE FOR LINE READ FROM CSV 
    std::string line;

    for( size_t i = 0; i < headLines; i++ ){
        // THROW AWAY THE HEADER LINES
        std::getline(fin,line);
    }

    while( std::getline(fin,line) ){

        // USED TO SEPERATE ELEMENTS 
        std::stringstream sstrm(line);

        // STORAGE FOR STRING WITHIN DELIMITERS
        std::string elem; 

        // EXPORT CONATINER COMPONENTS
        std::vector<double> dvec{};
        std::vector<Eigen::VectorXd> vvec{};
        std::vector<Eigen::MatrixXd> mvec{};

        // LENGTH OF FIRST OUTPUT VECTOR IS THE 
        // FIRST ELEMENT OF THIS VECTOR
        size_t cVlength = spec.endIndices[0];

        // FOR-LOOP ITERATES THROUGH THE INPUT TYPES OF
        // EIGEN MATRICES TO PLACE THE CS-VALUES
        for(size_t ii=0; ii < spec.types.size(); ii++){
            
            switch (spec.types[ii]){
                // INDICATED CONTAIN AS DOUBLE
                case 'd':{
                    // READ ELEMENT TO DELIMITER
                    std::getline(sstrm,elem,',');
                    // PUSH BACK DOUBLE VALUE INTO DOUBLES IN EIGEN CONTAINER
                    dvec.push_back( std::stod(elem) );
                    // CLEAR ELEMENT STRING JIC
                    elem = "";
                    break;
                }

                case 'v':{
                    Eigen::VectorXd velem;
                    velem.resize( cVlength,1 );
                    // SAME AS DOUBLE CASE BUT NOW IN FOR-LOOP
                    for( size_t jj = 0; jj < cVlength; jj++ ){
                        std::getline(sstrm,elem,',');
                        velem(jj) = std::stod(elem);
                        elem = "";
                    }
                    vvec.push_back(velem);
                    break;
                }

                case 'm':{
                    Eigen::MatrixXd melem;
                    melem.resize( sqrt(cVlength),sqrt(cVlength) );
                    // SAME AS VECTOR CASE BUT NOW WITH NESTED FOR-LOOP
                    for( size_t jj = 0; jj < std::sqrt(cVlength); jj++ ){
                        for( size_t kk = 0; kk < std::sqrt(cVlength); kk++ ){
                            std::getline(sstrm,elem,',');
                            melem(jj,kk) = std::stod(elem);
                            elem = "";
                        }
                    }
                    mvec.push_back(melem);
                    break;
                }

                default:
                    // MIGHT WANT TO THROW ERROR HERE
                    break;
            }

            cVlength = spec.endIndices[ii+1] - spec.endIndices[ii];
        }

        // PUSHBACK EXPORT CLASS INTO EXPORT CONTAINER
        eigenContainer.push_back( C2EExport(dvec,vvec,mvec) );

        // EFFECTIVELY "CLEAR" THE LINE VARIABLE 
        line = "";

    }

    // GENTLY CLOSE FILE
    fin.close();

    // END 
    return;

}