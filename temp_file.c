#include <stdlib.h>
#include <unistd.h>

/* A handle for a temporary file created with write_temp_file. in
   this implementatin, it's just a file descriptor. */
typedef int temp_file_handle;

/* Writes LENGTH bytes from BUFFER into a temporary file. The
   temporary file is immediately unlinked. Returns a handle to the 
   temporary_file. */

temp_file_handle write_temp_file (char* buffer, size_t length)
{
    /* Create a filename and file. The XXXXXX will be replaced with
       characteres that make the filename unique. */
    char temp_filename[] = "/tmp/temp_file.XXXXXX";

    int fd = mkstemp(temp_filename);

    /* Unlink the file immediatelt, so that it will be removed when the
       file descriptor is closed. */
    unlink(temp_filename);

    /* Write the number of bytes to the file first. */
    write( fd, &length, sizeof(length));

    /* Now write the data itself */
    write (fd, buffer, length);

    /* Use the file descriptor as the handle for the temp file. */
    return fd;
}

