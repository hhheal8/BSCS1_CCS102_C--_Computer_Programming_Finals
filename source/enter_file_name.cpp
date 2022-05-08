#include "enter_file_name.hpp"

auto enter_file_name() -> const_str {
  
  //REVIEW: Local Variables Declaration

  std::string user_file_name = "";

  const_str dot_html_ext = ".html";

  char enter_key = 0;

  const char confirmation_key_big_y = 'Y', confirmation_key_small_y = 'y',
             confirmation_key_big_n = 'N', confirmation_key_small_n = 'n';

  int key_n_validation = 0;

  const char space_key = ' ', dot_key = '.';

  bool has_space   = false, is_valid_key = false;

  bool is_dot_html = false, is_valid_ext = false;

  size_t n_spaces  = 0;

  size_t dot_html_index = 0;

  //ANCHOR: Algorithm and Statements to Execute
  
  std::cout << "\nPLEASE DO NOT USE SPACES IN YOUR FILE NAME!";
  std::cout << "\nEnter proper file name (without spaces) and end it with \".html\" file extension   : ";
  std::getline(std::cin, user_file_name);

  for(size_t i = 0; i < user_file_name.size(); ++i) {
    if(user_file_name[i] == space_key) {
      n_spaces++;
    }
  }

  has_space  = n_spaces > 0;

  if(has_space) {
    //REVIEW: To remove spaces from the user entered file name
    user_file_name.erase(
      std::remove(
        user_file_name.begin(), user_file_name.end(), space_key
      ), 
      user_file_name.end()
    );    
  }

  //NOTE: find ".html" characters index in user entered file name
  dot_html_index = user_file_name.find(dot_html_ext);

  //NOTE: if ".html" characters is at string index, return true
  is_dot_html    = dot_html_index != std::string::npos;

  if(is_dot_html) {
    is_valid_ext = true;

    std::cout << "\nPlease review your file name before you proceed to the next step                 : \"" << user_file_name << "\"";
    std::cout << "\nPlease enter [Y/y] to confirm and [N/n] to deny and reset                        : ";
    std::cin >> enter_key;
  }

  if((enter_key == confirmation_key_big_y) || (enter_key == confirmation_key_small_y)) {
    is_valid_key = true;
  }

  if((enter_key == confirmation_key_big_n) || (enter_key == confirmation_key_small_n)) {
    is_valid_key = true;

    key_n_validation++;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return enter_file_name();
  }

  if(is_valid_ext == false) {
    system("cls");
    std::cout << "\nInvalid file format -> \"" << user_file_name << "\". File failed to create.";
    std::cout << "\nFile must end with \".html\" file extension";
    std::cout << "\nRe-enter proper file name (without spaces) and end it with \".html\" file extension:\n";

    return enter_file_name();
  }

  if(is_valid_key == false) {
    system("cls");
    std::cout << "\nInvalid confirmation key -> \"" << enter_key << "\". File failed to create.";
    std::cout << "\nPlease try again and re-enter the valid confirmation key.\n";

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return enter_file_name();
  }

  if((is_valid_ext == true) && (is_valid_key == true) && (key_n_validation < 1)) {
    system("cls");
    std::cout << "\nThe file -> \"" << user_file_name << "\" is successfully created.\n";
  }

  return user_file_name;

}

//ANCHOR: Learning reference for resetting state of `std::cin`
//LINK: https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
//LINK: https://en.cppreference.com/w/cpp/types/numeric_limits

//ANCHOR: Learning reference for STL iterator
//LINK: https://en.cppreference.com/w/cpp/algorithm/remove 