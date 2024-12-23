#ifndef PARSER_H_SENTRY
#define PARSER_H_SENTRY

#include "string.h"

#include <stdio.h>

enum param_type { pt_none, pt_section, pt_task };

enum parser_error { pe_ok, pe_eof, pe_err };

struct file_parser {
    FILE *file;
    struct string *parsed_value;
    enum param_type parsed_type; 
    int last_parsed_char;
};

struct file_parser *parser_open(const char *filename, const char *mode);
void parser_free(struct file_parser *parser);
int parse_param(struct file_parser *parser);
const char *get_parsed_value(struct file_parser *parser);

#endif
