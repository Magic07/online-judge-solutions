class Solution {
public:
    int getMax(stack<int> num){
        int answer=0;
        while(!num.empty()&&num.top()==9){
            answer*=10;
            answer+=9;
            num.pop();
        }
        if(num.empty()){
            return answer;
        }
        int x=num.top();
        while(!num.empty()){
            answer*=10;
            if(num.top()==x){
                answer+=9;
            } else {
                answer+=num.top();
            }
            num.pop();
        }
        return answer;
    }
    int getMin(stack<int> num){
        int answer(0);
        int y=0;
        if(num.top()==1){
            while(!num.empty()&&num.top()==1){
                answer*=10;
                answer+=1;
                num.pop();
            }
        } else {
            y=1;
        }
        if(num.empty()){
            return answer;
        }
        while(!num.empty()&&(num.top()==1||num.top()==0)){
            answer*=10;
            answer+=num.top();
            num.pop();
        }
        if(num.empty()){
            return answer;
        }
        int x=num.top();
        while(!num.empty()){
            answer*=10;
            if(num.top()==x){
                answer+=y;
            } else {
                answer+=num.top();
            }
            num.pop();
        }
        return answer;
    }
    int maxDiff(int num) {
        stack<int> numStack;
        while(num!=0){
            numStack.push(num%10);
            num/=10;
        }
        int a=getMax(numStack);
        int b=getMin(numStack);
        return a-b;
    }
};