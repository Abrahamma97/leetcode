int countSubstrings(char* s) {
    int i, start, end, lenmax = 0, pos1 = 0, pos2 = 0, len = 0, count = 0;
    for(i = 0; s[i] != '\0'; i++) {
        start = i;
        end = i;
        while(start >= 0 && s[end] != '\0' && (s[start] == s[end]) ) {
            start--;
            end++;
            count++;
        }
        start = i;
        end = i+1;
        while(start >= 0 && s[end] != '\0' && (s[start] == s[end]) ) {
            start--;
            end++;
            count++;
        }
        
    }
    
    return count;
}

