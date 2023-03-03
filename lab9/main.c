#include "process.h"
#include "io.h"
int main(){
    int number, min_width, width;
    char** text=input_text(&number);
    if (text!=NULL){
        min_width=max_word_length_text(text, number);
        if(input_width(&width, min_width)){
            format_output_text(text, number, width, min_width);
        }
    }
    return 0;
}
