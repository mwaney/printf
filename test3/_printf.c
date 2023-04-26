#include "main.h"

int _printf(const char *format, ...) {
	va_list args;
	int buffer_index = 0, chars_printed = 0, result;
	char buffer[BUFFER_SIZE];

	va_start(args, format);

	while (*format != '\0') {
		if (*format == '%') {
			format++;
			result = handle_format_specifier(format, args, buffer,
					&buffer_index, BUFFER_SIZE,
					&chars_printed);
			if (result < 0) {
				va_end(args);
				return -1;
			}
			format += result;
		} else {
			buffer[buffer_index++] = *format++;
			if (buffer_index >= BUFFER_SIZE) {
				write_buffer(buffer, BUFFER_SIZE, &chars_printed,
						&buffer_index);
			}
		}
	}

	write_buffer(buffer, BUFFER_SIZE, &chars_printed, &buffer_index);

	va_end(args);

	return chars_printed;
}

void write_buffer(const char *buffer, int size, int *chars_printed, int *buffer_index) {
	int result;

	if (*buffer_index == 0) {
		return;
	}
	result = write(STDOUT_FILENO, buffer, *buffer_index);
	if (result == -1) {
		return;
	}
	*chars_printed += result;
	*buffer_index = 0;
	(void)size;
}
