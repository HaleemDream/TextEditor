#ifndef BUFFER_READ_H
#define BUFFER_READ_H
#include <gtk/gtk.h>
#include <string.h>
GtkTextBuffer* get_text_buffer(GtkWidget*);
void set_text_buffer_text(GtkTextBuffer* buffer, char* str);
void set_text_of_text_area(GtkWidget* area, char* str);
char* read_buffer_text_from_buffer(GtkTextBuffer*);
char* read_buffer_text_from_widget(GtkWidget*);
#endif