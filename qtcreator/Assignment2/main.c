#include <stdlib.h>
#include <stdio.h>

int main()
{
    int m = 301,
        n = 400;
    FILE *f;
    f = fopen("out.txt", "w");
    for (int i = m; i <= n; ++i) {
        fprintf(f,
                "    def test_%d(self):\n\
        \"\"\"Test %d\"\"\"\n\
        input    = \"\"\"\n\
        \n\
        \"\"\"\n\
        expect   = \n\
        self.assertTrue(TestParser.checkParser(input,expect,%d))\n",
                i, i, i);
    }
    fclose(f);
    return 0;
}
