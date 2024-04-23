#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[] = {9, 0, 12, 13};
    int y[] = {3, 2, 7, 5};
    int m = 3, n = 12, p, q, r, s;
    
    m = n--;
    m++;
    n = x[3] / y[x[1]];
    p = x[n - 2];
    q = y[0] / 3 + 5 * x[3];
    r = m = 3;
    s = (r== 2);
    
    printf("%d %d %d %d %d %d %d\n", m, n, p, q, r, s, x[2]);
    
    return 0;
}
