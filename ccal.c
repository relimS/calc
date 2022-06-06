// I am trying to write a calculator that can do basic math. I have zero clue how to get text input, GTK entry seems good but I cannot get text from it.
// btw, I am using the GTK-4.0 library
#include <gtk/gtk.h>
#include <string.h>
static void a(GtkWidget *entry, GtkWidget *button, gpointer data)
{
    printf(GTK_IS_EDITABLE(entry) ? "true\n" : "false\n"); // debug code, output false (unexpected)

/*
I wanted to write
    char text[] = gtk_editable_get_text(GTK_ENTRY(entry)); // should output string but entry isn't editable in this case so it outputs nothing
and a parser, calculate and change label contents
*/
//Github copilot gives this but gtk_entry_get_text() doesn't exist in GTK-4.0
//    char text[] = gtk_entry_get_text(GTK_ENTRY(entry));
}
static void activate(GtkApplication *app, gpointer user_data){
// declare widgets
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;
    GtkWidget *entry;
    GtkWidget *label;
// define widgets
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello World");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
    gtk_window_set_child(GTK_WINDOW(window), box);

// Text input
    entry = gtk_entry_new();
    gtk_editable_get_editable(GTK_ENTRY(entry));
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "1+1");
    gtk_box_append(GTK_BOX(box), entry);
    printf(GTK_IS_EDITABLE(entry) ? "true\n" : "false\n"); // debug code, output true (expected)
// The button is supposed to call a function that will read entry, calculate the answer and shows it in label
    button = gtk_button_new_with_label("Hello World");
    g_signal_connect(button, "clicked", G_CALLBACK(a), NULL); // call function a when button is clicked
    gtk_box_append(GTK_BOX(box), button);

// label shows the result of the calculation but I cannot get text input so I did not write any code for it
    label = gtk_label_new("");
    gtk_box_append(GTK_BOX(box), label);

    gtk_widget_show(window);
}

int main(int argc, char **argv){ // taken directly from gtk-4.0 hello-world example
    GtkApplication *app;
    int status;
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}