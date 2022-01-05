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
