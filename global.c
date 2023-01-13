struct termios orig_termios;
typedef double real;
typedef real* field;
const int R = 25;
const int C = 50;
const int H = 10; //pix height
const int W = 10; //pix width
const int F = 55; //max num filters
const int L =100; //max weights in filter
typedef struct {
    int length;
    int r[L];
    int c[L];
    real a[L];
} filter;
int reading = 0;
real power = 2.0;
int r_span =4;
int c_span = 4;
int num_filters = 10;
int right = 5;
int down = 5;
int U = 500;
filter f[F];
real B[2][R][C];
real buffer[R][C];






