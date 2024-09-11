bool isPalindrome(char* s) {
    char ch[2000000];
    int  i = 0, l = 0;
    while(s[i] != '\0') {
        if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            ch[l] = s[i] | ' ';
            l++;
        }
        i++;
       
    }
    ch[l] = '\0';
    i = 0;
    l = l-1;
    while( i <= l) {
        if(ch[i] != ch[l]) {
            return false;
        }
        i++;
        l--;
    }
    return true;
}
