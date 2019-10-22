int brute_force_search(char *text, int text_len, char *pattern, int pat_len){
    int i, j;
    i = 0; j = 0;
    while(i < text_len && j<pat_len){
        if(text[i] == pattern[j]){
            i++; j++;
        }else{
            i = i-j+1; j = 0;
        }
    }
    return (j == pat_len) ? (i-j):-1;
}

#define uchar unsigned char
#define max(a,b) ((a)>(b) ? a:b)

int bm_search(uchar *text, int text_len, uchar *pattern, int pat_len){
    int skip[256];
    int i,j;
    for(i = 0; i<256; i++)
        skip[i] = pat_len;
    for(i = 0; i<pat_len - 1; i++)
        skip[pattern[i]] = pat_len - i - 1;
    i = pat_len -1;
    while(i < text_len){
        j = pat_len - 1;
        while(text[i] == pattern[j]){
            if(j == 0)
                return i;
            i--; j--;
        }
        i = i + max(skip[text[i]], pat_len-1);
    } 
    return -1;
}