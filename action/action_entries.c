#include "action_entries.h"
#include "../buffer/read.h"
#include "../widget/text_area.h"

/*
    todo - find better alt way to get text_area ref
         - move file saving stuff else where
         - get parent ref
         - maybe refactor filechoosediag to new home
*/

//action methods
void save_active(GSimpleAction* a, GVariant* param, gpointer app){
    GtkWidget* dialog;
    GtkFileChooser* chooser;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
    gint res;

    //TODO Get parent window
    dialog = gtk_file_chooser_dialog_new("Save File",
                                          NULL,
                                          action,
                                          "Cancel",
                                          GTK_RESPONSE_CANCEL,
                                          "Save",
                                          GTK_RESPONSE_ACCEPT,
                                          NULL);

    chooser = GTK_FILE_CHOOSER(dialog);

    res = gtk_dialog_run(GTK_DIALOG(dialog));

    if(res == GTK_RESPONSE_ACCEPT){
        //path
        char* filename = gtk_file_chooser_get_filename(chooser);
        char* text = read_buffer_text_from_widget(get_text_area());

        //save to file
        FILE *fp = fopen(filename, "w+");
        fputs(text, fp);
        fclose(fp);
        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

void close_active(GSimpleAction* action, GVariant* param, gpointer app){
    g_application_quit(G_APPLICATION(app));
}

//action definitions
static GActionEntry app_entries[] ={
     {"close", close_active, NULL, NULL, NULL},
     {"save", save_active, NULL, NULL, NULL}
};

//called in main to link actions
void init_actions(GtkApplication* app){
    g_action_map_add_action_entries(G_ACTION_MAP(app), app_entries, G_N_ELEMENTS(app_entries), app);
}