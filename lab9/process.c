#include "process.h"

int count_spaces(char* str) {
    int spaces = 0;
    for (unsigned i = 0; i<strlen(str); i++)
        if (isspace(str[i]) != 0)
            spaces++;
    return spaces;
}

void changing_string(char* str, int width){
    int count_excess_symb=width-strlen(str), spaces=count_spaces(str);
    if (count_excess_symb!=0 && spaces!=0){
        int spaces_add=(count_excess_symb/spaces);
        count_excess_symb-=spaces_add*spaces;
        if (spaces_add>0){
            for (int i=0; i<strlen(str); i++){
                if (isspace(str[i])!=0){
                    for (int j=strlen(str)+1; j>i-1; j--)
                        str[j+spaces_add]=str[j];
                    for (int k=0; k<spaces_add; k++){
                        i++;
                        str[i]=' ';
                    }
                }
            }
        }
        for (int i=0; i<strlen(str) && count_excess_symb!=0; i++){
            if (isspace(str[i])!=0){
                for (int j=strlen(str)+1; j>i-1; j--)
                    str[j+1]=str[j];
                i++;
                str[i]=' ';
                count_excess_symb--;
            }
        }
    }
}

void check_and_do(int *word_len, int *cur_len, int width, char* outp_str, char* word){
    word[*word_len]='\0';
    if (outp_str[0]=='\0'){
        strcat(outp_str, word);
        *cur_len+=*word_len;
        *word_len=0;
    }
    else if (*word_len+*cur_len<width){
        strcat(outp_str, " \0");
        strcat(outp_str, word);
        *cur_len+=*word_len+1;
        *word_len=0;
    }
    else{
        changing_string(outp_str, width);
        output_string(outp_str);
        *cur_len=0;
        outp_str[0]='\0';
        strcat(outp_str, word);
        *cur_len+=*word_len;
        *word_len=0;
    }
}

void format_output_string(char* str, int width, int max_len){
    int cur_len=0, word_len=0;
    char word[max_len+1], outp_str[width+1];
    outp_str[0]='\0';
    for (int i=0; i<strlen(str)+1; i++){
        if (str[i]=='\n'){
            check_and_do(&word_len, &cur_len, width, outp_str, word);
            puts(outp_str);
        }
        else if (str[i]==' ')
            check_and_do(&word_len, &cur_len, width, outp_str, word);
        else{
            word[word_len]=str[i];
            word_len++;
        }
    }
}

void format_output_text(char **text, int number, int width, int max_len){
    for (int i=0; i<number; i++)
        format_output_string(text[i], width, max_len);
}

int max_word_length_string(char* str){
    int max_len=0, cur_len=0;
    for (unsigned i=0; i<strlen(str); i++){
        cur_len++;
        if (str[i]==' ' || str[i]=='\n'){
            cur_len--;
            if (max_len<cur_len)
                max_len=cur_len;
            cur_len=0;
        }
    }
    return max_len;
}

int max_word_length_text(char** text, int number){
    int max_len=0, cur_len=0;
    for (int i=0; i<number; i++){
        cur_len=max_word_length_string(text[i]);
        if (cur_len>max_len){
            max_len=cur_len;
        }
    }
    return max_len;
}
