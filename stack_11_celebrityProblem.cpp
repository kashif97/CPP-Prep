class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        while(st.size()>1){
            int temp1 = st.top();
            st.pop();
            int temp2 = st.top();
            st.pop();
            //here we are only pushing the single element when  commparing
            //and we will handle the other element in the next iteration
            if(M[temp1][temp2] == 1){
                st.push(temp2);
            }
            else{
                st.push(temp1);
            }
        }
        int final = st.top();
        for(int j=0; j<n; j++){
            if(final != j && M[final][j] != 0){
                return -1;
            }
        }
        for(int k=0; k<n; k++){
            if(final != k && M[k][final]  != 1){
                return -1;
            }
        }
        return final;
    }
};