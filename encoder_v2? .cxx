#include<cmath>
#include<cstring>
using namespace std;

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

char *getKey(int seed,char c)
{
    int t = -1;
    for(;t != (int)c;t++)
    {
        seed = (106*seed+1283)%6075;
        while (!((seed > 999) && (seed < 10000)))
        {
            seed = (106*seed+1283)%6075;
        }
    } 
    return splitNumber(seed);
}

char getChar(int seed,char *str)
{
    const int lenKey = 4;
    int key = 0;
    char c;
    for(int i = 0;i != lenKey;i++)
    {
        key += int(str[i] - '0')*pow(10,lenKey-1-i);
    }
    for(int i = 0;i != 128;i++)
    {
        seed = (106*seed+1283)%6075;
        while (!((seed > 999) && (seed < 10000)))
        {
            seed = (106*seed+1283)%6075;
        }
        if(seed == key)
        {
            c = (char)i;
            break;
        }
    }
    return c;
}

char *encoder(int seed,char str[])
{
    const int lenKey = 4;
    char *code = new char[strlen(str)*lenKey + 1] {};
    for(int i = 0;str[i] != '\0';i++)
    {
        char *m_figure = getKey(seed,str[i]);
        for(int k = 0;k != lenKey;k++)
        {
            code[i*lenKey + k] = m_figure[k];
        }
        delete [] m_figure;
    }
    return code;
}

char *decoder(int seed,char *str)
{
    const int lenKey = 4;
    char *decod = new char[strlen(str)/lenKey + 1] {};
    for(int i = 0;*(str + i) != '\0'; i += lenKey)
    {
        decod[i/lenKey] = getChar(seed,str+i);
    }
    return decod;
}

