#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

typedef __int128 i128;

namespace miller_rabin {
	ll mul(ll x, ll y, ll mod) { return (i128)x * y % mod; }
	ll _pow(ll x, ll y, ll p) {
		ll ret = 1, piv = x % p;
		while (y) {
			if (y & 1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;

	}
	bool miller_rabin(ll x, ll a) {
		if (x % a == 0) return 0;
		ll d = x - 1;
		while (1) {
			ll tmp = _pow(a, d, x);
			if (d & 1) return (tmp != 1 && tmp != x - 1);
			else if (tmp == x - 1) return 0;
			d >>= 1;
		}
	}
	bool isprime(ll x) {
		for (auto& i : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
			if (x == i) return 1;
			if (x > 40 && miller_rabin(x, i)) return 0;
		}
		if (x <= 40) return 0;
		return 1;
	}
}



void solve(ll n, vector<ll> &res) {
	if (n == 1) return;
	if (n % 2 == 0) {
		res.push_back(2);
		solve(n / 2, res);
		return;
	}
	if (miller_rabin::isprime(n)) {
		res.push_back(n);
		return;
	}
	ll a, b, c, g = n;
	auto f = [&](ll x) {
		return (c + miller_rabin::mul(x, x, n)) % n;
	};
	do {
		if (g == n) {
			a = b = rand() % (n - 2) + 2;
			c = rand() % 20 + 1;
		}
		a = f(a);
		b = f(f(b));
		g = gcd(abs(a - b), n);
	} while (g == 1);
	solve(g, res);
	solve(n / g, res);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector <ll> res;
	ll n;
	cin >> n;

	
}