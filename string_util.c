#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "string_util.h"

int is_numeric(const char* str)
{
    if (str == NULL) {
        return FALSE;
    }

    while (*str != '\0') {
        if (!isdigit((unsigned char)*str)) {
            return FALSE;
        }
        str++;
    }

    return TRUE;
}

int is_alpha(const char* str)
{
    if (str == NULL) {
        return FALSE;
    }

    while (*str != '\0') {
        if (!isalpha((unsigned char)*str)) {
            return FALSE;
        }
        str++;
    }

    return TRUE;
}

int is_alphanumeric(const char* str)
{
    if (str == NULL) {
        return FALSE;
    }

    while (*str != '\0') {
        if (!isalnum((unsigned char)*str)) {
            return FALSE;
        }
        str++;
    }

    return TRUE;
}

int contains_char(const char* str, char ch)
{
    if (str == NULL) {
        return FALSE;
    }

    while (*str != '\0') {
        if (*str == ch) {
            return TRUE;
        }
        str++;
    }

    return FALSE;
}

int contains_substring(const char* str, const char* sub)
{
    if (str == NULL || sub == NULL) {
        return FALSE;
    }

    if (strstr(str, sub) != NULL) {
        return TRUE;
    }

    return FALSE;
}

char* to_uppercase_malloc(const char* str)
{
    size_t i;
    size_t length;
    char* pa_result;

    if (str == NULL) {
        return NULL;
    }

    length = strlen(str);

    pa_result = (char*)malloc(length + 1);
    if (pa_result == NULL) {
        return NULL;
    }

    for (i = 0; i < length; ++i) {
        pa_result[i] = toupper((unsigned char)str[i]);
    }
    pa_result[length] = '\0';

    return pa_result;
}

char* to_lowercase_malloc(const char* str)
{
    size_t i;
    size_t length;
    char* pa_result;

    if (str == NULL) {
        return NULL;
    }

    length = strlen(str);

    pa_result = (char*)malloc(length + 1);
    if (pa_result == NULL) {
        return NULL;
    }

    for (i = 0; i < length; ++i) {
        pa_result[i] = tolower((unsigned char)str[i]);
    }
    pa_result[length] = '\0';

    return pa_result;
}

char* trim_malloc(const char* str)
{
    const char* start;
    const char* end;
    char* pa_result;
    size_t length;

    if (str == NULL) {
        return NULL;
    }

    start = str;
    while (*start != '\0' && isspace((unsigned char)*start)) {
        start++;
    }

    end = str + strlen(str) - 1;
    while (end >= start && isspace((unsigned char)*end)) {
        end--;
    }

    if (end < start) {
        length = 0;
    } else {
        length = (size_t)(end - start + 1);
    }

    pa_result = (char*)malloc(length + 1);
    if (pa_result == NULL) {
        return NULL;
    }

    if (length > 0) {
        strncpy(pa_result, start, length);
    }
    pa_result[length] = '\0';

    return pa_result;
}

char* reverse_string_malloc(const char* str)
{
    size_t length;
    size_t i;
    char* pa_reversed;

    if (str == NULL) {
        return NULL;
    }

    length = strlen(str);

    if (length == 0) {
        pa_reversed = (char*)malloc(1);
        if (pa_reversed == NULL) {
            return NULL;
        }
        pa_reversed[0] = '\0';
        return pa_reversed;
    }

    pa_reversed = (char*)malloc(length + 1);
    if (pa_reversed == NULL) {
        return NULL;
    }

    for (i = 0; i < length; i++) {
        pa_reversed[i] = str[length - i - 1];
    }
    pa_reversed[length] = '\0';

    return pa_reversed;
}

int safe_str_copy(char* dest, size_t dest_size, const char* src)
{
    size_t src_length;

    if (dest == NULL || src == NULL) {
        return -1;
    }

    if (dest_size == 0) {
        return -1;
    }

    src_length = strlen(src);

    if (src_length >= dest_size) {
        strncpy(dest, src, dest_size - 1);
        dest[dest_size - 1] = '\0';
        return 1;
    }

    strcpy(dest, src);
    return 0;
}

char* truncate_string_malloc(const char* str, size_t max_length, const char* ellipsis)
{
    size_t str_length;
    size_t ellipsis_length;
    size_t copy_length;
    char* pa_truncated;

    if (str == NULL) {
        return NULL;
    }

    if (max_length == 0) {
        return NULL;
    }

    str_length = strlen(str);

    if (ellipsis != NULL) {
        ellipsis_length = strlen(ellipsis);
    }
    else {
        ellipsis_length = 0;
    }

    if (str_length == 0) {
        pa_truncated = (char*)malloc(1);
        if (pa_truncated == NULL) {
            return NULL;
        }
        pa_truncated[0] = '\0';
        return pa_truncated;
    }

    if (str_length <= max_length) {
        pa_truncated = (char*)malloc(str_length + 1);
        if (pa_truncated == NULL) {
            return NULL;
        }
        strcpy(pa_truncated, str);
        return pa_truncated;
    }

    if (ellipsis_length < max_length) {
        copy_length = max_length - ellipsis_length;
    }
    else {
        copy_length = 0;
    }

    pa_truncated = (char*)malloc(max_length + 1);
    if (pa_truncated == NULL) {
        return NULL;
    }

    strncpy(pa_truncated, str, copy_length);
    pa_truncated[copy_length] = '\0';

    if (ellipsis != NULL && ellipsis_length > 0) {
        strncat(pa_truncated, ellipsis, ellipsis_length);
    }

    return pa_truncated;
}

char* string_replace_malloc(const char* str, const char* old_sub, const char* new_sub)
{
    const char* current;
    const char* next;
    size_t old_length;
    size_t new_length;
    size_t count;
    size_t result_length;
    char* pa_result;
    char* dest;

    if (str == NULL || old_sub == NULL || new_sub == NULL) {
        return NULL;
    }

    old_length = strlen(old_sub);
    new_length = strlen(new_sub);

    if (old_length == 0) {
        return NULL;
    }

    current = str;
    count = 0;

    while ((next = strstr(current, old_sub)) != NULL) {
        count++;
        current = next + old_length;
    }

    result_length = strlen(str) + count * (new_length - old_length) + 1;

    pa_result = (char*)malloc(result_length);
    if (pa_result == NULL) {
        return NULL;
    }

    current = str;
    dest = pa_result;

    while ((next = strstr(current, old_sub)) != NULL) {
        size_t prefix_length = next - current;
        memcpy(dest, current, prefix_length);
        dest += prefix_length;

        memcpy(dest, new_sub, new_length);
        dest += new_length;

        current = next + old_length;
    }

    strcpy(dest, current);

    return pa_result;
}

char** split_malloc(const char* str, const char* delimiter, size_t* out_count)
{
    size_t count = 0;
    const char* current;
    const char* next;
    char** pa_result;
    size_t delimiter_length;
    size_t token_length;
    size_t i;
    size_t j;

    if (str == NULL || delimiter == NULL || out_count == NULL) {
        return NULL;
    }

    delimiter_length = strlen(delimiter);
    if (delimiter_length == 0) {
        return NULL;
    }

    current = str;
    while ((next = strstr(current, delimiter)) != NULL) {
        count++;
        current = next + delimiter_length;
    }
    count++;

    pa_result = (char**)malloc(count * sizeof(char*));
    if (pa_result == NULL) {
        return NULL;
    }

    current = str;
    i = 0;

    while ((next = strstr(current, delimiter)) != NULL) {
        token_length = next - current;
        pa_result[i] = (char*)malloc(token_length + 1);
        if (pa_result[i] == NULL) {
            for (j = 0; j < i; j++) {
                free(pa_result[j]);
                pa_result[j] = NULL;
            }
            free(pa_result);
            pa_result = NULL;
            return NULL;
        }
        strncpy(pa_result[i], current, token_length);
        pa_result[i][token_length] = '\0';
        i++;
        current = next + delimiter_length;
    }

    pa_result[i] = (char*)malloc(strlen(current) + 1);
    if (pa_result[i] == NULL) {
        for (j = 0; j < i; j++) {
            free(pa_result[j]);
            pa_result[j] = NULL;
        }
        free(pa_result);
        pa_result = NULL;
        return NULL;
    }
    strcpy(pa_result[i], current);

    *out_count = count;
    return pa_result;
}
