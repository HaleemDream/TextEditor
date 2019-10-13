#include "text_area.h"

GtkWidget* get_text_area(){
    if(text_area == NULL){
        text_area = gtk_text_view_new();
        gtk_text_view_set_wrap_mode((GtkTextView*) text_area, GTK_WRAP_CHAR);
    }

    return text_area;
}