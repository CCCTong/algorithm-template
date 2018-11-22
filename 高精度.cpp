#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string add(string a,string b)//只限两个非负整数相加
{
    string ans;
    const int L = 200;
    int numa[L] = {0},numb[L] = {0};
    int lena = a.size(),lenb = b.size();
    for(int i=0;i<lena;i++) {
        numa[lena-1-i] = a[i]-'0';
    }
    for(int i=0;i<lenb;i++) {
        numb[lenb-1-i] = b[i]-'0';
    }
    int len = lena > lenb ? lena : lenb;
    for(int i=0;i<len;i++) {
        numa[i] += numb[i];
        numa[i+1] += numa[i]/10;
        numa[i]%=10;
    }
    if(numa[len]) len++;
    for(int i=len-1;i>=0;i--)
        ans += numa[i]+'0';
    return ans;
}
string sub(string a,string b)//只限大的非负整数减小的非负整数
{
    string ans;
    const int len = 100005;
    int numa[len]={0},numb[len]={0};
    int lena=a.length(),lenb=b.length();
    for(int i=0;i<lena;i++) numa[lena-1-i]=a[i]-'0';
    for(int i=0;i<lenb;i++) numb[lenb-1-i]=b[i]-'0';
    int max_len= max(lena,lenb);
    for(int i=0;i<max_len;i++)
    {
        numa[i]-=numb[i];
        if(numa[i]<0) numa[i]+=10,numa[i+1]--;
    }
    while(!numa[--max_len]&&max_len>0);max_len++;
    for(int i=max_len-1;i>=0;i--) ans+=numa[i]+'0';
    return ans;
}
// n方
string mul(string a,string b)//高精度乘法a,b,均为非负整数
{
    string ans;
    const int L = 200;
    int numa[L],numb[L],numc[L],lena = a.size(),lenb = b.size();//na存储被乘数，nb存储乘数，nc存储积
    memset(numa, 0, sizeof(numa));
    memset(numb, 0, sizeof(numb));
    memset(numc, 0, sizeof(numc));
    for(int i = lena-1; i>=0; i--)
        numa[lena-i] = a[i] - '0';//将字符串表示的大整形数转成i整形数组表示的大整形数
    for(int i = lenb-1;i>=0;i--)
        numb[lenb-i] = b[i]-'0';
    for(int i=1;i<=lena;i++)
        for(int j=1;j<=lenb;j++)
            numc[i+j-1] += numa[i]*numb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）
    for(int i=1; i<=lena+lenb ;i++){
        numc[i+1]+=numc[i]/10;
        numc[i]%=10;//统一处理进位
    }
    if(numc[lena+lenb])
        ans += numc[lena+lenb] + '0';//判断第i+j位上的数字是不是0
    for(int i= lena + lenb - 1;i>=1;i--)
        ans += numc[i] + '0';//将整形数组转成字符串
    return ans;
}


// 高精度fft 乘法，nlogn
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define L(x) (1 << (x))
const double PI = acos(-1.0);
const int Maxn = 133015;
double ax[Maxn], ay[Maxn], bx[Maxn], by[Maxn];
char sa[Maxn/2],sb[Maxn/2];
int sum[Maxn];
int x1[Maxn],x2[Maxn];
int revv(int x, int bits)
{
    int ret = 0;
    for (int i = 0; i < bits; i++)
    {
        ret <<= 1;
        ret |= x & 1;
        x >>= 1;
    }
    return ret;
}
void fft(double * a, double * b, int n, bool rev)
{
    int bits = 0;
    while (1 << bits < n) ++bits;
    for (int i = 0; i < n; i++)
    {
        int j = revv(i, bits);
        if (i < j)
            swap(a[i], a[j]), swap(b[i], b[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        int half = len >> 1;
        double wmx = cos(2 * PI / len), wmy = sin(2 * PI / len);
        if (rev) wmy = -wmy;
        for (int i = 0; i < n; i += len)
        {
            double wx = 1, wy = 0;
            for (int j = 0; j < half; j++)
            {
                double cx = a[i + j], cy = b[i + j];
                double dx = a[i + j + half], dy = b[i + j + half];
                double ex = dx * wx - dy * wy, ey = dx * wy + dy * wx;
                a[i + j] = cx + ex, b[i + j] = cy + ey;
                a[i + j + half] = cx - ex, b[i + j + half] = cy - ey;
                double wnx = wx * wmx - wy * wmy, wny = wx * wmy + wy * wmx;
                wx = wnx, wy = wny;
            }
        }
    }
    if (rev)
    {
        for (int i = 0; i < n; i++)
            a[i] /= n, b[i] /= n;
    }
}
int solve(int a[],int na,int b[],int nb,int ans[])
{
    int len = max(na, nb), ln;
    for(ln=0; L(ln)<len; ++ln);
    len=L(++ln);
    for (int i = 0; i < len ; ++i)
    {
        if (i >= na) ax[i] = 0, ay[i] =0;
        else ax[i] = a[i], ay[i] = 0;
    }
    fft(ax, ay, len, 0);
    for (int i = 0; i < len; ++i)
    {
        if (i >= nb) bx[i] = 0, by[i] = 0;
        else bx[i] = b[i], by[i] = 0;
    }
    fft(bx, by, len, 0);
    for (int i = 0; i < len; ++i)
    {
        double cx = ax[i] * bx[i] - ay[i] * by[i];
        double cy = ax[i] * by[i] + ay[i] * bx[i];
        ax[i] = cx, ay[i] = cy;
    }
    fft(ax, ay, len, 1);
    for (int i = 0; i < len; ++i)
        ans[i] = (int)(ax[i] + 0.5);
    return len;
}
string mul(string sa,string sb)
{
    int l1,l2,l;
    int i;
    string ans;
    memset(sum, 0, sizeof(sum));
    l1 = sa.size();
    l2 = sb.size();
    for(i = 0; i < l1; i++)
        x1[i] = sa[l1 - i - 1]-'0';
    for(i = 0; i < l2; i++)
        x2[i] = sb[l2-i-1]-'0';
    l = solve(x1, l1, x2, l2, sum);
    for(i = 0; i<l || sum[i] >= 10; i++) // 进位
    {
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }
    l = i;
    while(sum[l] <= 0 && l>0)    l--; // 检索最高位
    for(i = l; i >= 0; i--)    ans+=sum[i] + '0'; // 倒序输出
    return ans;
}
const int L=100005;
int na[L];
string mul(string a,int b)//高精度a乘单精度b
{
    string ans;
    int La=a.size();
    fill(na,na+L,0);
    for(int i=La-1;i>=0;i--) na[La-i-1]=a[i]-'0';
    int w=0;
    for(int i=0;i<La;i++) na[i]=na[i]*b+w,w=na[i]/10,na[i]=na[i]%10;
    while(w) na[La++]=w%10,w/=10;
    La--;
    while(La>=0) ans+=na[La--]+'0';
    return ans;
}

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int L=110;
int sub(int *a,int *b,int La,int Lb)
{
    if(La<Lb) return -1;//如果a小于b，则返回-1
    if(La==Lb)
    {
        for(int i=La-1;i>=0;i--)
            if(a[i]>b[i]) break;
            else if(a[i]<b[i]) return -1;//如果a小于b，则返回-1

    }
    for(int i=0;i<La;i++)//高精度减法
    {
        a[i]-=b[i];
        if(a[i]<0) a[i]+=10,a[i+1]--;
    }
    for(int i=La-1;i>=0;i--)
        if(a[i]) return i+1;//返回差的位数
    return 0;//返回差的位数

}
string div(string n1,string n2,int nn)//n1,n2是字符串表示的被除数，除数,nn是选择返回商还是余数
{
    string s,v;//s存商,v存余数
    int a[L],b[L],r[L],La=n1.size(),Lb=n2.size(),i,tp=La;//a，b是整形数组表示被除数，除数，tp保存被除数的长度
    fill(a,a+L,0);fill(b,b+L,0);fill(r,r+L,0);//数组元素都置为0
    for(i=La-1;i>=0;i--) a[La-1-i]=n1[i]-'0';
    for(i=Lb-1;i>=0;i--) b[Lb-1-i]=n2[i]-'0';
    if(La<Lb || (La==Lb && n1<n2)) {
        //cout<<0<<endl;
        return n1;}//如果a<b,则商为0，余数为被除数
    int t=La-Lb;//除被数和除数的位数之差
    for(int i=La-1;i>=0;i--)//将除数扩大10^t倍
        if(i>=t) b[i]=b[i-t];
        else b[i]=0;
    Lb=La;
    for(int j=0;j<=t;j++)
    {
        int temp;
        while((temp=sub(a,b+j,La,Lb-j))>=0)//如果被除数比除数大继续减
        {
            La=temp;
            r[t-j]++;
        }
    }
    for(i=0;i<L-10;i++) r[i+1]+=r[i]/10,r[i]%=10;//统一处理进位
    while(!r[i]) i--;//将整形数组表示的商转化成字符串表示的
    while(i>=0) s+=r[i--]+'0';
    //cout<<s<<endl;
    i=tp;
    while(!a[i]) i--;//将整形数组表示的余数转化成字符串表示的</span>
    while(i>=0) v+=a[i--]+'0';
    if(v.empty()) v="0";
    //cout<<v<<endl;
    if(nn==1) return s;
    if(nn==2) return v;
}
#include<iostream>
#include<algorithm>
using namespace std;
string div(string a,int b)//高精度a除以单精度b
{
    string r,ans;
    int d=0;
    if(a=="0") return a;//特判
    for(int i=0;i<a.size();i++)
    {
        r+=(d*10+a[i]-'0')/b+'0';//求出商
        d=(d*10+(a[i]-'0'))%b;//求出余数
    }
    int p=0;
    for(int i=0;i<r.size();i++)
        if(r[i]!='0') {p=i;break;}
    return r.substr(p);
}
int main()
{
    string a;
    int b;
    while(cin>>a>>b)
    {
        cout<<div(a,b)<<endl;
    }
    return 0;
}



int main()
{
    string a,b;
    while(cin>>a>>b) cout<<add(a,b)<<endl;
    return 0;
}


