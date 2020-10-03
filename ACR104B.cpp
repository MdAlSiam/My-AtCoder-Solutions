/// In the name of Allah SWT

using namespace std;
#include <bits/stdc++.h>

#define ll long long int
#define dd double

#define scl(x) scanf("%lld", &x)
#define scll(x, y) scanf("%lld %lld", &x, &y)
#define scd(x) scanf("%lf", &x)
#define scdd(x, y) scanf("%lf %lf", &x, &y)

#define prl(x) printf("%lld\n", x)
#define prll(x, y) printf("%lld %lld\n", x, y)
#define prYes printf("YES\n")
#define prNo printf("NO\n")
#define aNewLine printf("\n")

#define ON(n, i) (n|(1LL<<i))
#define OFF(n, i) (n&(~(1LL<<i)))
#define CHK(n, i) (n&(1LL<<i))

#define For(i, x, y) for(ll i = x; i < y; i++)
#define Mem(ara, x) memset(ara, x, sizeof(ara))

#define pb push_back
#define pll pair<ll, ll >
#define ff first
#define ss second

#define maxn 200005 ///2x10^5 + 5
//#define maxn 1000006 ///10^6 + 6
//#define maxn 1000000009 ///10^9 + 9

#define pi acos(-1.00)
#define eps 0.0000000001 ///10^-10
#define inf LONG_LONG_MAX
#define mod 1000000007 ///10^9+7

ll t, test, temp;
ll n, m, k, kount;
ll a, b, c, ans, u, v;
ll x, y, z = -1, maxi, mini;
string str;

void solve() {
    cin >> n >> str;
    str = "#" + str;
    n++;
    ll grid[4][n+10];

    For (i, 0, n) {
        if (str[i] == 'T') str[i] = 'B';
        if (str[i] == 'G') str[i] = 'D';
    }

    For (j, 0, n) {
        For (i, 0, 4) {
            if (j == 0) {
                grid[i][j] = 0;
                continue;
            }

            grid[i][j] = grid[i][j-1] + (ll)((str[j] - 'A') == i);
        }
    }

    ans = 0;

    For (len, 2, n+1) {
        for (ll j = 1; j+len-1 < n; j++) {
            ll aKount = grid[0][j+len-1] - grid[0][j-1];
            ll bKount = grid[1][j+len-1] - grid[1][j-1];
            ll cKount = grid[2][j+len-1] - grid[2][j-1];
            ll dKount = grid[3][j+len-1] - grid[3][j-1];

            if (aKount == bKount and cKount == dKount) {
//                for (ll k = j; k <= j+len-1; k++) printf("%c", str[k]);
//                printf(" : %lld %lld %lld %lld \n", aKount, bKount, cKount, dKount);
                ans++;
            }
        }
    }

    prl(ans);
}

int main() {
    test = 1;
    //while (scl(test) == 1)
    while (test--) solve();
}
