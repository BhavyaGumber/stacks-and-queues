class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
         vector<long long >LeftIndex(long long arr[],int n)
      {
           vector<long long>left;
           stack<pair<long long,int>>s;
           int pseudoIndex=-1;
           for(int i=0;i<n;i++)
           {
           
               if(s.size()==0) left.push_back(pseudoIndex);
               else if(s.size()>0 && s.top().first<arr[i]) left.push_back(s.top().second);
               else if(s.size()>0 && s.top().first>=arr[i])
               {
                      while(s.size()>0 && s.top().first>=arr[i]) {s.pop();}
                      if(s.size()==0) left.push_back(pseudoIndex); 
                      else left.push_back(s.top().second);
               }
               s.push({arr[i],i});
        } 
           return left;
    }       
    vector<long long >RightIndex(long long arr[],int n)
    {
        vector<long long>right;
        stack<pair<long long,int>>s1;
        int pseudoIndex2=n;
        for(int i=n-1;i>=0;i--)
        {
            if(s1.size()==0) right.push_back(pseudoIndex2);
            else if(s1.size()>0 && s1.top().first<arr[i]) right.push_back(s1.top().second);
            else if(s1.size()>0 && s1.top().first>=arr[i])
            {
                while(s1.size()>0 && s1.top().first>=arr[i]) {s1.pop();}
                if(s1.size()==0)right.push_back(pseudoIndex2); 
                else right.push_back(s1.top().second);
                   
            }
            s1.push({arr[i],i});
             
            
        }
        reverse(right.begin(),right.end());
        return right;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
          vector<long long >left  =LeftIndex(arr,n);
        vector<long long >right =RightIndex(arr,n);
       long long area=0;
       long long mx=INT_MIN;
       for(int i=0;i<n;i++)
       {
           long long width=right[i]-left[i]-1;
           area=arr[i]*width;
           mx=max(mx,area);
       }
       return mx;
    }
};
