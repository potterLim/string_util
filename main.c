#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_util.h"

#define BUFFER_SIZE (256)

/* Function prototypes */
static void test_is_numeric(void);
static void test_is_alpha(void);
static void test_is_alphanumeric(void);
static void test_contains_char(void);
static void test_contains_substring(void);
static void test_to_uppercase_malloc(void);
static void test_to_lowercase_malloc(void);
static void test_trim_malloc(void);
static void test_reverse_string_malloc(void);
static void test_safe_str_copy(void);
static void test_truncate_string_malloc(void);
static void test_string_replace_malloc(void);
static void test_split_malloc(void);

int main(void)
{
    test_is_numeric();
    test_is_alpha();
    test_is_alphanumeric();
    test_contains_char();
    test_contains_substring();
    test_to_uppercase_malloc();
    test_to_lowercase_malloc();
    test_trim_malloc();
    test_reverse_string_malloc();
    test_safe_str_copy();
    test_truncate_string_malloc();
    test_string_replace_malloc();
    test_split_malloc();

    printf("All tests passed!\n");
    return 0;
}

static void test_is_numeric(void)
{
    assert(is_numeric("12345") == TRUE);
    assert(is_numeric("0000") == TRUE);

    assert(is_numeric("12a45") == FALSE);
    assert(is_numeric("") == TRUE);

    assert(is_numeric(NULL) == FALSE);
}

static void test_is_alpha(void)
{
    assert(is_alpha("hello") == TRUE);
    assert(is_alpha("WORLD") == TRUE);

    assert(is_alpha("hello123") == FALSE);
    assert(is_alpha("12345") == FALSE);
    assert(is_alpha("!@#") == FALSE);

    assert(is_alpha("") == TRUE);

    assert(is_alpha(NULL) == FALSE);
}

static void test_is_alphanumeric(void)
{
    assert(is_alphanumeric("hello123") == TRUE);
    assert(is_alphanumeric("HELLO") == TRUE);
    assert(is_alphanumeric("12345") == TRUE);

    assert(is_alphanumeric("hello!") == FALSE);
    assert(is_alphanumeric("123@") == FALSE);
    assert(is_alphanumeric("") == TRUE);

    assert(is_alphanumeric(NULL) == FALSE);
}

static void test_contains_char(void)
{
    assert(contains_char("hello", 'e') == TRUE);
    assert(contains_char("hello", 'z') == FALSE);

    assert(contains_char("world", 'w') == TRUE);

    assert(contains_char("example", 'e') == TRUE);

    assert(contains_char("", 'a') == FALSE);

    assert(contains_char(NULL, 'a') == FALSE);
}

static void test_contains_substring(void)
{
    assert(contains_substring("hello world", "world") == TRUE);
    assert(contains_substring("hello world", "hello") == TRUE);
    assert(contains_substring("hello world", "o w") == TRUE);

    assert(contains_substring("hello world", "") == TRUE);
    assert(contains_substring("", "") == TRUE);

    assert(contains_substring("hello world", "test") == FALSE);
    assert(contains_substring("", "test") == FALSE);

    assert(contains_substring(NULL, "test") == FALSE);
    assert(contains_substring("hello world", NULL) == FALSE);
    assert(contains_substring(NULL, NULL) == FALSE);
}

static void test_to_uppercase_malloc(void)
{
    char* pa_result;

    pa_result = to_uppercase_malloc("hello");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "HELLO") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = to_uppercase_malloc("");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = to_uppercase_malloc("Hello123!");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "HELLO123!") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = to_uppercase_malloc(NULL);
    assert(pa_result == NULL);
}

static void test_to_lowercase_malloc(void)
{
    char* pa_result;

    pa_result = to_lowercase_malloc("HELLO");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "hello") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = to_lowercase_malloc("");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = to_lowercase_malloc("Hello123!");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "hello123!") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = to_lowercase_malloc(NULL);
    assert(pa_result == NULL);
}

static void test_trim_malloc(void)
{
    char* pa_result;

    pa_result = trim_malloc("  hello  ");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "hello") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = trim_malloc("   hello");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "hello") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = trim_malloc("hello   ");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "hello") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = trim_malloc("hello");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "hello") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = trim_malloc("      ");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = trim_malloc("");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = trim_malloc(NULL);
    assert(pa_result == NULL);
}

static void test_reverse_string_malloc(void)
{
    char* pa_result;

    pa_result = reverse_string_malloc("hello");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "olleh") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = reverse_string_malloc("a");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "a") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = reverse_string_malloc("");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, "") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = reverse_string_malloc(NULL);
    assert(pa_result == NULL);

    pa_result = reverse_string_malloc("123@! ");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, " !@321") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = reverse_string_malloc("  1 2  3@! ");
    assert(pa_result != NULL);
    assert(strcmp(pa_result, " !@3  2 1  ") == 0);
    free(pa_result);
    pa_result = NULL;
}

static void test_safe_str_copy(void)
{
    char buffer[10];

    assert(safe_str_copy(buffer, sizeof(buffer), "hello") == 0);
    assert(strcmp(buffer, "hello") == 0);

    assert(safe_str_copy(buffer, sizeof(buffer), "hello world") == 1);
    assert(strncmp(buffer, "hello wor", 9) == 0);
    assert(buffer[9] == '\0');

    assert(safe_str_copy(NULL, sizeof(buffer), "hello") == -1);
    assert(safe_str_copy(buffer, 0, "hello") == -1);
    assert(safe_str_copy(buffer, sizeof(buffer), NULL) == -1);
}

static void test_truncate_string_malloc(void)
{
    char* pa_result;

    pa_result = truncate_string_malloc("", 10, "...");
    assert(strcmp(pa_result, "") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = truncate_string_malloc("hello", 10, "...");
    assert(strcmp(pa_result, "hello") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = truncate_string_malloc("hello world", 8, "...");
    assert(strcmp(pa_result, "hello...") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = truncate_string_malloc("hello world", 5, NULL);
    assert(strcmp(pa_result, "hello") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = truncate_string_malloc("hello world", 0, "...");
    assert(pa_result == NULL);

    pa_result = truncate_string_malloc(NULL, 10, "...");
    assert(pa_result == NULL);
}

static void test_string_replace_malloc(void)
{
    char* pa_result;

    pa_result = string_replace_malloc("hello world", "world", "there");
    assert(strcmp(pa_result, "hello there") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = string_replace_malloc("aaa bbb aaa", "aaa", "ccc");
    assert(strcmp(pa_result, "ccc bbb ccc") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = string_replace_malloc("hello world", "test", "there");
    assert(strcmp(pa_result, "hello world") == 0);
    free(pa_result);
    pa_result = NULL;

    pa_result = string_replace_malloc("hello world", "", "test");
    assert(pa_result == NULL);
    pa_result = NULL;

    pa_result = string_replace_malloc(NULL, "test", "there");
    assert(pa_result == NULL);
}

static void test_split_malloc(void)
{
    char** pa_result;
    size_t i;
    size_t count;

    pa_result = split_malloc("a,b,c", ",", &count);
    assert(count == 3);
    assert(strcmp(pa_result[0], "a") == 0);
    assert(strcmp(pa_result[1], "b") == 0);
    assert(strcmp(pa_result[2], "c") == 0);
    for (i = 0; i < count; i++) {
        free(pa_result[i]);
        pa_result[i] = NULL;
    }
    free(pa_result);
    pa_result = NULL;

    pa_result = split_malloc("a,,b", ",", &count);
    assert(count == 3);
    assert(strcmp(pa_result[0], "a") == 0);
    assert(strcmp(pa_result[1], "") == 0);
    assert(strcmp(pa_result[2], "b") == 0);
    for (i = 0; i < count; i++) {
        free(pa_result[i]);
        pa_result[i] = NULL;
    }
    free(pa_result);
    pa_result = NULL;

    pa_result = split_malloc("", ",", &count);
    assert(count == 1);
    assert(strcmp(pa_result[0], "") == 0);
    for (i = 0; i < count; i++) {
        free(pa_result[i]);
        pa_result[i] = NULL;
    }
    free(pa_result);
    pa_result = NULL;

    pa_result = split_malloc(NULL, ",", &count);
    assert(pa_result == NULL);
}
