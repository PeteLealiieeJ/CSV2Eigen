find_package( Eigen3 3.3 REQUIRED NO_MODULE)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY 
    ${CMAKE_SOURCE_DIR}/examples/bin
    )

###################################################
# USE THIS TO ALLOW THE OBJECT TO "SEE" THE CSV

file(GLOB EXAMPLE_CSVS ${CMAKE_CURRENT_SOURCE_DIR}/*.csv)
file( COPY ${EXAMPLE_CSVS} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )

###################################################

add_executable(example1 example1.cxx)

target_link_libraries(
  example1
  CSV2Eigen
  Eigen3::Eigen
)

target_include_directories(example1 PUBLIC 
  ${CMAKE_SOURCE_DIR}/src 
)