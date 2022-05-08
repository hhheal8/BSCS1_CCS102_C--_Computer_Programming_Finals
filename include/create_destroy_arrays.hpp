#ifndef CREATE_DESTROY_ARRAYS_H
#define CREATE_DESTROY_ARRAYS_H

#include "types_aliases.hpp"

//REVIEW: `constexpr` - so array will be known at compile time

template<typename ArrayType>
constexpr ArrayType *create_1d_array(const_szt &size);

template<typename ArrayType>
constexpr ArrayType **create_2d_array(const_szt &rows, const_szt &columns);

template<typename ArrayType> 
auto destroy_1d_array(ArrayType *table_data, const_szt &size) -> void;

template<typename ArrayType>
auto destroy_2d_array(ArrayType **table_data, const_szt &size) -> void;

//ANCHOR: Template specialization
//NOTE: Specialization for std::string

template<>
std::string *create_1d_array<std::string>(const_szt &size);

template<>
std::string **create_2d_array<std::string>(const_szt &rows, const_szt &columns);

template<>
auto destroy_1d_array(std::string *table_data, const_szt &size) -> void;

template<>
auto destroy_2d_array(std::string **table_data, const_szt &size) -> void;

//ANCHOR: Template specialization
//NOTE: Specialization for double

template<>
double *create_1d_array<double>(const_szt &size);

template<>
double **create_2d_array<double>(const_szt &rows, const_szt &columns);

template<>
auto destroy_1d_array(double *table_data, const_szt &size) -> void;

template<>
auto destroy_2d_array(double **table_data, const_szt &size) -> void;

#endif // CREATE_DESTROY_ARRAYS_H