#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;  // Keep track of the number of characters printed

    while (*format != '\0') {
        if (*format == '%') {
            format++;  // Move past the '%'

            // Handle the conversion specifiers
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
            }
        } else {
            putchar(*format);
            count++;
        }

        format++;  // Move to the next character in the format string
    }

    va_end(args);

    return count;
}

