
int hue_from(real x) { 
    return (int)trunc( (128.0 *(x + 1.0)) ); 
}

real rnd() {
    return 1.0 - 2*(rand()/((real)RAND_MAX));
}

void randomize_buffers() { 
    for (int r = 0; r < R ; r++) for (int c = 0 ; c < C ; c++ ) {
        B[reading][r][c] = rnd();
        B[!reading][r][c] = rnd();
    }      
}

void plot_reading_buffer() {
    int brightness = 0;
    for (int r = 0; r < R ; r++) for (int c = 0 ; c < C ; c++ ) {
        cursor_to(r,c);
        brightness = hue_from(B[reading][r][c]);
        set_color(brightness,brightness,brightness);
        printf("\u2588");
    }
}
void plot_buffer() {
    int brightness = 0;
    cursor_to(down,right);
    set_color(255,255,255);
    printf("ffl0 %d %d %d %20d",R,C,F,U);
    for (int r = 0; r < R ; r++) for (int c = 0 ; c < C ; c++ ) {
        cursor_to(r+down+1,c+right);
        brightness = hue_from(buffer[r][c]);
        set_color(brightness,brightness,brightness);
        printf("\u2588");
    }
}
void randomize_buffer() { 
    for (int r = 0; r < R ; r++) for (int c = 0 ; c < C ; c++ ) {
        buffer[r][c] = rnd();
    }      
}