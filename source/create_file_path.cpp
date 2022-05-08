#include "create_file_path.hpp"

auto create_file_path(const_str &user_file_name) -> const_str {

  //REVIEW: Local Variable Declaration

  const_str file_path = "../html/";

  const_str file_path_name = file_path + user_file_name;
  const_str user_file_path = file_path_name;

  return user_file_path;

}

//ANCHOR: Learning reference for setting file path for fstream file
//LINK: https://stackoverflow.com/questions/8068921/how-to-use-fstream-objects-with-relative-path
