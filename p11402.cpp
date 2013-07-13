#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

double
lg(double x)
{
    return log(x) / log(2.0);
}

void
init_seg_tree(int n, vector<int>& tree)
{
    int len = (int)(2 * pow(2.0, floor(lg((double) n) + 1)));
    tree.resize(len, 0);
}

void
build_seg_tree(vector<int>& tree, int A[], int node, size_t a, size_t b)
{
    if (a == b) {
        tree[node] = A[a];
    } else {
        size_t l_child = 2 * node, r_child = 2 * node + 1;
        size_t mid = (a&b) + ((a^b) >> 1);
        build_seg_tree(tree, A, l_child, a, mid);
        build_seg_tree(tree, A, r_child, mid + 1, b);

        tree[node] = tree[l_child] + tree[r_child];
    }
}

int
query_seg_tree(vector<int>& tree, int node, int a, int b, int i, int j)
{
    if (i > a || j < b)
        return -1;
    if (a >= i && b <= j)
        return tree[node];

    size_t l_child = 2 * node, r_child = 2 * node + 1;
    size_t mid = (a&b) + ((a^b) >> 1);
    int p1 = query_seg_tree(tree, l_child, a, mid, i, j);
    int p2 = query_seg_tree(tree, r_child, mid + 1, b, i, j);

    if (p1 == -1)
        return p2;
    if (p2 == -1)
        return p1;

    return p1 + p2;
}

void
update_seg_tree(vector<int>& tree, int oldval, int newval,
                int node, int a, int b, int i)
{
    if (a == b)
        tree[node] = newval;
    else {
        size_t l_child = 2 * node, r_child = 2 * node + 1;
        size_t mid = (a&b) + ((a^b) >> 1);
        tree[node] = tree[node] - oldval + newval;

        if (a <= i && i <= mid) {
            update_seg_tree(tree, oldval, newval, l_child, a, mid, i);
        } else {
            update_seg_tree(tree, oldval, newval, r_child, mid + 1, b, i);
        }
    }
}

int caseno, T;

int
main()
{
    vector<int> seg;
    printf("%d", &T);

    for (caseno = 1; caseno <= T; casneo++) {

    }

    return 0;
}
