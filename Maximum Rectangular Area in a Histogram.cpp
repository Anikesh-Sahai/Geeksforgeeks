//Function to find largest rectangular area possible in a given histogram.
    vector<long long> NSL(long long h[], int n){
        stack<pair<long long,long long>> s;
        vector<long long> v;
        for(long long i=0;i<n;i++){
            if(s.empty()){
                v.push_back(-1);
                s.push({h[i],i});
            }
            else{
                if(s.top().first<h[i]){
                    v.push_back(s.top().second);
                    s.push({h[i],i});
                }
                else{
                    while(s.size()>0 && s.top().first>=h[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        v.push_back(-1);
                        s.push({h[i],i});                        
                    }
                    else{
                        v.push_back(s.top().second);
                        s.push({h[i],i});                        
                    }
                }
            }
        }
        return v;
    };
    vector<long long> NSR(long long h[],int n){
        stack<pair<long long,long long>> s;
        vector<long long> v;
        for(long long i=n-1;i>=0;i--){
            if(s.empty()){
                v.push_back(n);
                s.push({h[i],i});
            }
            else{
                if(s.top().first<h[i]){
                    v.push_back(s.top().second);
                    s.push({h[i],i});
                }
                else{
                    while(s.size()>0 && s.top().first>=h[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        v.push_back(n);
                        s.push({h[i],i});                        
                    }
                    else{
                        v.push_back(s.top().second);
                        s.push({h[i],i});                        
                    }
                }
            }
        }
        reverse(v.begin(),v.end());
        return v;
    };
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> nsr=NSR(arr,n);
        vector<long long> nsl=NSL(arr,n);
        vector<long long> width(n);
        vector<long long> area(n);
        for(int i=0;i<n;i++){
            
            width[i]=nsr[i]-nsl[i]-1;
            //cout<<width[i]<<" "<<nsr[i]<<" "<<nsl[i]<<endl;
            area[i]=width[i]*arr[i];
        }
        return *max_element(area.begin(), area.end());
        
    }