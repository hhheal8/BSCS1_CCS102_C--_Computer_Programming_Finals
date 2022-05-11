#include "information_number.hpp"

#include "validate_user_var.hpp"

auto as_rows() -> const_szt {

  //REVIEW: Local Variable Declarations

  size_t n_students_to_encode = 0;

  const_str warning_msg = "\nInvalid Format/Not a valid Number of Student(s)\nRe-enter how many Number of Student(s) to Encode: ";

  //ANCHOR: Algorithm and Statements to execute

  std::cout << "\nEnter how many Number of Student(s) to Encode   : ";
  validate_user_var(n_students_to_encode, warning_msg);

  return n_students_to_encode;

}

auto as_columns() -> const_szt {

  //REVIEW: Local Variable Declarations

  size_t n_subjgrades_to_encode = 0;

  const_str warning_msg = "\nInvalid Format/Not a valid Number of Grade(s)\nRe-enter how many Number of Grade(s) to Encode  : ";

  //ANCHOR: Algorithm and Statements to execute

  std::cout << "\nEnter how many Number of Grade(s) to Encode     : ";
  validate_user_var(n_subjgrades_to_encode, warning_msg);

  return n_subjgrades_to_encode;

}

auto enter_subject_name(std::string *table_data, const_szt &columns) -> void {

  std::string subj_name = "";

  std::cout << "\n";
  std::cin.ignore();
  for(size_t i = 0; i < columns; ++i) {
    std::cout << "Enter Name of Subject No. " << i + 1 << ".   : ";
    getline(std::cin, subj_name);

    table_data[i] = subj_name;
  }

}


//ANCHOR: Learning reference for resetting state of `std::cin`
//LINK: https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
//LINK: https://en.cppreference.com/w/cpp/types/numeric_limits