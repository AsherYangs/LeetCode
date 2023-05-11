//first way
// 找到每個因數並相加
if(num==1)
    return false;
int sum = 1;
for(int i=2; i<=num/2; i++){
    if(num%i==0)
        sum+=i;
}
return sum==num;

// Improve from way one
if(num==1)
    return false;
int sum = 1;
for(int i=2; i*i<=num; i++){
    if(num%i==0){
        if(i==num/i) //若該數為完全平方數則僅需要加一次
            sum+=i;
        else{        //否則配對的因數都需要相加起來
            sum+=i;
            sum+=num/i;
        }
    }
}
return sum==num;

// second way
//binary Search, 起始因數為2往下找若有配對成功即把left設成另一個因數, 這樣一次可以縮減許多範圍
if(num==1)
    return false;
int r = 2;
int l = num/2;
while(r<l){
    if(num%r==0){
        sum+=r;
        l = (num/r);
        sum+= (num/r);
    }
    r++;
}
return sum==num;
