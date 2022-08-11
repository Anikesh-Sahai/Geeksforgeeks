//Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> s;
       vector<int> v;
       for(int i=0;i<n;i++){
           if(s.empty()){
               v.push_back(-1);
               s.push({price[i],i});
           }
           else{
               if(s.top().first>price[i]){
                   v.push_back(s.top().second);
                   s.push({price[i],i});
               }
               else{
                   while(s.size()>0 && s.top().first<=price[i]){
                       s.pop();
                   }
                   if(s.empty()){
                       v.push_back(-1);
                       s.push({price[i],i});
                   }
                   else{
                       v.push_back(s.top().second);
                       s.push({price[i],i});
                   }
               }
           }
       }
       for(int i=0;i<n;i++){
           v[i]=i-v[i];
       }
       return v;
    }