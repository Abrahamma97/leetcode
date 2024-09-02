int lengthOfLongestSubstring(char* s) {
	int l = 0, r = 0, lenmax = 0;
	int arr[128] = {0};

	while(s[r] != '\0') {
		arr[s[r]]++;
		while(arr[s[r]] > 1) {
			arr[s[l]]--;
			l++;
		}
		lenmax = lenmax > (r-l+1)?lenmax:(r-l+1);
		r++;
	}
	return lenmax;
}
