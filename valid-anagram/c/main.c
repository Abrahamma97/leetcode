bool isAnagram(char* s, char* t) {
    int len1 = strlen(s), len2 = strlen(t);
    if(len1 != len2) {
        return false;
    }
    int chs[128] = {0};
    int cht[128] = {0};
    int i = 0;
    while(s[i] != '\0') {
        chs[s[i]]++;
        cht[t[i]]++;
        i++;
    }
    if(memcmp(chs, cht, sizeof(chs)) == 0) {
        return true;
    } else {
        return false;
    }
    
}
