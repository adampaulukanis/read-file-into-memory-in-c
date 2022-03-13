#include <stdlib.h>
#include <stdio.h>

/* declare pointers */
FILE  *infile;
char  *buffer;
long  numbytes;

int main() {
  /* open an existing file for reading */
  infile = fopen("main.c", "r");

  /* quit if the file does not exist */
  if (infile == NULL) {
    return 1;
  }

  /* get the number of bytes */
  fseek(infile, 0L, SEEK_END);
  numbytes = ftell(infile);

  /* reset the file position indicator to the beginning of the file */
  fseek(infile, 0L, SEEK_SET); /* is this identical to rewind()? */

  /* grab sufficient memory for the buffer to hold the text */
  buffer = (char*)calloc(numbytes, sizeof(char));

  /* memory error */
  /*
  if (buffer == NULL) {
    return 1;
  }
  */

  /* copy all the text into the buffer */
  fread(buffer, sizeof(char), numbytes, infile);
  fclose(infile);

  /* confirm we have read the file by outputting it to the console */
  printf("The file called main.c contains this text\n\n%s", buffer);

  return 0;
}
/* kaszanka */
