#include "encode_data.hpp"

#include "create_destroy_arrays.hpp"
#include "validate_user_var.hpp"

template<>
auto encode_data(std::string *str_table_data, double **table_data, const_szt &rows, const_szt &columns) -> void {

  //REVIEW: Local Variable Declarations

  size_t number_code = 0;
  double grade_subj  = 0;

  double **temp_data = create_2d_array<double>(rows, columns);

  const_str warning_msg = "\nInvalid Format/Student Number Code is already existing\nRe-enter Student Number Code(Unique No.): ";

  //ANCHOR: Algorithm and Statements to execute

  std::cout << "\nEncode Student Grades\n";
  for(size_t i = 0; i < rows; ++i) {

    for(size_t j = 0; j < columns + 1; ++j) {

      std::cout << "\nStudent No. " << i + 1 << ". Enter Student Number Code: ";
      validate_number_code(number_code);

      //TODO: If number code is already existing in the array, prompt user to enter number again
      for(size_t ii = 0; ii < rows; ++ii) {
        if(temp_data[ii][j] == number_code) {
          std::cout << warning_msg;
          validate_number_code(number_code);
          continue;
        }

        if(temp_data[ii][j] != number_code) {
          break;
        }
      }

      table_data[i][j] = number_code;
      temp_data[i][j] = number_code;

      std::cout << "\nEncode " << std::fixed << std::setprecision(0) << number_code << "\'s Grades:\n";
      break;

    }

    for(size_t k = 1; k < columns + 1; ++k) {

      std::cout << "\nEncode " << str_table_data[k - 1] << " Subject Grade\nEnter Grade on Subject No. " << k << ".   : ";
      validate_grade_subj(grade_subj, k);

      table_data[i][k] = grade_subj;
      temp_data[i][k] = grade_subj;

    }

  }

  destroy_2d_array<double>(temp_data, rows);

}
