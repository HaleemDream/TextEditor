#include <gtk/gtk.h>
#include "main_menu.h"

void on_text_change(GtkTextBuffer* buffer, gpointer user_data){
    //method to get data

    /*GtkTextIter* start = malloc(sizeof(GtkTextIter));
    GtkTextIter* end = malloc(sizeof(GtkTextIter));

    gtk_text_buffer_get_start_iter(buffer, start);
    gtk_text_buffer_get_end_iter(buffer, end);

    gchar* text = gtk_text_buffer_get_text(buffer, start, end, FALSE);
    printf("%s\n", text);

    free(start);
    free(end);
    */
}

void activate(GtkApplication* app, gpointer user_data){
    GtkWidget* window;
    GtkWidget* text_area;
    GtkTextBuffer* text_buffer;

    //main window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Dream Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    //text area
    text_area = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(window), text_area);

    //text buffer
    text_buffer = gtk_text_view_get_buffer((GtkTextView*) text_area);

    //text area change signal
    g_signal_connect(text_buffer, "changed", G_CALLBACK(on_text_change), NULL);
    
    //Main Menu Bar
    main_menu menu;

    gtk_application_set_menubar(app, (GMenuModel*) menu.g_main_menu());
    
    gtk_widget_show_all(window);
}

int main(int argc, char **argv){
    GtkApplication* app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run (G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
