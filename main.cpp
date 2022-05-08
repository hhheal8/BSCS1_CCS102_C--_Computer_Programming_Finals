#include "create_destroy_arrays.hpp"
#include "create_file_path.hpp"
#include "encode_data.hpp"
#include "enter_file_name.hpp"
#include "information_number.hpp"
#include "write_to_file.hpp"

auto main() -> int {

  std::fstream file_html; //REVIEW: Instantiate fstream class

  //ANCHOR: 
  //1st step - Ask the user to enter the name of the file(.html)
  //2nd step - Create path for user file(.html)

  const_str user_file_name = enter_file_name();
  const_str html_file_name = user_file_name;

  const_str user_file      = create_file_path(html_file_name);

  file_html.open(user_file, std::ios::out);
  
  //ANCHOR:
  //3rd step - Ask the user to enter the number of students to encode as rows
  //4th step - Ask the user to enter the number of subject grades to encode as columns

  const_szt rows    = as_rows();
  const_szt columns = as_columns();

  //ANCHOR:
  //Allocate 2D double array
  //5th step - Encode student number code and grades per n subject
  //6th step - Create html tags in user file(.html) and output the encoded information
  //Deallocate 2D double array

  double **list_data = create_2d_array<double>(rows, columns);

  encode_data(list_data, rows, columns);
  create_html_table(file_html, list_data, rows, columns);

  destroy_2d_array<double>(list_data, rows);

  file_html.close();

}
