Reverse Array /String:

// TC:O(N)
// SC:O(1)

string reverseWord(string str){
    int i=0; int j=str.length()-1;
    for(i=0,j=str.length()-1; i<j; i++,j--)
    {
        int temp= str[i];
        str[i]=str[j];
        str[j]=temp;
        
    }
      return str;
}


If it is asked that reverse the array after the given Mth position, then the all code will be same on;ly difference is that we will change the start position as i= M+1;

string reverseWord(string str, int M){
    int i=M+1; int j=str.length()-1;
    for(i=0,j=str.length()-1; i<j; i++,j--)
    {
        int temp= str[i];
        str[i]=str[j];
        str[j]=temp;
        
    }
      return str;
}
