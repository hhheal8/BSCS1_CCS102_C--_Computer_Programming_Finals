#ifndef VALIDATE_USER_VAR_H
#define VALIDATE_USER_VAR_H

#include "types_aliases.hpp"

template<typename Var>
auto validate_user_var(Var &var, const_str &msg) -> void;

//ANCHOR: Template specialization
//NOTE: Template specialization for std::string

template<>
auto validate_user_var(std::string &var, const_str &msg) -> void;

//ANCHOR: Template specialization
//NOTE: Template specialization for size_t

template<>
auto validate_user_var(size_t &var, const_str &msg) -> void;

//ANCHOR: Template specialization
//NOTE: Template specialization for size_t

template<typename Var>
auto validate_number_code(Var &number_code, std::string *n_code_table_data, const_szt &rows, const_szt &validate_at_n) -> void;

template<>
auto validate_number_code(std::string &number_code, std::string *n_code_table_data, const_szt &rows, const_szt &validate_at_n) -> void;

//ANCHOR: Template specialization
//NOTE: Template specialization for double

template<typename Var>
auto validate_grade_subj(Var &grade_subj, const_szt &validate_at_n) -> void;

template<>
auto validate_grade_subj(double &grade_subj, const_szt &validate_at_n) -> void;

#endif // VALIDATE_USER_VAR_H