LL inv[maxn];
void init(int n){
    inv[1] = 1;
    for(int i = 2; i <=n; i ++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
/*
 数值分析牛顿迭代法编程作业，2017100102020，褚童。
 */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-8; // eps 用于控制迭代精度
// x^2-3*x+2-e^x = 0; diff : x*2-3-e^x = 0;
// x^3+2*x^2+10*x-20 = 0; diff : 3*x+4*x+10 = 0;
// 以上为题目中所给出的方程
// 一下带下标1为方程1，2代表对方程式2操作。
double diff1(double x){
    return x*2-3-exp(x); // 计算1式的导数
}
double f1(double x){
    return x*x-3*x+2-exp(x); // 计算1式的函数值
}
double diff2(double x){
    return 3*x+4*x+10;   // 计算2式的导数
}
double f2(double x){
    return x*x*x + 2*x*x + 10*x - 20; // 计算2式的函数值
}
void NewTon(double & x,int tag,int tims){
    // 牛顿迭代法，针对题目修改公式，计算导数
    // x 为当前迭代到的点，tag标记对1还是2函数求0点，tims控制迭代次数
    int flag = 0; // 标记是否找到方程的近似根
    for (int i=1; i<=tims; i++) {
        double y = tag == 1 ? f1(x) : f2(x);
        double k = tag == 1 ? diff1(x) : diff2(x);
        if (abs(x-y/k-x) < eps) { flag = 1; break;}
        x = x - y/k; // 更新 迭代 x 为新的点
        cout << "the x is " << x << endl; // 输出一下迭代过程
    }
    if (flag) cout << "the answer is " << x << endl;
    else cout << "the answer not be found!" << endl;
}
int main(){
    double init_x = 3; // 自己设置一个初始点方便测试，也可改成cin读入初始点。
    NewTon(init_x, 1, 100);
    double ans1 = init_x*init_x-3*init_x+2-exp(init_x);//将结果带入方程
    if (ans1 < eps) cout << "good answer !" << endl;
    else cout << "bad answer !" << endl;  // 测试是不是方程的根
    return 0;
}
