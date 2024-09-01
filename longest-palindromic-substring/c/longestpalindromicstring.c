char* longestPalindrome(char* s) {
    int i, start, end, lenmax = 0, pos1 = 0, pos2 = 0, len = 0;
    for(i = 0; s[i] != '\0'; i++) {
        start = i;
        end = i;
        while(start >= 0 && s[end] != '\0' && (s[start] == s[end]) ) {
            start--;
            end++;
        }
        start++;
        end--;
        len = end - start + 1;
        if(len > lenmax) {
            lenmax = len;
            pos1 = start;
            pos2 = end;
        }
        start = i;
        end = i+1;
        while(start >= 0 && s[end] != '\0' && (s[start] == s[end]) ) {
            start--;
            end++;
        }
        start++;
        end--;
        len = end - start + 1;
        if(len > lenmax) {
            lenmax = len;
            pos1 = start;
            pos2 = end;
        }

        printf("%d\n", i);
    }
    s[pos2+1] = '\0';
    return &(s[pos1]);
}
