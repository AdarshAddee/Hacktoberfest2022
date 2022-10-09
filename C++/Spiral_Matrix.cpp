// Github username: kashika1109
// Aim: Sprial Matrix in C++
// Date: 10 October 2022

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int r, int c) 
    {
        vector<int> ans;
    int rt=0,cl=0;
int cr=c-1;
int rb=r-1;
while(rt<=rb && cl<=cr){
	for(int i=cl;i<=cr;++i){
		ans.push_back(a[rt][i]);
	}
	rt++;
	for(int i=rt;i<=rb;++i){
		ans.push_back(a[i][cr]);
	}
	cr--;
	if(rt<=rb){
		for(int i=cr;i>=cl;--i){
			ans.push_back(a[rb][i]);
		}
	rb--;
	}
	if(cl<=cr){
		for(int i=rb;i>=rt;--i){
			ans.push_back(a[i][cl]);
		}
	cl++;
	}
	
}
return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends