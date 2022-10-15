#include <stdio.h>
#include <string.h>
#include "functions.h"

void reverseline(char* line)
{
  int size1 = strlen(line);
  for(int i=size1-1;i>=0;i--){
    printf("%c",line[i]);
  }
}