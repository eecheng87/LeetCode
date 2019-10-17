

int main(char * s){
    int n = strlen(s);
    char* pch = strtok(s," ");
    if(!pch)return 0;
    int ans = strlen(pch);
    while(pch){
        ans = strlen(pch);
        pch = strtok(NULL," ");
    }
    return ans;
}
