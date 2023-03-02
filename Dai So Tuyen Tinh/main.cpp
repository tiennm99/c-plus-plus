#include "DSTT.h"

int main()
{
    fstream f;
    f.open("ma_tran.txt");
    ma_tran mt;
    f >> mt;
    ma_tran m = mt.bac_thang();
    cout << mt << endl;
    cout << m << endl;
    return 0;
}
