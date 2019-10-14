#include "read.h"

//todo - make buffer/write?

GtkTextBuffer* get_text_buffer(GtkWidget* widget){
    return gtk_text_view_get_buffer((GtkTextView*) widget);
}

void set_text_buffer_text(GtkTextBuffer* buffer, char* str){
    gtk_text_buffer_set_text(buffer, str, strlen(str));
}

void set_text_of_text_area(GtkWidget* area, char* str){
    set_text_buffer_text(get_text_buffer(area), str);
}

//read from start to end
char* read_buffer_text_from_buffer(GtkTextBuffer* buffer){
    GtkTextIter* start = malloc(sizeof(GtkTextIter));
    GtkTextIter* end = malloc(sizeof(GtkTextIter));

    gtk_text_buffer_get_start_iter(buffer, start);
    gtk_text_buffer_get_end_iter(buffer, end);

    gchar* text = gtk_text_buffer_get_text(buffer, start, end, FALSE);

    free(start);
    free(end);

    return text;
}

//read from start to end
char* read_buffer_text_from_widget(GtkWidget* widget){
    return read_buffer_text_from_buffer(get_text_buffer(widget));
}