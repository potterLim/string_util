# string_util

`string_util` is a C89-compliant utility library providing a comprehensive suite of functions for string manipulation. Designed with strict adherence to memory management best practices, it offers robust and efficient tools for common string operations, such as trimming, replacing, splitting, and validating strings.

## Features

- **Validation**: Check if a string contains numeric, alphabetic, or alphanumeric characters.
- **Analysis**: Identify specific characters or substrings within a string.
- **Manipulation**: Perform operations like case conversion, whitespace trimming, string reversal, and substring replacement.
- **Utilities**: Safely copy strings, truncate them to a specific length with optional ellipsis, and split them into tokens based on a delimiter.

For detailed descriptions and usage, see the header file: `string_util.h`.

## Requirements

- **Compiler**: Clang 18.1.8
- **Target Platform**: `i686-pc-windows-msvc`
- **Compilation Flags**: `-std=c89 -Wall -pedantic-errors`

## Implementation Details

- Functions with dynamic memory allocation include the `_malloc` suffix, clearly indicating the caller’s responsibility to free memory.
- Robust input validation:
  - `NULL` inputs are validated to prevent undefined behavior.
  - Functions return `NULL` pointers or specific error codes on failure.
- Strict compliance with the C89 standard ensures compatibility with legacy systems and compilers.
- Uniform behavior across all functions:
  - Empty strings are treated as valid inputs where applicable.
  - Graceful handling of memory allocation failures to maintain stability.

### Thorough Testing
`string_util` has been extensively tested under diverse scenarios, including edge cases, to ensure reliability and correctness. The provided `main` function includes a comprehensive test suite demonstrating typical usage and edge case handling.

## Compilation

To compile and use the `string_util` library, follow these instructions based on your operating system:

### For Windows Users

- If you only need the `string_util` library:
  ```  
  clang -std=c89 -Wall -pedantic-errors -D_CRT_SECURE_NO_WARNINGS -o string_util.lib string_util.c
  ```

- To compile and run the provided test cases (included in `main.c`):
  ```  
  clang -std=c89 -Wall -pedantic-errors -D_CRT_SECURE_NO_WARNINGS -o string_util_test.exe string_util.c main.c
  ```

  - Run the executable:
    ```
    ./string_util_test.exe
    ```

**Important**: The `-D_CRT_SECURE_NO_WARNINGS` flag suppresses warnings related to secure function usage in MSVC environments. These warnings can be safely ignored for this library.

### For Unix-like Systems (Linux/macOS)

- If you only need the `string_util` library:
  ```
  clang -std=c89 -Wall -pedantic-errors -o string_util string_util.c
  ```

- To compile and run the provided test cases (included in `main.c`):
  ```
  clang -std=c89 -Wall -pedantic-errors -o string_util_test string_util.c main.c
  ```

  - Run the executable:
    ```
    ./string_util_test
    ```

## Contribution

We welcome contributions to improve `string_util`. Here’s how you can contribute:

### Report Issues

If you encounter bugs or have feature suggestions, please open an issue with detailed information.

### Make Changes

1. **Fork the Repository**: Create your own copy of the repository.
2. **Create a Branch**: Use a descriptive branch name: `git checkout -b feature/your-feature`
3. **Make Changes**: Implement your changes, ensuring adherence to C89 standards and repository conventions.
4. **Commit and Push**:
   - Commit your changes with a meaningful message: `git commit -m "Describe your changes"`
   - Push your branch to your fork: `git push origin feature/your-feature`
5. **Submit a Pull Request**: Open a pull request with a detailed description of your changes.

Whether reporting an issue or proposing new features, your input helps us improve the library.

## Contact

If you have questions, suggestions, or discussions, please reach out by opening an issue or starting a discussion in the repository.   
Alternatively, you can email us at: [potterLim0808@gmail.com](mailto:potterLim0808@gmail.com)

Your feedback is always welcome!