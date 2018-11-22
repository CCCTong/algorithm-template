LL cal_mod(LL x,LL y,LL p)// x * y % p
{
    long long ret = 0;
    while (y) {
        if(y & 1)ret = (ret + x) % p;
        x = (x + x) % p;
        y >>= 1;
    }
    return ret;
}

