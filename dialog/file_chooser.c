#include "file_chooser.h"

//might revert
GtkWidget* get_dialog(GtkFileChooserAction chooser_action, char* dialog_name, char* action){
    dialog = gtk_file_chooser_dialog_new(dialog_name,
                                        NULL,
                                        chooser_action,
                                        "Cancel",
                                        GTK_RESPONSE_CANCEL,
                                        action,
                                        GTK_RESPONSE_ACCEPT,
                                        NULL);

    chooser = GTK_FILE_CHOOSER(dialog);
}