cmake_minimum_required(VERSION 3.0.2)
project(CSV2Eigen)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_library(
  CSV2Eigen
  src/CSV2Eigen.cxx
  src/CSV2Eigen.h
)

target_link_libraries(
  CSV2Eigen 
  Eigen3::Eigen
)

# UNCOMMENT TO BUILD EXAMPLES FOLDER
# add_subdirectory(examples)
