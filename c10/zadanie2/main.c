#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <locale.h>
#include <wchar.h>


//-----------------------------magic squares

#define TABLE_SIZE 128
int A[TABLE_SIZE];
int B[TABLE_SIZE];
int lastSize=0;
int should_end_now=0;
volatile int skip_this_square=0;
void initMagicSquare()
{
    skip_this_square=0;
    should_end_now=0;
    lastSize=0;
    for(int i=0;i<TABLE_SIZE;++i)
    {
        A[i]=0;
        B[i]=0;
    }
}
int validateMagicSquare(int *tb,int row_size)
{
	int magic_sum=(row_size*(row_size*row_size+1))/2;
	for(int i=0;i<row_size;++i)
	{
		int sum=0;
		for(int j=0;j<row_size;++j)
		{
			int index=i*row_size+j;
			sum+=tb[index];
		}
		if(sum!=magic_sum)
			return 0;
	}
	for(int i=0;i<row_size;++i)
	{
		int sum=0;
		for(int j=0;j<row_size;++j)
		{
			int index=i+j*row_size;
			sum+=tb[index];
		}
		if(sum!=magic_sum)
			return 0;
	}
	{
		int sum=0;
		for(int i=0;i<row_size;++i)
		{
			int index=i*row_size+i;
			sum+=tb[index];
		}
		if(sum!=magic_sum)
			return 0;
	}
	{
		int sum=0;
		for(int i=0;i<row_size;++i)
		{
			int index=i*row_size+(row_size-i-1);
			sum+=tb[index];
		}
		if(sum!=magic_sum)
			return 0;
	}
	return 1;
}
void writeArray(FILE *stream,int *tb,int size)
{
    for(int i=0;i<size;++i)
        fprintf(stream,"%d,",tb[i]);
    fprintf(stream,"\n");
}
void writeMagicSquare(FILE *stream,int *tb,int row_size)
{
	for(int i=0;i<row_size;++i)
	{
		writeArray(stream,tb+i*row_size,row_size);
	}
}
void magicPermute(int n,int size)
{

	for(int i=1;i<=size*size;++i)
    {
        if(should_end_now)
            return;
        if(A[n-1]!=0 && skip_this_square==1)
        {
            i=A[n-1];
            B[i]=0;
        }
		if(B[i]==0)
		{
			B[i]=1;A[n-1]=i;
			if(n%size==0)
			{
				int sum=0;
				for(int i=n-size;i<n;++i)
					sum+=A[i];
				if(sum==(size*(size*size+1))/2)
				{
					if(n<size*size)
						magicPermute(n+1,size);
					else
					{
						if(validateMagicSquare(A,size))
						{
						    if(skip_this_square==1)
                            {
                                skip_this_square=0;
                                B[i]=0;
                                A[n-1]=0;
                                //g_print("skipped square!!!");
                                return;
                            }
						    //g_print("SQUARE\n");
						    //writeMagicSquare(stdout,A,size);
						    skip_this_square = 1;
							should_end_now = 1;
                            return;
						}
					}
				}
			}
			else
			{
				magicPermute(n+1,size);
			}
			if(should_end_now)
                return;
			B[i]=0;
			A[n-1]=0;
		}
    }
}
int nextPermutation(int s)
{
    if(s!=lastSize)
    {
        //g_print("change size");
        initMagicSquare();
        lastSize=s;
    }
    magicPermute(1,s);
    should_end_now=0;
    if(A[0]!=0)
        skip_this_square=1;
    return 1;
}

//-----------------------------


typedef struct programsettings
{
    int square_size;
    GtkWidget *square_container;

}ProgramSettings;

ProgramSettings global_settings;

GtkWidget * number_square_new_from_tb(int *tb,int row_size)
{

    GtkWidget *table = 0;
    GtkWidget *label_box = 0;
    if(tb[0]==0)
    {
        table = gtk_table_new(1,1,1);
        label_box = gtk_button_new_with_label("No more squares");
        gtk_table_attach_defaults(GTK_TABLE(table),label_box,0,1,0,1);
        return table;
    }
    char buff[256];
    table = gtk_table_new(row_size,row_size,1);

    for(int i=0;i<row_size;++i)
    {
        for(int j=0;j<row_size;++j)
        {
            int index = i*row_size+j;
            sprintf(buff,"%d",tb[index]);
            label_box = gtk_button_new_with_label(buff);
            gtk_table_attach_defaults(GTK_TABLE(table),label_box,j,j+1,i,i+1);
        }
    }
    return table;
}

void parseArgs(int argc, char *argv[])
{

    /*if can't parse args then defaults specified below are applied*/
    int square_size=1;
    GOptionEntry entries[] =
    {
        {"square_size",'s', 0, G_OPTION_ARG_INT, &square_size, "Sets square size",0},
        {0}
    };

    GError *error = NULL;
    GOptionContext *context;
    context = g_option_context_new("- test");
    g_option_context_add_main_entries(context, entries, 0);
    g_option_context_add_group(context, gtk_get_option_group (TRUE));
    if (!g_option_context_parse (context, &argc, &argv, &error))
    {
      g_print ("option parsing failed: %s\n", error->message);
      exit (1);
    }

    global_settings.square_size = square_size;
    global_settings.square_container = gtk_frame_new("Square");
}




void on_button_clicked()
{
   // printf("Clicked");
    GList *children, *iter;
    children = gtk_container_get_children(GTK_CONTAINER(global_settings.square_container));
    for(iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_container_remove(GTK_CONTAINER(global_settings.square_container),GTK_WIDGET(iter->data));


    //int test_tb[global_settings.square_size*global_settings.square_size];
    //for(int i=0;i<global_settings.square_size*global_settings.square_size;++i)
    //    test_tb[i]=i;
    nextPermutation(global_settings.square_size);
    GtkWidget *square = number_square_new_from_tb(A,global_settings.square_size);
   // g_print("Square generated!");
    //GtkWidget *square = gtk_button_new_with_label("lol");
    gtk_container_add(GTK_CONTAINER(global_settings.square_container), square);
    gtk_widget_show_all (global_settings.square_container); /*all new widgets are hidden by default*/
}

void on_spin_box_value_change_event(GtkSpinButton *spinbutton,GtkScrollType  arg1,gpointer user_data)
{
    global_settings.square_size = (int)gtk_spin_button_get_value(spinbutton);
}

static GtkWidget * buildInterface(int argc, char *argv[])
{
    /*init GTK*/
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
    gtk_init (&argc, &argv);
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);
    /*create window*/
    GtkWidget *win = 0;
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Magic Squares");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);
    /*create layout*/
    GtkWidget *layout_v = 0;
    GtkWidget *layout_h = 0;
    layout_v = gtk_vbox_new(1, 1);
    layout_h = gtk_hbox_new(1, 1);
    gtk_container_add(GTK_CONTAINER(win), layout_v);
    gtk_container_add(GTK_CONTAINER(layout_v), layout_h);
    GtkWidget *button = 0;
    GtkWidget *label = 0;
    GtkWidget *spin = 0;
    button = gtk_button_new_with_label("Find next");
    label = gtk_label_new("Square size");
    spin = gtk_spin_button_new_with_range(1,4,1.0);
    gtk_spin_button_set_value((GtkSpinButton*)spin,global_settings.square_size);
    gtk_container_add(GTK_CONTAINER(layout_h), label);
    gtk_container_add(GTK_CONTAINER(layout_h), spin);
    gtk_container_add(GTK_CONTAINER(layout_v), button);
    gtk_container_add(GTK_CONTAINER(layout_v), global_settings.square_container);
    g_signal_connect(G_OBJECT(spin), "value-changed",G_CALLBACK(on_spin_box_value_change_event), NULL);
    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(on_button_clicked), NULL);


    return win;
}


int main (int argc, char *argv[])
{
    /*
    *Program pozwala ustalic poprzez parametr
    *wywolania programu rozmiar generowanego kwadratu
    *mozna np. podac -s 3
    */
    parseArgs(argc,argv);
    GtkWidget *win = 0;
    win = buildInterface(argc,argv);
    gtk_widget_show_all (win);
    gtk_main ();
    return 0;
}
