// I have zero clue how to get text input
// entry seems good but I do not know how to get text from it
#include <gtk/gtk.h>
//static void set_label(GtkWidget *label, gpointer data)
//{
//    gtk_label_set_text(GTK_LABEL(label), "Hello World");
//
//}
static void print_text(GtkWidget *widget,GtkWidget *entry, gpointer data)
{
    g_print("%s\n", gtk_editable_get_text(entry));
//Gtk-CRITICAL **: xx:xx:xx.xxx: gtk_editable_get_text: assertion 'GTK_IS_EDITABLE (editable)' failed
//(null)
// zero clue how gtk_editable_get_text() works
}
static void activate(GtkApplication *app, gpointer user_data){
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;
    GtkWidget *entry;
    GtkWidget *label;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello World");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
    gtk_window_set_child(GTK_WINDOW(window), box);

    entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "1+1");
    gtk_box_append(GTK_BOX(box), entry);

    button = gtk_button_new_with_label("Hello World");
    g_signal_connect(button, "clicked", G_CALLBACK(print_text), NULL);
// g_signal_connect(button, "clicked", G_CALLBACK(set_label), NULL);
// GLib-GObject-WARNING **: xx:xx:xx.xxx: invalid cast from 'GtkButton' to 'GtkLabel'
// Gtk-CRITICAL **: xx:xx:xx.xxx: gtk_label_set_text: assertion 'GTK_IS_LABEL (self)' failed 
    gtk_box_append(GTK_BOX(box), button);

    label = gtk_label_new("");
    gtk_box_append(GTK_BOX(box), label);

    gtk_widget_show(window);
}

int main(int argc, char **argv){
    GtkApplication *app;
    int status;
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}