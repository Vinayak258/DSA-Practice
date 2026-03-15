#include <bits/stdc++.h>
using namespace std;

class Fancy
{
private:
    const long long MOD = 1000000007;

    vector<long long> seq;
    long long mul = 1;
    long long add = 0;

    long long modPow(long long a, long long b)
    {
        long long res = 1;
        a %= MOD;

        while (b > 0)
        {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    long long modInv(long long x)
    {
        return modPow(x, MOD - 2);
    }

public:
    Fancy() {}

    void append(int val)
    {
        long long stored =
            ((val - add + MOD) % MOD * modInv(mul)) % MOD;

        seq.push_back(stored);
    }

    void addAll(int inc)
    {
        add = (add + inc) % MOD;
    }

    void multAll(int m)
    {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx)
    {
        if (idx >= seq.size())
            return -1;

        return (seq[idx] * mul + add) % MOD;
    }
};

int main()
{

    Fancy fancy;

    fancy.append(2);
    fancy.addAll(3);
    fancy.append(7);
    fancy.multAll(2);

    cout << fancy.getIndex(0) << endl;

    fancy.addAll(3);
    fancy.append(10);
    fancy.multAll(2);

    cout << fancy.getIndex(0) << endl;
    cout << fancy.getIndex(1) << endl;
    cout << fancy.getIndex(2) << endl;

    return 0;
}