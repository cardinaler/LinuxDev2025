#include <stdio.h>
#include <assert.h>
#include <check.h>
#include <string.h>
#include "roman_tools.h"
#include "const.h"
START_TEST(test_dummy) 
{
 	assert(roman_to_dec("I") == 1);
}
END_TEST
 
START_TEST(test_roman_to_dec) 
{
 	for(int i = 0; i < romans_amount; ++i)
	{
		assert(roman_to_dec(roman_table[i]) == i + 1);
	}
}
END_TEST

START_TEST(test_dec_to_roman) 
{
 	for(int i = 0; i < romans_amount; ++i)
	{
		assert(strcmp(dec_to_roman(i + 1), roman_table[i]) == 0);
	}
}
END_TEST



int main(int argc, char *argv[]) 
{
	Suite *suite = suite_create("Dummy");
	TCase *testcase = tcase_create("Dummy");
	SRunner *runner = srunner_create(suite);
	int ret;

	suite_add_tcase(suite, testcase);
	tcase_add_test(testcase, test_dummy);
	tcase_add_test(testcase, test_roman_to_dec); 
	tcase_add_test(testcase, test_dec_to_roman);
	srunner_run_all(runner, CK_ENV);
	ret = srunner_ntests_failed(runner);
	srunner_free(runner);
	return ret != 0;
}
