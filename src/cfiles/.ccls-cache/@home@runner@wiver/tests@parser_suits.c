#include "../test_main.h"

START_TEST(parser_1) {
  char filename[50] = "tests_files/1.obj\0";
  struct parser_output output;
  output.points = NULL;
  output.points_count = 0;
  output.poligons_count = 0;
  parse_obj_file("tests/tests_files/1.obj", &output);
  ck_assert_int_eq(1, 1);
}

Suite *suite_parser(void) {
  Suite *s22;
  TCase *tc22;
  s22 = suite_create("parser");
  tc22 = tcase_create("parser");
  tcase_add_test(tc22, parser_1);
  suite_add_tcase(s22, tc22);
  return s22;
}