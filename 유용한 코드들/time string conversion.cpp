inline int time_to_int(string t) {
	int res = 0;
	res += (t[0]-'0') * 36000;
	res += (t[1] - '0') * 3600;

	res += (t[3] - '0') * 600;
	res += (t[4] - '0') * 60;

	res += (t[6] - '0') * 10;
	res += (t[7] - '0');
	return res;
}
inline string int_to_time(int t) {
	char tmp[9];
	sprintf(tmp, "%02d:%02d:%02d", t / 3600, t / 60 % 60, t % 60);
	return string(tmp);
}