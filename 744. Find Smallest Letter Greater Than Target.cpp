class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         int n = letters.size();
         char ans = '{';
         int low = 0, high = n - 1;

         while(low<=high){
            int mid = low + (high-low)/2;
            
            if(letters[mid]>target){
                 ans = letters[mid];
                 high = mid - 1;
            }else{
                 low = mid + 1;
            }
         }

         if(ans=='{'){
             return letters[0];
         }else{
             return ans;
         }
    }
};