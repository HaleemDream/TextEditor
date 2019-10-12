#ifndef BUFFER_READ_H
#define BUFFER_READ_H
#include <gtk/gtk.h>
GtkTextBuffer* get_text_buffer(GtkWidget*);
char* read_buffer_text_from_buffer(GtkTextBuffer*);
char* read_buffer_text_from_widget(GtkWidget*);
#endif