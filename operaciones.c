
int suma(int a,int b,int res)
{

    res=a+b;

    return res;

}

int resta(int a,int b,int res)
{

    res=a-b;

    return res;

}

int multiplica(int a,int b,int res)
{

    res=a*b;

    return res;

}


float division(int a,int b, float res)
{

    res=(float)a/b;

    return res;

}

int facto(int a, int res)
{

    res=1;
    while(a>0)
    {
        res*=a;
        a--;
    }

    return res;

}
