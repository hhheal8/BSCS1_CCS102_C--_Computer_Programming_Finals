#include "create_destroy_arrays.hpp"

//REVIEW: Allocate 1D Array 
template<typename ArrayType>
ArrayType *create_1d_array(const_szt &size) {

  ArrayType *table_data = nullptr;
  table_data = new ArrayType[size];

  return table_data;

}

//REVIEW: Allocate 2D Array
template<typename ArrayType>
ArrayType **create_2d_array(const_szt &rows, const_szt &columns) {

  ArrayType **table_data = nullptr;
  table_data = new ArrayType*[rows];

  for(size_t i = 0; i < rows; ++i) {
    table_data[i] = new ArrayType[columns];
  }

  return table_data;

}

//REVIEW: Deallocate 1D Array
template<typename ArrayType> 
auto destroy_1d_array(ArrayType *table_data, const_szt &size) -> void {
  
  delete[] table_data;
  table_data = nullptr;

}

//REVIEW: Deallocate 2D Array
template<typename ArrayType>
auto destroy_2d_array(ArrayType **table_data, const_szt &size) -> void {

  for(size_t i = 0; i < size; ++i) {
    delete[] table_data[i];
  }
  
  delete[] table_data;
  table_data = nullptr;

}

//ANCHOR: Template specialization
//NOTE: Specialization for std::string

template<>
std::string *create_1d_array<std::string>(const_szt &size) {

  std::string *table_data = nullptr;
  table_data = new std::string[size];

  return table_data;

}

template<>
std::string **create_2d_array<std::string>(const_szt &rows, const_szt &columns) {

  std::string **table_data = nullptr;
  table_data = new std::string*[rows];

  for(size_t i = 0; i < rows; ++i) {
    table_data[i] = new std::string[columns];
  }

  return table_data;

}

template<>
auto destroy_1d_array(std::string *table_data, const_szt &size) -> void {

  delete[] table_data;
  table_data = nullptr;

}

template<>
auto destroy_2d_array(std::string **table_data, const_szt &size) -> void {

  for(size_t i = 0; i < size; ++i) {
    delete[] table_data[i];
  }
  
  delete[] table_data;
  table_data = nullptr;

}

//ANCHOR: Template specialization
//NOTE: Specialization for double

template<>
double *create_1d_array<double>(const_szt &size) {

  double *table_data = nullptr;
  table_data = new double[size];

  return table_data;

}

template<>
double **create_2d_array<double>(const_szt &rows, const_szt &columns) {

  double **table_data = nullptr;
  table_data = new double*[rows];

  for(size_t i = 0; i < rows; ++i) {
    table_data[i] = new double[columns];
  }

  return table_data;

}

template<>
auto destroy_1d_array(double *table_data, const_szt &size) -> void {

  delete[] table_data;
  table_data = nullptr;

}

template<>
auto destroy_2d_array(double **table_data, const_szt &size) -> void {

  for(size_t i = 0; i < size; ++i) {
    delete[] table_data[i];
  }
  
  delete[] table_data;
  table_data = nullptr;

}

//ANCHOR: Learning reference for template specialization
//LINK: https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67490s

//ANCHOR: Learning reference for `constexpr`
//LINK: https://xuhuisun.com/post/c++-weekly-2-constexpr-map/#:~:text=The%20constexpr%20specifier%20declares%20that%20it%20is%20possible,like%20to%20be%20evaluated%20at%20the%20compile-time%20specifically.?msclkid=261d68dccf6011eca2e6d26a526a1076