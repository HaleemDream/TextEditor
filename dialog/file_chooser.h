#ifndef FILE_CHOOSER
#define FILE_CHOOSER
#include <gio/gio.h>
#include <gtk/gtk.h>
GtkWidget* dialog;
GtkFileChooser* chooser;
GtkFileChooserAction action;
GtkWidget* get_dialog(GtkFileChooserAction, char*, char*);
#endif