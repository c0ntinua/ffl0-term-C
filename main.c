
int main(void) {
    int r, c, cells = 200;
    clear_screen();
    start_raw_mode();
    hide_cursor();
    randomize_buffer();
    load_filters(3,3);     
    while (1)  {
        plot_buffer();
        for (int k = 0; k < U; k++) {
            r = rand()%R;
            c = rand()%C;
            for (int i = 0 ; i < F ; i++) {
                filter_cell(i,r,c); 
            }
            
        }
        respond();

    }
    return 0;
}