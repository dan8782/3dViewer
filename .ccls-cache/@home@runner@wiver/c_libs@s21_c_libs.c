#include "../s21_c_libs.h"
#include "string.h"


int parse_obj_file(char *file_path, struct parser_output *output) {
  FILE *file;
  char ch;
  file = fopen(file_path, "r");
  int resut_code = 1;
  // Проверяем, удалось ли открыть файл
  if (file != NULL) {
    parser_handler(file, output);
    fclose(file);
  }
  else {
    resut_code = 0;
  }
  
  
  
  return resut_code;
}
int parser_handler(FILE *file, struct parser_output *output){
  char string[1024] = "\0";
  while (fgets(string, sizeof(string), file) != NULL) {
        // Если первый символ f - обработка точки
        // Если первый символ v - обработка полигона
        printf("%s", string); // Просто выводим на экран считанную строку
    }
  return 1;
}
int point_handler(struct parser_output *output)