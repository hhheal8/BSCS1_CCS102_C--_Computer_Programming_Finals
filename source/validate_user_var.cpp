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

template<typename Var>
auto validate_number_code(Var &number_code) -> void {

  //REVIEW: Local Variable Declarations

  size_t student_number_code = 0;
  int count_number           = 0;

  const_str error_msg1 = "\nInvalid Format/Not a valid Student Number Code\nRe-enter Student Number Code: ";
  const_str error_msg2 = "\nInvalid Format/Student Number Code must be 10 maximum digits only\nRe-enter Student Number Code: ";

  //ANCHOR: Algorithm and Statements to execute

  std::cin >> number_code;

  student_number_code = number_code;

  while(student_number_code > 0) {
    student_number_code /= 10;
    count_number++;
  }

  if(!std::cin) {
    std::cout << error_msg1;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    validate_number_code(number_code);
  }

  if(count_number != 10) {
    std::cout << error_msg2;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    validate_number_code(number_code);
  }

}

template<>
auto validate_number_code(size_t &number_code) -> void {

  //REVIEW: Local Variable Declarations

  size_t student_number_code = 0;
  int count_number           = 0;

  const_str error_msg1 = "\nInvalid Format/Not a valid Student Number Code\nRe-enter Student Number Code: ";
  const_str error_msg2 = "\nInvalid Format/Student Number Code must be 10 maximum digits only\nRe-enter Student Number Code: ";

  //ANCHOR: Algorithm and Statements to execute

  std::cin >> number_code;

  student_number_code = number_code;

  while(student_number_code > 0) {
    student_number_code /= 10;
    count_number++;
  }

  if(!std::cin) {
    std::cout << error_msg1;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    validate_number_code(number_code);
  }

  if(count_number != 10) {
    std::cout << error_msg2;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    validate_number_code(number_code);
  }

}



template<typename Var>
auto validate_grade_subj(Var &grade_subj, const_szt &validate_at_n) -> void {

  //REVIEW: Local Variable Declarations
  
  const_str warning_msg1 = "\nInvalid Format/Not an integer\nRe-enter Grade for Subject no. ";
  const_str warning_msg2 = "\nInvalid Format/Grade(s) per Subject should be between 1 to 100 only\nRe-enter Grade for Subject no. ";

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

template<>
auto validate_grade_subj(double &grade_subj, const_szt &validate_at_n) -> void {

  //REVIEW: Local Variable Declarations
  
  const_str warning_msg1 = "\nInvalid Format/Not an integer\nRe-enter Grade for Subject no. ";
  const_str warning_msg2 = "\nInvalid Format/Grade(s) per Subject should be between 1 to 100 only\nRe-enter Grade for Subject no. ";

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

