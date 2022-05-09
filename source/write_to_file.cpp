#include "write_to_file.hpp"

auto create_html_table(std::fstream &file_html, double **table_data, const_szt &rows, const_szt &columns) -> void {

  //REVIEW: Local Variable Declarations

  tags *html_tags = new tags();

  html_tags->start       = "<!DOCTYPE html>";
  html_tags->start_html  = "\n<html>";
  html_tags->start_head  = "\n<head>";
  html_tags->start_style = "\n<style>";

html_tags->style_tags = R"css(
table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%
}
td, th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 6px;
}
tr:nth-child(even) {
  background-color: #dddddd;
}
)css";

  html_tags->close_style = "</style>";
  html_tags->close_head  = "\n</head>";

  html_tags->start_body  = "\n<body>";

  html_tags->start_table = "\n<table>";
  html_tags->start_table_r = "\n\t<tr>";
  html_tags->start_table_h = "\n\t\t<th>";
  html_tags->start_table_d = "\n\t\t<td>";

  html_tags->close_table_r = "\n\t</tr>";
  html_tags->close_table_h = "</th>";
  html_tags->close_table_d = "</td>";

  html_tags->close_table = "\n</table>";
  
  html_tags->close_body = "\n</body>";

  html_tags->close_html = "\n</html>";

  double sum_grades    = 0;
  double average_grade = 0;

  const_str user_average_msg1 = "Failed";
  const_str user_average_msg2 = "Needs Improvement";
  const_str user_average_msg3 = "Satisfactory";
  const_str user_average_msg4 = "Good";
  const_str user_average_msg5 = "Excellent";

  //ANCHOR: Output in file(.html)
  //ANCHOR: Algorithm and Statements to execute

  file_html << html_tags->start;
  file_html << html_tags->start_html;

  file_html << "\n";

  file_html << html_tags->start_head;
  file_html << html_tags->start_style;

  file_html << html_tags->style_tags;

  file_html << html_tags->close_style;
  file_html << html_tags->close_head;

  file_html << "\n";

  file_html << html_tags->start_body;

  file_html << html_tags->start_table;

  for(size_t i = 0; i < rows; i++) { 

    file_html << html_tags->start_table_r;

    for(size_t j = 0; j < columns; j++) {
      file_html << html_tags->start_table_h << "Student Number Code" << html_tags->close_table_h;
      break;
    }

    for(size_t k = 1; k < columns + 1; k++) {
      file_html << html_tags->start_table_h << "Subject Grade No. " << k << html_tags->close_table_h;
    }

    for(size_t l = 1; l < columns; l++) {
      file_html << html_tags->start_table_h << "Average Grade" << html_tags->close_table_h;
      break;
    }

    for(size_t m = 1; m < columns; m++) {
      file_html << html_tags->start_table_h << "Result" << html_tags->close_table_h;
      break;
    }

    file_html << html_tags->close_table_r;

    break;

  }

  for(size_t i = 0; i < rows; i++) {

    file_html << html_tags->start_table_r;

    for(size_t j = 0; j < columns; j++) {

      file_html << html_tags->start_table_d << std::fixed << std::setprecision(0) << table_data[i][j] << html_tags->close_table_d;

      break;

    }

    for(size_t k = 1; k < columns + 1; k++) {

      sum_grades += table_data[i][k];

      file_html << html_tags->start_table_d<< std::fixed << std::setprecision(2) << table_data[i][k] << html_tags->close_table_d;

    }

    for(size_t l = 1; l < columns; l++) {

      average_grade = sum_grades / columns;

      if(average_grade <= 60) {
        file_html << html_tags->start_table_d << std::fixed << std::setprecision(2) << average_grade << html_tags->close_table_d;
      }

      else if(average_grade <= 75) {
        file_html << html_tags->start_table_d << std::fixed << std::setprecision(2) << average_grade << html_tags->close_table_d;
      }

      else if(average_grade <= 85) {
        file_html << html_tags->start_table_d << std::fixed << std::setprecision(2) << average_grade << html_tags->close_table_d;
      }

      else if(average_grade <= 90) {
        file_html << html_tags->start_table_d << std::fixed << std::setprecision(2) << average_grade << html_tags->close_table_d;
      }

      else if(average_grade <= 100) {
        file_html << html_tags->start_table_d << std::fixed << std::setprecision(2) << average_grade << html_tags->close_table_d;
      }

      sum_grades = 0;

      break;

    }

    for(size_t m = 1; m < columns; m++) {

      if(average_grade <= 60) {
        file_html << html_tags->start_table_d << user_average_msg1 << html_tags->close_table_d;
      }

      else if(average_grade <= 75) {
        file_html << html_tags->start_table_d << user_average_msg2 << html_tags->close_table_d;
      }

      else if(average_grade <= 85) {
        file_html << html_tags->start_table_d << user_average_msg3 << html_tags->close_table_d;
      }

      else if(average_grade <= 90) {
        file_html << html_tags->start_table_d << user_average_msg4 << html_tags->close_table_d;
      }

      else if(average_grade <= 100) {
        file_html << html_tags->start_table_d << user_average_msg5 << html_tags->close_table_d;
      }

      average_grade = 0;

      break;

    }      

    file_html << html_tags->close_table_r;

  }

  file_html << html_tags->close_table;

  file_html << html_tags->close_body;

  file_html << "\n";

  file_html << html_tags->close_html;

  delete html_tags;
  html_tags = nullptr;

}

//ANCHOR: Learning reference for HTML table
//LINK: https://www.w3schools.com/html/html_tables.asp