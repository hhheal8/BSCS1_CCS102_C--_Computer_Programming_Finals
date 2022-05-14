#include "encode_data.hpp"

#include "create_destroy_arrays.hpp"
#include "validate_user_var.hpp"

template<>
auto encode_data(std::string *n_code_table_data, std::string *subj_table_data, double **table_data, 
                  const_szt &rows, const_szt &columns) -> void {

  //REVIEW: Local Variable Declarations

  std::string number_code = "";
  double grade_subj       = 0;

  //ANCHOR: Algorithm and Statements to execute

  system("cls");
  std::cout << "\nEncode Student Grades.\n";

  for(size_t i = 0; i < rows; ++i) {

    for(size_t j = 0; j < columns + 1; ++j) {

      std::cout << "\nStudent No. " << i + 1 << ". Enter Student Number Code: ";
      validate_number_code(number_code);

      n_code_table_data[i] = number_code;

      std::cout << "\nEncode " << number_code << "\'s Grades:\n";
      break;

    }

    for(size_t k = 1; k < columns + 1; ++k) {

      std::cout << "\nEncode " << subj_table_data[k - 1] << " Subject Grade\nEnter Grade on Subject No. " << k << ".   : ";
      validate_grade_subj(grade_subj, k);

      table_data[i][k] = grade_subj;

    }

  }

}
