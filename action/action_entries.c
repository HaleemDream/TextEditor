#include "action_entries.h"

//action methods
void close_active(GSimpleAction* action, GVariant* param, gpointer app){
    g_application_quit(G_APPLICATION(app));
}

//action definitions
static GActionEntry app_entries[] ={
     {"close", close_active, NULL, NULL, NULL}
};

//called in main to link actions
void init_actions(GtkApplication* app){
    g_action_map_add_action_entries(G_ACTION_MAP(app), app_entries, G_N_ELEMENTS(app_entries), app);
}