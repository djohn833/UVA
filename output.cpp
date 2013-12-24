int pos_in_line;

void
pad_to_len(int n)
{
    while (pos_in_line++ <= n)
        cout << " ";
}

