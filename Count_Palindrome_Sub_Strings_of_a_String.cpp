bool isPalindrome(char s[],int i, int j){
    while(i<=j){
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int CountPS(char S[], int n)
{
    //code here
    int ans =0;
    for(int i=0; i<n;i++){
        for(int j =i+1; j<n;j++){
            if(isPalindrome(S,i,j))
            ans++;
        }
    }
    return ans;
}