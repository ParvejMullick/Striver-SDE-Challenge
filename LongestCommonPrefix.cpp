string longestCommonPrefix(vector<string> &arr, int n)
{
    string lcp="";
    for(int i=0;i<arr[0].size();i++){
        char ch = arr[0][i];
        bool match = true;
        
        for(int j=1;j<n;j++){
            if(i>arr[j].size() || ch != arr[j][i]){
                match = false;
                break;
            }
        }

        if(match==false){
            break;
        }
        
        else{
            lcp += ch;
        }
    }
    return lcp;
}
