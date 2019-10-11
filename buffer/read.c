#include "read.h"

char* read_buffer_text(GtkTextBuffer* buffer){
    GtkTextIter* start = malloc(sizeof(GtkTextIter));
    GtkTextIter* end = malloc(sizeof(GtkTextIter));

    gtk_text_buffer_get_start_iter(buffer, start);
    gtk_text_buffer_get_end_iter(buffer, end);

    gchar* text = gtk_text_buffer_get_text(buffer, start, end, FALSE);
    printf("%s\n", text);

    free(start);
    free(end);

    return text;
}