#include "encode_data.hpp"

#include "validate_user_var.hpp"

template<>
auto encode_data(std::string *str_table_data, double **table_data, const_szt &rows, const_szt &columns) -> void {

  //REVIEW: Local Variable Declarations

  size_t number_code = 0;
  double grade_subj  = 0;

  //ANCHOR: Algorithm and Statements to execute

  std::cout << "\nEncode Student Grades\n";
  for(size_t i = 0; i < rows; ++i) {

    for(size_t j = 0; j < columns + 1; ++j) {

      std::cout << "\nStudent No. " << i + 1 << ". Enter Student Number Code   : ";
      validate_number_code(number_code);

      table_data[i][j] = number_code;

      std::cout << "\nEncode " << std::fixed << std::setprecision(0) << number_code << "\'s Grades:\n";
      break;

    }

    for(size_t k = 1; k < columns + 1; ++k) {

      std::cout << "\nEncode " << str_table_data[k - 1] << " Subject Grade\nEnter Grade on Subject No. " << k << ".   : ";
      validate_grade_subj(grade_subj, k);

      table_data[i][k] = grade_subj;

    }

  }

}
