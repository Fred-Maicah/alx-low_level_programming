#include <fcntl.h>  /* for open */
#include <unistd.h> /* for read, write, close */
#include <stdlib.h> /* for malloc, free, exit */

#define BUFFER_SIZE 1024

void *create_buffer(size_t size);
void copy_file(const char *file_from, const char *file_to);
void handle_error(const char *message, int exit_code);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        handle_error("Usage: cp file_from file_to\n", 97);
    }

    copy_file(argv[1], argv[2]);

    return 0;
}

void *create_buffer(size_t size) {
    void *buffer = malloc(size);
    if (buffer == NULL) {
        handle_error("Error: Can't allocate memory\n", 99);
    }
    return buffer;
}

void copy_file(const char *file_from, const char *file_to) {
    int fd_from, fd_to, read_bytes;
    char *buffer = create_buffer(BUFFER_SIZE);

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        free(buffer);
        handle_error("Error: Can't read from file\n", 98);
    }

    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_to == -1) {
        close(fd_from);
        free(buffer);
        handle_error("Error: Can't write to file\n", 99);
    }

    while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd_to, buffer, read_bytes) != read_bytes) {
            close(fd_from);
            close(fd_to);
            free(buffer);
            handle_error("Error: Can't write to file\n", 99);
        }
    }

    if (read_bytes == -1) {
        close(fd_from);
        close(fd_to);
        free(buffer);
        handle_error("Error: Can't read from file\n", 98);
    }

    close(fd_from);
    close(fd_to);
    free(buffer);
}

void handle_error(const char *message, int exit_code) {
    /* Write the error message to stderr */
    size_t len = 0;
    while (message[len] != '\0') {
        len++;
    }
    write(STDERR_FILENO, message, len);
    exit(exit_code);
}

