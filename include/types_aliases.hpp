#ifndef TYPES_ALIASES_H
#define TYPES_ALIASES_H

#include "library_includes.hpp"

//REVIEW: type aliases

using const_szt = const size_t;
using const_dbl = const double;
using const_str = const std::string;

struct tags {
   
  std::string style_tags;       //REVIEW: style html tags (i.e - table, td, th, etc ...)
  std::string start;            //REVIEW: starting of html - <!DOCTYPE html>

  std::string start_html;       //REVIEW: starting of html tags - <html>
  std::string start_head;       //REVIEW: starting of head - <head>
  std::string start_body;       //REVIEW: starting of body - <body>
  std::string start_heading1;   //REVIEW: starting of heading1 - <h1>
  std::string start_style;      //REVIEW: starting of style - <style>
  std::string start_table;      //REVIEW: starting of table - <table>
  std::string start_table_h;    //REVIEW: starting of table header - <th>
  std::string start_table_r;    //REVIEW: starting of table row - <tr>
  std::string start_table_d;    //REVIEW: starting of table data - <td>      

  std::string close_html;       //REVIEW: closing of html tags - </html>
  std::string close_head;       //REVIEW: closing of head - </head>
  std::string close_body;       //REVIEW: closing of body - </body>
  std::string close_heading1;   //REVIEW: closing of heading1 - </h1>
  std::string close_style;      //REVIEW: closing of style - </style>
  std::string close_table;      //REVIEW: closing of table - </table>
  std::string close_table_h;    //REVIEW: closing of table header - </th>
  std::string close_table_r;    //REVIEW: closing of table row - </tr>
  std::string close_table_d;    //REVIEW: closing of table data - </td>      

  ~tags(){} //NOTE: Destructor

};

#endif // TYPES_ALIASES_H