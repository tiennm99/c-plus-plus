#ifndef DSTT_H_INCLUDED
#define DSTT_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

class ma_tran
{
public:
    int hang, cot;
    double **phan_tu;

    ma_tran()
    {
        this->hang = 0;
        this->cot = 0;
        this->phan_tu = NULL;
    }

    ma_tran(int m, int n)
    {
        this->hang = m;
        this->cot = n;
        phan_tu = new double*[this->hang];
        for (int i = 0; i < this->hang; i++)
        {
            phan_tu[i] = new double[this->cot];
        }
    }

    friend istream &operator >> (istream &input, ma_tran &m)
    {
        m.huy();
        input >> m.hang >> m.cot;
        m.phan_tu = new double* [m.hang];
        for (int i = 0; i < m.hang; i++)
        {
            m.phan_tu[i] = new double[m.cot];
        }
        for (int i = 0; i < m.hang; i++)
        {
            for (int j = 0; j < m.cot; j++)
            {
                input >> m.phan_tu[i][j];
            }
        }
        return input;
    }

    friend ostream &operator << (ostream &output, ma_tran &m)
    {
        for (int i = 0; i < m.hang; i++)
        {
            for (int j = 0; j < m.cot; j++)
            {
                output << setw(5) << m.phan_tu[i][j];
            }
            output << endl;
        }
        return output;
    }

    bool operator == (const ma_tran &m)
    {
        if (this->hang != m.hang || this->cot != m.cot)
        {
            return 0;
        }
        else
        {
            for (int i = 0; i < this->hang; i++)
            {
                for (int j = 0; j < this-> cot; j++)
                {
                    if (this->phan_tu[i][j] != m.phan_tu[i][j])
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    ma_tran operator + (const ma_tran &m)
    {
        ma_tran mt(this->hang, this->cot);
        if (this->hang == m.hang && this->cot == m.cot)
        {
            for (int i = 0; i < mt.hang; i++)
            {
                for (int j = 0; j < mt.cot; j++)
                {
                    mt.phan_tu[i][j] = this->phan_tu[i][j] + m.phan_tu[i][j];
                }
            }
        }
        else
        {
            mt.huy();
        }
        return mt;
    }

    ma_tran operator - (const ma_tran &m)
    {
        ma_tran mt(this->hang, this->cot);
        if (this->hang == m.hang && this->cot == m.cot)
        {
            for (int i = 0; i < mt.hang; i++)
            {
                for (int j = 0; j < mt.cot; j++)
                {
                    mt.phan_tu[i][j] = this->phan_tu[i][j] - m.phan_tu[i][j];
                }
            }
        }
        else
        {
            mt.huy();
        }
        return mt;
    }

    ma_tran operator * (const ma_tran &m)
    {
        ma_tran mt(this->hang, m.cot);
        if (this->cot == m.hang)
        {
            for (int i = 0; i < mt.hang; i++)
            {
                for (int j = 0; j < mt.cot; j++)
                {
                    mt.phan_tu[i][j] = 0;
                    for (int k = 0; k < this->cot; k++)
                    {
                        mt.phan_tu[i][j] += this->phan_tu[i][k] * m.phan_tu[k][j];
                    }
                }
            }
        }
        else
        {
            mt.huy();
        }
        return mt;
    }

    ma_tran duong_cheo_chinh()
    {
        ma_tran m(this->hang, this->cot);
        for (int i = 0; i < this->hang; i++)
        {
            for (int j = 0; j < this->cot; j++)
            {
                if (i == j)
                {
                    m.phan_tu[i][j] = this->phan_tu[i][j];
                }
                else
                {
                    m.phan_tu[i][j] = 0;
                }
            }
        }
        return m;
    }

    ma_tran tam_giac_tren()
    {
        ma_tran m(this->hang, this->cot);
        for (int i = 0; i < this->hang; i++)
        {
            for (int j = 0; j < this->cot; j++)
            {
                if (i <= j)
                {
                    m.phan_tu[i][j] = this->phan_tu[i][j];
                }
                else
                {
                    m.phan_tu[i][j] = 0;
                }
            }
        }
        return m;
    }

    ma_tran tam_giac_duoi()
    {
        ma_tran m(this->hang, this->cot);
        for (int i = 0; i < this->hang; i++)
        {
            for (int j = 0; j < this->cot; j++)
            {
                if (i >= j)
                {
                    m.phan_tu[i][j] = this->phan_tu[i][j];
                }
                else
                {
                    m.phan_tu[i][j] = 0;
                }
            }
        }
        return m;
    }

    ma_tran don_vi()
    {
        ma_tran m(this->hang, this->cot);
        for (int i = 0; i < this->hang; i++)
        {
            for (int j = 0; j < this->cot; j++)
            {
                if (i == j)
                {
                    m.phan_tu[i][j] = 1;
                }
                else
                {
                    m.phan_tu[i][j] = 0;
                }
            }
        }
        return m;
    }

    ma_tran chuyen_vi()
    {
        ma_tran m(this->cot, this->hang);
        for (int i = 0; i < this->hang; i++)
        {
            for (int j = 0; j < this->cot; j++)
            {
                m.phan_tu[j][i] = this->phan_tu[i][j];
            }
        }
        return m;
    }

    bool la_ma_tran_vuong()
    {
        if (this->hang == this->cot)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool la_ma_tran_bac_thang()
    {
        int phan_tu_co_so = -1;
        for (int i = 0; i < this->hang; i++)
        {
            int j = 0;
            while (this->phan_tu[i][j] == 0)
            {
                j++;
            }
            if (j <= phan_tu_co_so && j != this->cot)
            {
                return 0;
            }
            else
            {
                phan_tu_co_so = j;
            }
        }
        return 1;
    }

    bool la_ma_tran_doi_xung()
    {
        ma_tran m(this->hang, this->cot);
        for (int i = 0; i < m.hang; i++)
        {
            for (int j = 0; j < m.cot; j++)
            {
                m.phan_tu[i][j] = this->phan_tu[i][j];
            }
        }
        if (m == this->chuyen_vi())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool la_ma_tran_phan_doi_xung()
    {
        ma_tran m(this->hang, this->cot);
        for (int i = 0; i < m.hang; i++)
        {
            for (int j = 0; j < m.cot; j++)
            {
                m.phan_tu[i][j] = -this->phan_tu[i][j];
            }
        }
        if (m == this->chuyen_vi())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    double vet()
    {
        if (this->la_ma_tran_vuong())
        {
            double v = 0;
            for (int i = 0; i < this->hang; i++)
            {
                v += this->phan_tu[i][i];
            }
            return v;
        }
        else
        {
            return 0;
        }
    }

    void hang_x_nhan_y(int x, double y)
    {
        if (x >= 1 && x <= this->hang)
        {
            for (int j = 0; j < this->cot; j++)
            {
                this->phan_tu[x - 1][j] *= y;
            }
        }
    }

    void hang_x_cong_y_lan_hang_z(int x, double y, int z)
    {
        if (x >= 1 && x <= this->hang && z >= 1 && z <= this->hang)
        {
            for (int j = 0; j < this->cot; j++)
            {
                this->phan_tu[x - 1][j] += y*this->phan_tu[z - 1][j];
            }
        }
    }

    void doi_cho_2_hang(int x, int y)
    {
        if (x >= 1 && x <= this->hang && y >= 1 && y <= this->hang)
        {
            for (int j = 0; j < this->cot; j++)
            {
                int t = this->phan_tu[x - 1][j];
                this->phan_tu[x - 1][j] = this->phan_tu[y - 1][j];
                this->phan_tu[y - 1][j] = t;
            }
        }
    }

    void cot_x_nhan_y(int x, double y)
    {
        if (x >= 1 && x <= this->cot)
        {
            for (int i = 0; i < this->hang; i++)
            {
                this->phan_tu[i][x - 1] *= y;
            }
        }
    }

    void cot_x_cong_y_lan_cot_z(int x, double y, int z)
    {
        if (x >= 1 && x <= this->cot && z >= 1 && z <= this->cot)
        {
            for (int i = 0; i < this->hang; i++)
            {
                this->phan_tu[i][x - 1] += y*this->phan_tu[i][z - 1];
            }
        }
    }

    void doi_cho_2_cot(int x, int y)
    {
        if (x >= 1 && x <= this->cot && y >= 1 && y <= this->cot)
        {
            for (int i = 0; i < this->hang; i++)
            {
                int t = this->phan_tu[i][x - 1];
                this->phan_tu[i][x - 1] = this->phan_tu[i][y - 1];
                this->phan_tu[i][y - 1] = t;
            }
        }
    }

    ma_tran bac_thang()
    {
        ma_tran m(this->hang, this->cot);
        for (int i = 0; i < m.hang; i++)
        {
            for (int j = 0; j < m.cot; j++)
            {
                m.phan_tu[i][j] = this->phan_tu[i][j];
            }
        }
        int k = 0;
        while (k < m.hang)
        {
            if (m.phan_tu[k][k] == 0)
            {
                for (int i = 0; i < this->hang; i++)
                {
                    if (m.phan_tu[i][k] != 0)
                    {
                        m.doi_cho_2_hang(k, i);
                        break;
                    }
                }
            }
            for (int i = k + 1; i < m.hang; i++)
            {
                for (int j = k + 1; j < m.cot; j++)
                {
                    m.phan_tu[i][j] = m.phan_tu[i][j]*m.phan_tu[k][k] - m.phan_tu[i][k]*m.phan_tu[k][j];
                }
                m.phan_tu[i][k] = 0;
            }
            k++;
        }
        return m;
    }

    void huy()
    {
        if (phan_tu != NULL)
        {
            for (int i = 0; i < this->hang; i++)
            {
                if (phan_tu[i] != NULL)
                {
                    delete[] phan_tu[i];
                    phan_tu[i] = NULL;
                }
            }
            delete[] phan_tu;
            phan_tu = NULL;
        }
    }

    ~ma_tran(){}
};

#endif // DSTT_H_INCLUDED
