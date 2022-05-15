#include "validate_user_var.hpp"

template<typename Var>
auto validate_user_var(Var &var, const_str &msg) -> void {

  //REVIEW: Algorithm and Statements to execute

  std::cin >> var;

  if(!std::cin) {
    std::cout << msg;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<::std::streamsize>::max(), '\n');

    validate_user_var(var, msg);
  }

}

//ANCHOR: Template specialization
//NOTE: Template specialization for std::string

template<>
auto validate_user_var(std::string &var, const_str &msg) -> void {

  //REVIEW: Algorithm and Statements to execute

  std::cin >> var;

  if(!std::cin) {
    std::cout << msg;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<::std::streamsize>::max(), '\n');

    validate_user_var(var, msg);
  }

}

//ANCHOR: Template specialization
//NOTE: Template specialization for size_t

template<>
auto validate_user_var(size_t &var, const_str &msg) -> void {

  //REVIEW: Algorithm and Statements to execute

  std::cin >> var;

  if(!std::cin) {
    std::cout << msg;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<::std::streamsize>::max(), '\n');

    validate_user_var(var, msg);
  }

}

template<>
auto validate_number_code(std::string &number_code, std::string *n_code_table_data, const_szt &rows, const_szt &validate_at_n) -> void {

  //ANCHOR: Algorithm and Statements to execute

  //TODO: This is a bug LOL

  std::getline(std::cin, number_code);

  for(size_t i = 0; i < rows; ++i) {
    if(n_code_table_data[i] == number_code) {
      system("cls");
      std::cout << "\nEncode Student Grades.\n";
      std::cout << "\nStudent No. " << validate_at_n + 1 << '.';
      std::cout << "\nPlease do not enter an existing Number Code(Must be a Unique No.): ";
      validate_number_code(number_code, n_code_table_data, rows, validate_at_n);
      return;
    }
  }

}

template<>
auto validate_grade_subj(double &grade_subj, const_szt &validate_at_n) -> void {

  //REVIEW: Local Variable Declarations
  
  const_str warning_msg1 = "\nInvalid Format/Not an integer\nRe-enter Grade for Subject No. ";
  const_str warning_msg2 = "\nInvalid Format/Grade(s) per Subject should be between 1 to 100 only\nRe-enter Grade for Subject No. ";

  //ANCHOR: Algorithm and Statements to execute

  std::cin >> grade_subj;

  if(!std::cin) {
    std::cout << warning_msg1 << validate_at_n << ": ";
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    validate_grade_subj(grade_subj, validate_at_n);
  }

  if(grade_subj <= 0 || grade_subj >= 101) {
    std::cout << warning_msg2 << validate_at_n << ": ";
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    validate_grade_subj(grade_subj, validate_at_n);
  }

}