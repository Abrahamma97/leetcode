int max(int a, int b) {
	return a>b?a:b;
}
int characterReplacement(char* s, int k) {
	int len = strlen(s);
	int r = 0, l = 0, freqmax = 0;
	int arr[128] = {0};
	while(r != len) {
		arr[s[r]]++;

		freqmax  = max(freqmax, arr[s[r]]);

		if((r - l - freqmax + 1) > k) {
			arr[s[l]]--;
			l++;
		}
		r++;

	}
	return r-l;

}
