#include<cmath>

int lenNum(int num)
{
    int i = 0;
    num = abs(num);
    if (num != 0)
    {
        for(;num != 0;i++) num /= 10;
    }
    else i++;
    return i;
}

char *resize(const char *str, unsigned size, unsigned new_size)
{
	char *new_str = new char[new_size] {};
    for(int i = 0; i < size && i < new_size;i++)
    {
        new_str[i] = str[i];
    }
    delete [] str;
    return new_str;
}

char *splitNumber(int num)
{
    int lnum = lenNum(num);
    char *figures = new char[lnum+1] {} ;
    for(--lnum;lnum != -1;--lnum)
    {
        figures[lnum] = (char)((int)'0' + num%10);
        num /= 10;
    }
    return figures;
}

char *encoder(int seed,char str[])
{
    char alf[96] {};
    for(int i = 32;i < 127;i++) alf[i-32] = (char)i;
    int cod[95] {};
    for(int c = 0; c < 95; c++)
    {
        seed = (106*seed+1283)%6075;
        for(int c1 = 0;c1<95;c1++)
        {
            if(cod[c1] == 0) break;
            while(max(cod[c1],seed) / (int)pow(10,abs(lenNum(cod[c1])-lenNum(seed))) == min(cod[c1],seed))
            {
                seed = (106*seed+1283)%6075;
            }
        }
        cod[c] = seed;
    }
    char *code = new char[100] {};
    int t = 0;
    int len_m = 100;
    for(int i = 0;str[i] != '\0';i++)
    {
        if(len_m - t <= 20)
        {
            code = resize(code,len_m,len_m+100);
            len_m += 100;
        }
        if((str[i] > (char)31) && (str[i] < (char)127))
        {
            int key = cod[(int)str[i] - 32];
            char *m_figure = splitNumber(key);
            for(int r = 0;m_figure[r] != '\0';r++)
            {
                code[t] = m_figure[r];
                t++;
            }
            delete [] m_figure;
            m_figure = nullptr;
        }
        else
        {
            code[t] = str[i];
            t++;
        }
    }
    return code;
}

char *decoder(int seed,char str[])
{
    char alf[96] {};
    for(int i = 32;i < 127;i++) alf[i-32] = (char)i;
    int cod[95] {};
    for(int c = 0; c < 95; c++)
    {
        seed = (106*seed+1283)%6075;
        for(int c1 = 0;c1<95;c1++)
        {
            if(cod[c1] == 0) break;
            while(max(cod[c1],seed) / (int)pow(10,abs(lenNum(cod[c1])-lenNum(seed))) == min(cod[c1],seed))
            {
                seed = (106*seed+1283)%6075;
            }
        }
        cod[c] = seed;
    }
    char *decod = new char[100] {};
    int figure;
    int number = 0;
    int t = 0;
    int len_m = 100;
    for(int i = 0; str[i] != '\0';i++)
    {
        if(len_m - t <= 20)
        {
            decod = resize(decod,len_m,len_m+100);
            len_m += 100;
        }
        if ((str[i] > (char)47) && (str[i] < (char)58))
        {
            figure = int(str[i] - '0');
            number = number*10 + figure;
            for(int y = 0;y < 95;y++)
            {
                if (cod[y] == number)
                {
                    decod[t] = alf[y];
                    number = 0;
                    t++;
                    break;
                }
            }
        }
        else
        {
            decod[t] = str[i];
            number = 0;
            t++;
        }
        

    }
    return decod;
}
