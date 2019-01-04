public: int reverse(int x) {
    if(x>2147483647 || x<-2147483648) 
       return 0;
    
    vector<int> v;
    int j = 0;
    do{
       v.push_back(x%10);
       x/=10;
    }
    while(x!=0);
    
    int result = 0;
    for(int i = 0; i<v.size();i++){ 
       result=result*10+v[i];
       if(result>2147483647 || result<-2147483648)
          return 0;
    }
    return result;
}
