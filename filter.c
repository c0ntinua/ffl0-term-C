filter _random_filter(int r, int c) {
    filter new_filter;
    new_filter.length = (2*r + 1)*(2*c + 1);
    int piece_index =0;
    for (int i = -r ; i <= r; i++) for (int j = -c; j <= c; j++) {
        new_filter.r[piece_index] = i;
        new_filter.c[piece_index] = j;
        new_filter.a[piece_index] = power*rnd();
        piece_index++;
    }
    return new_filter;
}

filter random_filter() {
    return _random_filter(rand()%r_span+1,rand()%c_span+1);
}

void load_filters(int r, int c) {
    for (int i = 0; i < F; i++) f[i] = _random_filter(r,c);
}

int safe(int i, int M) {
    if (i < 0) return i + M;
    if (i > M -1) return i - M;
    return i;
}

void filter_cell(int i, int r, int c) {
    real sum = 0;
    for (int piece_index = 0; piece_index < f[i].length; piece_index++) {
        int row = safe(r + f[i].r[piece_index],R);
        int col = safe(c + f[i].c[piece_index],C);
        sum += buffer[row][col]*f[i].a[piece_index];
    }
    buffer[r][c] = tanh(sum);
}







