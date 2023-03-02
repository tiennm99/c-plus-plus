#include <stdio.h>
#include <assert.h>
void DrawSpiralLine(const int n, const int line)
{
    // Throw an assertion when faulty parameters are supplied.
    assert(line >= 0 && line < n && n > 0);
    const int square = n * n;
    int       i      = 0;
    // Simple case: The first line of a spiral.
    if (line == 0)
    {
        for (i = 0; i < n; i++)
        {
            printf("%02d ", (square - 1) - i);
        }
    }
    // Simple case: The last line of a spiral.
    else if (line == (n - 1))
    {
        for (i = 0; i < n; i++)
        {
            printf("%02d ", square - (3 * n) + 2 + i);
        }
    }
    // Complex case: Line with other inner spirals.
    else
    {
        // Print the first character.
        printf("%02d ", square - (4 * n) + 4 + (line - 1));
        // Print a line of the rest
        DrawSpiralLine(n - 2, line - 1);
        // Print the last character
        printf("%02d ", (square - 1) - n - (line - 1));
    }
}
void DrawSpiral(const int n)
{
    int i = 0;
    // Draw the lines of the spiral.
    for (i = 0; i < n; i++)
    {
        DrawSpiralLine(n, i);
        printf("\n");
    }
}
int main(void)
{
    DrawSpiral(5);
    printf("\n");
    DrawSpiralLine(6, 2);
    return 0;
}
