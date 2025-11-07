#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int lenNum(int num)
{
    int i = 0;
    num = abs(num);
    if (num > 0)
    {
        for(i;num > 0;i++) num /= 10;
    }
    else i++;
    return i;
}

char *splitNumber(int num,char num1[])
{
    char chars[100] {};
    int i = 0;
    while(num > 0)
    {
        chars[i] = (char)((int)'0' + num%10);
        num /= 10;
        i++;
    }
    for(int i1 = 0;i1 < i;i1++)
    {
        num1[i1] = chars[i-i1-1];
    }
    num1[i] = '\0';
    return num1;
}

void encoder(int seed,char str[])
{
    char alf[] {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
    int cod[62] {};
    for(int c = 0; c < 62; c++)
    {
        seed = seed = (106*seed+1283)%6075;
        for(int c1 : cod)
        {
            if(c1 == 0) break;
            while(max(c1,seed) / (int)pow(10,abs(lenNum(c1)-lenNum(seed))) == min(c1,seed))
            {
                seed = seed = (106*seed+1283)%6075;
            }
        }
        cod[c] = seed;
    }
    char code[100] {};
    int t = 0;
    for(int i = 0;str[i] != '\0';i++)
    {
        for(int k = 0; k < 62;k++)
        {
            if(alf[k] == str[i])
            {
                int lencod = lenNum(cod[k]);
                char codnum[const int(lencod+1)] {};
                char *codnum1 = splitNumber(cod[k],codnum);
                int p = 0;
                for(p;p < lencod;p++)
                {
                    code[t] = *(codnum1 + p);
                    t++;
                }
                break;
            }
            if (k == 61)
            {
                code[t] = str[i];
                t++;
            }
            
        }
    }
    cout << code << endl;
}

void decoder(int seed,char str[])
{
    char alf[] {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
    int cod[62] {};
    for(int c = 0; c < 62; c++)
    {
        seed = seed = (106*seed+1283)%6075;
        for(int c1 : cod)
        {
            if(c1 == 0) break;
            while(max(c1,seed) / (int)pow(10,abs(lenNum(c1)-lenNum(seed))) == min(c1,seed))
            {
                seed = seed = (106*seed+1283)%6075;
            }
        }
        cod[c] = seed;
    }
    char decod[100] {};
    int l;
    int m = 0;
    int t = 0;
    for(int i = 0; str[i] != '\0';i++)
    {
        if (find(begin(alf),end(alf),str[i]) != end(alf))
        {
            l = int(str[i] - '0');
            m = m*10 + l;
            for(int y = 0;y < 62;y++)
            {
                if (cod[y] == m)
                {
                    decod[t] = alf[y];
                    m = 0;
                    t++;
                    break;
                }
            }
        }
        else
        {
            decod[t] = str[i];
            m = 0;
            t++;
        }
        

    }
    cout << decod << endl;
}
