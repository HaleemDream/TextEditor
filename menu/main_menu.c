#include "main_menu.h"

//WIP
GMenu* g_main_menu(){
    //main menu
    GMenu* main_menu = g_menu_new();

    //file menu
    GMenu* file_menu = g_menu_new();

    //file menu children
    g_menu_insert(file_menu, 0, "Open", "Open");
    g_menu_insert(file_menu, 1, "Save", "Save");
    g_menu_insert(file_menu, 2, "Close", "Close");
    
    //about menu
    GMenu* about_menu = g_menu_new();
    g_menu_insert(about_menu, 0, "Version", "Version");

    //about menu children
    g_menu_append_submenu(main_menu, "File", (GMenuModel*) file_menu);
    g_menu_append_submenu(main_menu, "About", (GMenuModel*) about_menu);

    return main_menu;
}