#ifndef ENCODE_DATA_H
#define ENCODE_DATA_H

#include "types_aliases.hpp"

template<typename ArrayType>
auto encode_data(ArrayType **table_data, const_szt &rows, const_szt &columns) -> void;

//ANCHOR: Template specialization
//NOTE: Specialization for double

template<>
auto encode_data(double **table_data, const_szt &rows, const_szt &columns) -> void;

#endif // ENCODE_DATA_H