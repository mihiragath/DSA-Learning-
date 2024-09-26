//189.
/*/Rotate array...
vector<int> temp(nums.size());

for(int i=0; i< nums.size(); i++){
    temp[i+k]%nums.size() = nums[i];
}

nums = temp;



1752.check if aaray sorted or rotated.

int count = 0;
int n = nums.size();

for(int i=1; i<n; i++){
    if(nums[i-1]>i){
        count ++;
    }
}

if(nums[n-1] > nums[0]){
    count ++;
}

return <= 1;


another question..
int reverse(arr[]){
int s=0;
int e = v.size()-1;

while(s<e){
swap(v[s++], v[e--]);
}
reverse v;
}

int i=n-1;
int j=m-1;
vector<int>=ans;
int carry = 0;\

while(i>=0 && j>=0){
int val1= a[i];
int val2 = a[j]

int sum = val1+val2+carry;

carry = sum/10;
sum = sum%10;
ans.push_back(sum);
i--;
j--

}

while(carry != 0){
int sum = carry;

carry = sum/10;
sum = sum%10;
ans.push_back(sum);
i--;

}

while(j>=0){
int sum = b[j] + carry;
carry = sum/10;
sum = sum%10;
ans.push_back(sum);
j--;
}
return reverse(ans);
*/
