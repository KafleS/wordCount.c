/*****
 * Name : Suman Kafle
 * Class : CS241 
 * Lab-02 : wordCount.c 
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define IN 1
#define OUT 0
#define MAX_LEN 100

int main()
{
  int i=0;
  char line[MAX_LEN];
  int line_count = 0, word_count = 0, char_count = 0;
  int line_max_words = 0, line_max_chars = 0;
  int line_num_words = 0, line_num_chars = 0;
  int line_with_max_words = 0, line_with_max_chars = 0;

  while (fgets(line, MAX_LEN, stdin) != NULL)
  {
    int state = 0;
    ++line_count;

    line_num_words = 0;
    line_num_chars = strlen(line);

    for (i=0; line[i] != '\0'; ++i) 
    {
      if (isspace(line[i]))
      {
	    state = OUT;
      }
       else if (!state)
      {
	      ++line_num_words;
	      state = IN;
      }
    }

    if (line_num_words > line_max_words)
    {
      line_max_words = line_num_words;
      line_with_max_words = line_count;
    }
    if (line_num_chars > line_max_chars) 
    {
      line_max_chars = line_num_chars;
      line_with_max_chars = line_count;
    }

    printf("( %d) %s[%d, %d]\n", line_count, line, line_num_words, line_num_chars - 1);

    word_count += line_num_words;
    char_count += line_num_chars;
  }

  printf("%d lines, %d words, %d characters\n", line_count, word_count, char_count - line_count);
  printf("Line %d has the most words with %d\n", line_with_max_words, line_max_words);
  printf("Line %d has the most characters with %d\n", line_with_max_chars, line_max_chars - 1);

  return 0;
}
  
