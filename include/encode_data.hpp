#ifndef ENCODE_DATA_H
#define ENCODE_DATA_H

#include "types_aliases.hpp"

template<typename ArrayType, typename ArrayType1, typename ArrayType2>
auto encode_data(ArrayType *n_code_table_data, ArrayType1 *subj_table_data, ArrayType2 **table_data, 
                  const_szt &rows, const_szt &columns) -> void;

//ANCHOR: Template specialization
//NOTE: Specialization for double

template<>
auto encode_data(std::string *n_code_table_data, std::string *subj_table_data, double **table_data, 
                  const_szt &rows, const_szt &columns) -> void;

#endif // ENCODE_DATA_H