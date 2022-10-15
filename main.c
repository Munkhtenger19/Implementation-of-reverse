#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define line_size 1024

int main(int argc, char *argv[]){
  FILE *file;
  char line[line_size];
  if(argc==1){
    int str_size=8;
    int line_cnt=0;
    char** content = malloc((sizeof(char*))* str_size);
    while(fgets(line,sizeof(line),stdin)!=NULL){
      if(line_cnt >= str_size){
        str_size *= 2;
        content = realloc (content, str_size*sizeof(char*));
        if (content == NULL ) {
          printf("Memory reallocation failed");
          exit(0);
        }
      }
      content[line_cnt] = malloc(line_size * sizeof(char));
      if (content == NULL) {
        printf("Memory allocation failed!");
        exit(1);
      }
      if(line[strlen(line)-1]=='\n'){
        line[strlen(line)-1]='\0';
      }
      strcpy(content[line_cnt],line);
      line_cnt++;
    }
    for(int i=line_cnt-1;i>=0;i--){ 
      printf("%d ",i+1);reverseline(content[i]);printf("\n");
      free(content[i]);
    }
    free(content);
  }
  else{
    for(int i=1;i<argc;i++){       
      int str_size=8;
      int line_cnt=0;
      char** content = malloc(str_size*sizeof(char*));
      if(content==NULL){            
        perror("Memory allocation failed!");
        exit(1);
      }
      file=fopen(argv[i],"r");
      if(file==NULL){            
        perror("File opening unsuccessful!");
      }

      while(fgets(line,sizeof(line),file)!=NULL) {
           
        if(line_cnt >= str_size){
                
          str_size *= 2;
          content = realloc (content, str_size*sizeof(char*));
          if (content == NULL){
          
            printf("Memory reallocation failed");
            exit(1);
          }
        }
        content[line_cnt] = malloc(line_size * sizeof(char));
        if (content == NULL) {
          printf("Memory allocation failed!");
          exit(1);
        }
        if(line[strlen(line)-1]=='\n'){
                    line[strlen(line)-1]='\0';
        }
        strcpy(content[line_cnt],line);
        line_cnt++;
      }
      for(int i=line_cnt-1;i>=0;i--){
        printf("%d ",i+1);reverseline(content[i]);printf("\n");
        free(content[i]);
      }
      free(content);
      fclose(file);
    }
  }

  return 0;
}