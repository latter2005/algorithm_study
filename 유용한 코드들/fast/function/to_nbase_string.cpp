string to_nbase_string(int x, int n){
	static char c[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	string A = "";               
	while (x / n != 0) {
		int a = 0;
		a = x % n;
		A = c[a] + A;          
		x = x / n;
	}

	A = c[x%n] + A;

	return A;
}
