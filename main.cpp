#include "create_destroy_arrays.hpp"
#include "create_file_path.hpp"
#include "encode_data.hpp"
#include "enter_file_name.hpp"
#include "information_number.hpp"
#include "write_to_file.hpp"

/*

  REVIEW: 
  Variable naming convention - snake_case (ex. variable_name)
  Tab size - 2

  Function implementation/declaration syntax - east end function style (ex. auto fun() -> bool;)
  LINK: https://www.danielsieger.com/blog/2022/01/28/cpp-trailing-return-types.html#:~:text=Trailing%20return%20types%20are%20an%20alternative%20syntax%20introduced,of%20the%20function%3A%20int%20max%28int%20a%2C%20int%20b%29%3B
  
  Some of my video learning reference
  LINK: https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67490s

  LINK: https://en.cppreference.com/

  //TODO:
  Things you'll be dealing with this project
  1. Pass by Pointer
  2. Pass by Reference/const Reference
  3. Variable Allocation and Deallocation 
  4. Some C++11 features

*/

auto main() -> int {

  std::fstream file_html; //REVIEW: Instantiate fstream class

  //ANCHOR: 
  //1st step - Ask the user to enter the name of the file(.html)
  //2nd step - Create path for user file(.html)

  const_str user_file_name = enter_file_name();
  const_str html_file_name = user_file_name;

  const_str user_file      = create_file_path(html_file_name);

  file_html.open(user_file, std::ios::out); //REVIEW: Open in output mode
  
  //ANCHOR:
  //3rd step - Ask the user to enter the number of students to encode as rows for 2D array
  //4th step - Ask the user to enter the number of subject grades to encode as columns for 2D array
  //5th step - Ask the user to enter the name of the subject as columns for 2D array

  const_szt rows    = as_rows();
  const_szt columns = as_columns();

  std::string *list_subj = create_1d_array<std::string>(columns);
  enter_subject_name(list_subj, columns);

  //ANCHOR:
  //Allocate 1D string array, 2D double array
  //6th step - Encode student number code and grades per n subject
  //7th step - Create html tags in user file(.html) and output the encoded information
  //Deallocate 1D string array, 2D double array
  
  std::string *list_n_code = create_1d_array<std::string>(rows);

  double **list_data = create_2d_array<double>(rows, columns);

  encode_data(list_n_code, list_subj, list_data, rows, columns);

  create_html_table(
    file_html, list_n_code, 
    list_subj, list_data, 
    rows, columns
  );

  destroy_1d_array<std::string>(list_subj, columns);
  destroy_1d_array<std::string>(list_n_code, rows);
  destroy_2d_array<double>(list_data, rows);

  file_html.close();

}

/*

  //REVIEW:
  Here are some VS Code Extension that might help you write code efficiently
  1. C++ Algorithm Mnemonics - David Br??tje
  2. C++ Helper - amir
  3. Code Spell Checker - Street Side Software
  4. Error Lens - Alexander
  5. Comment Anchors - Starlane Studios

*/