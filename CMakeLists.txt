cmake_minimum_required(VERSION 3.0.0)

project(
  Cxx20CreateReadUpdateDeleteSearch 
  VERSION 0.1.0
  DESCRIPTION "First Year BSCS CCS102 Computer Programming Finals Project (May 2022)"
  LANGUAGES CXX
)

add_executable(
  CxxFinals2022
  main.cpp

  source/create_destroy_arrays.cpp
  source/create_file_path.cpp
  source/encode_data.cpp
  source/enter_file_name.cpp
  source/information_number.cpp
  source/validate_user_var.cpp
  source/write_to_file.cpp
)

target_compile_features(
  CxxFinals2022 PRIVATE cxx_std_20
)

target_include_directories(
  CxxFinals2022 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include  
)