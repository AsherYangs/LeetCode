/....................................................................../
  The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. 
  Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
/....................................................................../

  
//way 1
string countAndSay(int n) {
    if(n==1)
        return "1";
    string ans = "";
    string lastAns = "1";   //紀錄每個n-1的答案
    for(int i=2; i<=n; i++){
        int count = 1;
        ans = "";
        for(int j=0; j<lastAns.size(); j++){
            if(j==lastAns.size()-1){
                ans += to_string(count);
                ans += lastAns[j];
                break;
            }
            if(lastAns[j]==lastAns[j+1])
                count++;
            else{
                ans += to_string(count);
                ans += lastAns[j];
                count=1;
            }
        }
        lastAns = ans;
    }
    return ans;
}

//way2
string countAndSay(int n) {
    if(n==1)
        return "1";
    return help(n-1);
}
string help(int n){
  if(n==1)
      return "11";
  string temp = help(n-1);
  int count = 1;
  string s = "";
  for(int i=1; i<temp.size(); i++){
      if(temp[i]==temp[i-1])
          count++;
      if(temp[i]!=temp[i-1]){
          s = s + to_string(count);
          s.push_back(temp[i-1]);
          count=1;
      }
      if(i==temp.size()-1){
          s = s + to_string(count);
          s.push_back(temp[temp.size()-1]);
      }
}
return s;
