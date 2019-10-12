#include <gtk/gtk.h>
#include <stdio.h>
#include "menu/main_menu.h"
#include "buffer/read.h"
#include "action/action_entries.h"
#include "widget/text_area.h"

void activate(GtkApplication* app, gpointer user_data){
    GtkWidget* window;
    GtkWidget* text_area;
    GtkTextBuffer* text_buffer;

    //main window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Dream Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    //text area
    gtk_container_add(GTK_CONTAINER(window), get_text_area());
    
    gtk_application_set_menubar(app, (GMenuModel*) g_main_menu());

    init_actions(app);

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
