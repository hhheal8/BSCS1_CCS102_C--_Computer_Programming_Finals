#include "create_destroy_arrays.hpp"
#include "create_file_path.hpp"
#include "encode_data.hpp"
#include "enter_file_name.hpp"
#include "information_number.hpp"
#include "write_to_file.hpp"

/*

  REVIEW: 
  Variable naming convention - snake_case (ex. variable_name)

  Function implementation/declaration syntax - east end function style (ex. auto fun() -> bool;)
  LINK: https://www.danielsieger.com/blog/2022/01/28/cpp-trailing-return-types.html#:~:text=Trailing%20return%20types%20are%20an%20alternative%20syntax%20introduced,of%20the%20function%3A%20int%20max%28int%20a%2C%20int%20b%29%3B
  
  Some of my video learning reference
  LINK: https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67490s

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

/*

  //TODO:
  Things you'll be dealing with this project
  1. Pass by Pointer
  2. Pass by Reference/const Reference
  3. Variable Allocation and Deallocation 
  4. Some C++11 features

  //REVIEW:
  Here are some VS Code Extension that might help you write code efficiently
  1. C++ Algorithm Mnemonics - David Brötje
  2. C++ Helper - amir
  3. Code Spell Checker - Street Side Software
  4. Error Lens - Alexander
  5. Comment Anchors - Starlane Studios

*/
