void respond() {
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");
    if (c == 'q') exit(0);
    if ( c == ' ' ) randomize_buffer();
    if (c == 'f' ) load_filters(r_span,c_span);
    if (c == 'p') { power = 5*rnd();load_filters(r_span,c_span);}
    if (c == '1') f[0] = random_filter();
    if (c == '2') f[1] = random_filter();
    if (c == '3') f[2] = random_filter();
    if (c == '4') f[3] = random_filter();
    if (c == '5') f[4] = random_filter();
    if (c == '6') f[5] = random_filter();
    if (c == '7') f[6] = random_filter();
    if (c == '8') f[7] = random_filter();
    if (c == '9') f[8] = random_filter();
    if (c == '0') f[9] = random_filter();
    if (c == 'm') U += 10;
    if (c == 'n') {U -= 10; if (U <= 0) U = 0;}
}