# CSV2Eigen
This repository is used to parse/extract data from a CSV file to a container (vector storage indexed by line/row of CSV) which stores vector storages of the standard doubles, Eigen vectors, and Eigen matrice. (see diagram below)

<!-- insert image of container setup -->

Knowledge of the following are required to utilize CSV2Eigen::C2EExtract

- Class C2ESpec 
    - Holds the Specifications that C2EExtract uses to extract to the user-input types and endpoint
    - Contains a member variable which is a vector of 'char's which holds the type of variable which a section is extracted to according to the following:
        - 'd' = section is appended to the vector of doubles
        - 'v' = section is appended to the vector of Eigen::VectorXd s
        - 'm' = section is appended to the vector of Eigen::MatrixXd s
    - Contains a member variable which is a vector of 'size_t's (for those unfamillar, essentially an unsigned integer but ... not) which holds the END POINTS of sections which are being extracted to the user-input type
    - Contains one parametric constructor which defines ALL members variables of the class

- Class C2EContainer 
    - Holds the vector storages for the doubles, vectors, and matrices, and is the type of the vector elements of the container respective to csv rows/lines
    - Contains member variables which are the vector storage for standard type double (doubles) and the dynamic Eigen types VectorXd and MatrixXd (vectors,matrices) which are all public access
    - Contains one parametric constructor which defines ALL members variables of the class

- CSV2Eigen::C2EExtract(REQUIRED1,REQUIRED2,REQUIRED3,)
    - Funciton which takes in 3 REQUIRED inputs and 1 OPTIONAL input
        - REQUIRED1: String of the file name/path which describes the location of the CSV
        - REQUIRED2: An empty initilized vector containing the C2EContainer class, std::vector\<C2EContainer\>. Note that after the extraction function is called this will be the variable which has all the data
        - REQUIRED3: A user completed C2ESpec class which holds specification as described above
        - OPTIONAL1: The number of lines to be ignored (usually for users which have headlines or lines that describe variables). Default value is zero.


<!-- insert image of CSV description -->

Further utilization instruction of CSV2Eigen can be seen in [examples](examples/).

