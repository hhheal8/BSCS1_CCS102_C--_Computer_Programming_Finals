#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H

#include "types_aliases.hpp"

auto create_html_table(std::fstream &file_html, double **table_data, const_szt &rows, const_szt &columns) -> void;

#endif // WRITE_TO_FILE_H