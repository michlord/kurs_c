/*
*Michal Zimniak
*indeks 258375
*lista 10
*zadanie 1
*/

#include <stdlib.h>
#include <gtk/gtk.h>

int votes_amt=0;
int votes_for=0;
int votes_against=0;

GtkWidget *label_total=0;
GtkWidget *label_for=0;
GtkWidget *label_against=0;

void update_labels()
{
    char msg[256];
    sprintf(msg, "Liczba oddanych glosow: %d", votes_amt);
    gtk_label_set_text((GtkLabel*)label_total,msg);
    sprintf(msg, "Procent glosow za: %.2f %%", (float)votes_for/(float)votes_amt*100.0f);
    gtk_label_set_text((GtkLabel*)label_for,msg);
    sprintf(msg, "Procent glosow przeciw: %.2f %%", (float)votes_against/(float)votes_amt*100.0f);
    gtk_label_set_text((GtkLabel*)label_against,msg);
}

void button_for_clicked(GtkWidget *widget, gpointer data)
{
  //g_print("clicked for\n");
  ++votes_amt;
  ++votes_for;
  update_labels();
}
void button_against_clicked(GtkWidget *widget, gpointer data)
{
  //g_print("clicked against\n");
  ++votes_amt;
  ++votes_against;
  update_labels();
}
void button_undecided_clicked(GtkWidget *widget, gpointer data)
{
  //g_print("clicked undecided\n");
  ++votes_amt;
  update_labels();
}


static void initGTK(int argc, char *argv[])
{
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
    gtk_init (&argc, &argv);
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);
}

static GtkWidget * buildInterface(const char *voting_reason)
{
    /*Build window*/
    GtkWidget *win = 0;
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Glosowanie");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);
    /*Create layouts*/
    /*
    * VBOX(
    *   VOTING REASON
    *   HBOX(FOR, AGAINST, UNDECIDED)
    *   VOTES AMT
    *   VOTES FOR
    *   VOTES AGAINST
    *  )
    */
    GtkWidget *vbox = 0;
    GtkWidget *hbox = 0;
    vbox = gtk_vbox_new(1, 1);
    hbox = gtk_hbox_new(1, 1);
    gtk_container_add(GTK_CONTAINER(win), vbox);
    GtkWidget *label = 0;
    label = gtk_label_new(voting_reason);
    gtk_container_add(GTK_CONTAINER(vbox), label);
    gtk_container_add(GTK_CONTAINER(vbox), hbox);

    GtkWidget *button = 0;
    button = gtk_button_new_with_label("Za");
    gtk_container_add(GTK_CONTAINER(hbox), button);
    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(button_for_clicked), NULL);
    button = gtk_button_new_with_label("Przeciw");
    gtk_container_add(GTK_CONTAINER(hbox), button);
    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(button_against_clicked), NULL);
    button = gtk_button_new_with_label("Nie mam zdania");
    gtk_container_add(GTK_CONTAINER(hbox), button);
    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(button_undecided_clicked), NULL);

    label = gtk_label_new("Liczba oddanych glosow: 0");
    gtk_container_add(GTK_CONTAINER(vbox), label);
    label_total=label;
    label = gtk_label_new("Procent glosow za: 0.00 %");
    gtk_container_add(GTK_CONTAINER(vbox), label);
    label_for=label;
    label = gtk_label_new("Procent glosow przeciw: 0.00 %");
    gtk_container_add(GTK_CONTAINER(vbox), label);
    label_against=label;

    return win;
}

int main (int argc, char *argv[])
{
    initGTK(argc,argv);
    GtkWidget *win = 0;
    win = buildInterface("Czy zalegalizowac marihuane?");
    gtk_widget_show_all (win);
    gtk_main ();
    return 0;
}
