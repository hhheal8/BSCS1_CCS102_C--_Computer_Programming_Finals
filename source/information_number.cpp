#include "information_number.hpp"

#include "validate_user_var.hpp"

auto as_rows() -> const_szt {

  size_t n_students_to_encode = 0;

  const_str warning_msg = "\nInvalid Format/Not a valid Number of Student(s)\nRe-enter how many Number of Student(s) to Encode: ";

  std::cout << "\nEnter how many Number of Student(s) to Encode   : ";
  validate_user_var(n_students_to_encode, warning_msg);

  return n_students_to_encode;

}

auto as_columns() -> const_szt {

  size_t n_subjgrades_to_encode = 0;

  const_str warning_msg = "\nInvalid Format/Not a valid Number of Grade(s)\nRe-enter how many Number of Grade(s) to Encode  : ";

  std::cout << "\nEnter how many Number of Grade(s) to Encode     : ";
  validate_user_var(n_subjgrades_to_encode, warning_msg);

  return n_subjgrades_to_encode;

}
