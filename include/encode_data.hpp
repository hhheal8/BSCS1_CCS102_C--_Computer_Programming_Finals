#ifndef ENCODE_DATA_H
#define ENCODE_DATA_H

#include "types_aliases.hpp"

template<typename ArrayType1, typename ArrayType2>
auto encode_data(ArrayType1 *str_table_data, ArrayType2 **table_data, const_szt &rows, const_szt &columns) -> void;

//ANCHOR: Template specialization
//NOTE: Specialization for double

template<>
auto encode_data(std::string *str_table_data, double **table_data, const_szt &rows, const_szt &columns) -> void;

#endif // ENCODE_DATA_H