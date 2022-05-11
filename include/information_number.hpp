#ifndef INFORMATION_NUMBER
#define INFORMATION_NUMBER

#include "types_aliases.hpp"

auto as_rows() -> const_szt;
auto as_columns() -> const_szt;

auto enter_subject_name(std::string *table_data, const_szt &columns) -> void;

#endif // INFORMATION_NUMBER