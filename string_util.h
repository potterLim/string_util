#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <stddef.h>

#define TRUE (1)
#define FALSE (0)

/* Check if a string contains only numeric characters.
   Parameters:
     - str: Pointer to the string to check. If NULL, the function returns FALSE.

   Behavior:
     - If str is empty (""), this function returns TRUE (since there are no non-numeric chars).

   Returns:
     - TRUE if the string contains only numeric characters.
     - FALSE if the string contains any non-numeric characters or if the input string is NULL.
*/
int is_numeric(const char* str);

/* Check if a string contains only alphabetic characters.
   Parameters:
     - str: Pointer to the string to check. If NULL, the function returns FALSE.

   Behavior:
     - If str is empty (""), this function returns TRUE (since there are no non-alphabetic chars).

   Returns:
     - TRUE if the string contains only alphabetic characters.
     - FALSE if the string contains any non-alphabetic characters or if the input string is NULL.
*/
int is_alpha(const char* str);

/* Check if a string contains only alphanumeric characters.
   Parameters:
     - str: Pointer to the string to check. If NULL, the function returns FALSE.

   Behavior:
     - If str is empty (""), this function returns TRUE (since there are no non-alphanumeric chars).

   Returns:
     - TRUE if the string contains only alphanumeric characters.
     - FALSE if the string contains any non-alphanumeric characters or if the input string is NULL.
*/
int is_alphanumeric(const char* str);

/* Check if a character is present in the string.
   Parameters:
     - str: Pointer to the string to search. If NULL, the function returns FALSE.
     - ch: The character to search for.

   Returns:
     - TRUE if the character is found in the string.
     - FALSE if the character is not found or if the input string is NULL.
*/
int contains_char(const char* str, char ch);

/* Check if a substring is present in the string.
   Parameters:
     - str: Pointer to the string to search. If NULL, the function returns FALSE.
     - sub: Pointer to the substring to search for. If NULL, the function returns FALSE.

   Returns:
     - TRUE if the substring is found in the string, including if the substring is an empty string (""),
       which is considered found at index 0 by standard C library functions.
     - FALSE if the substring is not found, or if either input string is NULL.
*/
int contains_substring(const char* str, const char* sub);

/* Convert a string to uppercase (returns dynamically allocated memory).
   Parameters:
     - str: Pointer to the input string. If NULL, the function returns NULL.

   Returns:
     - Pointer to the newly allocated string converted to uppercase.
     - NULL if memory allocation fails or the input string is NULL.

   Note:
     - The caller is responsible for freeing the returned string.
*/
char* to_uppercase_malloc(const char* str);

/* Convert a string to lowercase (returns dynamically allocated memory).
   Parameters:
     - str: Pointer to the input string. If NULL, the function returns NULL.

   Returns:
     - Pointer to the newly allocated string converted to lowercase.
     - NULL if memory allocation fails or the input string is NULL.

   Note:
     - The caller is responsible for freeing the returned string.
*/
char* to_lowercase_malloc(const char* str);

/* Trim leading and trailing whitespaces (returns dynamically allocated memory).
   Parameters:
     - str: Pointer to the input string. If NULL, the function returns NULL.

   Returns:
     - Pointer to the newly allocated string with leading and trailing whitespaces removed.
       If the input string is empty or contains only whitespace, an empty string ("") is returned.
     - NULL if memory allocation fails or the input string is NULL.

   Note:
     - The caller is responsible for freeing the returned string.
*/
char* trim_malloc(const char* str);

/* Reverse a string (returns dynamically allocated memory).
   Parameters:
     - str: Pointer to the input string. If NULL, the function returns NULL.

   Returns:
     - Pointer to the newly allocated reversed string.
     - NULL if memory allocation fails or the input string is NULL.

   Note:
     - The caller is responsible for freeing the returned string.
*/
char* reverse_string_malloc(const char* str);

/* Safely copy a string with buffer size checking.
   Parameters:
     - dest: Pointer to the destination buffer.
     - dest_size: Size of the destination buffer.
     - src: Pointer to the source string.

   Returns:
     - 0 if the string is copied successfully.
     - 1 if the source string is truncated.
     - -1 if the input parameters are invalid.
*/
int safe_str_copy(char* dest, size_t dest_size, const char* src);

/* Truncate a string to a specific length with ellipsis (returns dynamically allocated memory).
   Parameters:
     - str: Pointer to the input string. If NULL, the function returns NULL.
     - max_length: Maximum length of the truncated string including the ellipsis.
     - ellipsis: Pointer to the ellipsis string to append. Can be NULL.

   Returns:
     - Pointer to the newly allocated truncated string with ellipsis appended.
     - NULL if memory allocation fails or the input string is NULL.

   Note:
     - The caller is responsible for freeing the returned string.
*/
char* truncate_string_malloc(const char* str, size_t max_length, const char* ellipsis);

/* Replace a substring with another substring (returns dynamically allocated memory).
   Parameters:
     - str: Pointer to the input string. If NULL, the function returns NULL.
     - old_sub: Pointer to the substring to replace. If NULL or empty, the function returns NULL.
     - new_sub: Pointer to the substring to replace with. If NULL, the function returns NULL.

   Returns:
     - Pointer to the newly allocated string with replacements made.
     - NULL if memory allocation fails or the input parameters are invalid.

   Note:
     - The caller is responsible for freeing the returned string.
*/
char* string_replace_malloc(const char* str, const char* old_sub, const char* new_sub);

/* Split a string into tokens based on a delimiter (returns dynamically allocated array and strings).
   Parameters:
     - str: Pointer to the input string. If NULL, the function returns NULL.
     - delimiter: Pointer to the delimiter string. If NULL or empty, the function returns NULL.
     - out_count: Pointer to a variable where the number of tokens will be stored. If NULL, the function returns NULL.

   Returns:
     - Pointer to the newly allocated array of strings (tokens).
     - NULL if memory allocation fails or the input parameters are invalid.

   Note:
     - Each token in the returned array is also dynamically allocated.
     - The caller must free each token and then free the array itself.
*/
char** split_malloc(const char* str, const char* delimiter, size_t* out_count);

#endif /* STRING_UTIL_H */
