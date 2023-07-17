#include "../test_main.h"
void do_suite(Suite *suite, int *res) {
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  *res += srunner_ntests_failed(runner);
  srunner_free(runner);
}


int main(void) {
  Suite *test_suites[] = {
      suite_s21_matrix(), 
};
int res = 0;        
    for (size_t i = 0; i < ARRAY_SIZE(test_suites); i++) {
        do_suite(test_suites[i], &res);
      printf("\n\n");
  }
  if (res) {
    printf("\e[0;31m");
  } else {
    printf("\e[0;32m");
  }


}