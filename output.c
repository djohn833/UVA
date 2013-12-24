int pos_in_line = 1;

void
indent(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        putchar(' ');
        pos_in_line++;
    }
}

void
newline()
{
    putchar('\n');
    pos_in_line = 1;
}

void
pad_to_len(int n)
{
    while (pos_in_line++ <= n)
        putchar(' ');
}

void
print_fmt(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    pos_in_line += vprintf(fmt, args);
    va_end(args);
}

void
print_binary(int n, int width)
{
    int i;
    for (i = width-1; i >= 0; i--)
        putchar((n & (1<<i)) ? '1' : '0');
}

