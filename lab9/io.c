#include "io.h"

char* input_str(){
    char symb=getchar();
    int count=1, len_str=1;
    char* str=memory_string(len_str+2);
    if (str==NULL)
        return NULL;
    str[0]='\n';
    str[1]='\0';
    for (int i=0; symb!='\n'; i++){
        if (len_str<count){
            char temp[len_str+2];
            strcpy(temp, str);
            free(str);
            len_str*=2;
            str=memory_string(len_str+2);
            if (str==NULL)
                return NULL;
            strcpy(str, temp);
        }
        str[i]=symb;
        str[i+1]='\n';
        str[i+2]='\0';
        symb=getchar();
        count++;
    }
    char temp[strlen(str)+1];
    strcpy(temp, str);
    free(str);
    str=memory_string(strlen(temp)+1);
    if (str==NULL)
        return NULL;
    strcpy(str, temp);
    return str;
}

char** input_text(int *number){
    printf(FORMAT_OUTPUT_HELLO_STRING_TEXT);
    *number=0;
    int count=0;
    char* new_line=input_str();
    char** text=memory_mass_strings(*number);
    if (text==NULL || new_line==NULL){
        errors_func(FORMAT_OUTPUT_STRING_MEMORY_ERROR_NUMBER);
        return NULL;
    }
    for (int i=0; strlen(new_line)!=1; i++){
        if (*number==count){
            char** temp=memory_mass_strings(*number);
            if (temp==NULL){
                errors_func (FORMAT_OUTPUT_STRING_MEMORY_ERROR_NUMBER);
                return NULL;
            }
            for (int j=0; j<*number; j++)
                temp[j]=text[j];
            free_mas_strings(text);
            *number+=1;
            text=memory_mass_strings(*number);
            if (text==NULL){
                errors_func(FORMAT_OUTPUT_STRING_MEMORY_ERROR_NUMBER);
                return NULL;
            }
            for (int j=0; j<*number; j++)
                text[j]=temp[j];
            free_mas_strings(temp);
        }
        text[i]=new_line;
        count++;
        new_line=input_str();
    }
    return text;
}

int input_width(int *width, int min_length){
    printf(FORMAT_OUTPUT_HELLO_WIDTH);
    if (scanf("%d", width)!=SUCCES_WIDTH){
        errors_func(FORMAT_OUTPUT_STRING_WIDTH_ERROR_NUMBER);
        return 0;
    }
    if (*width<=0 || *width<min_length){
        errors_func(FORMAT_OUTPUT_STRING_WIDTH_ERROR_NUMBER);
        return 0;
    }
    return SUCCES_WIDTH;
}

void output_string(char* str){
    puts(str);
}

