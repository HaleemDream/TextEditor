#include "read.h"

char* read_file(char* path){
    FILE *fp = fopen(path, "r");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    //buffer to read in
    char* buffer = NULL; 

    //read line by line from file and add to buffer while realloc
    while((read = getline(&line, &len, fp)) != -1){
        if(buffer == NULL){
            buffer = calloc(read, sizeof(char));
            strncpy(buffer, line, read);
        } else {
            char* newPtr;
            if(newPtr = realloc(buffer,  strlen(buffer) + 1 + read)){
                buffer = newPtr;
                strncat(buffer, line, read);
            }
        }
    }

    free(line);
    fclose(fp);

    return buffer;
}