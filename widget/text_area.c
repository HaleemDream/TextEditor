#include "text_area.h"

GtkWidget* get_text_area(){
    if(text_area == NULL){
        text_area = gtk_text_view_new();
    }

    return text_area;
}