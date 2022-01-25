class Solution {
public:
    int type_counts[3] = {0,0,0};  // counters to keep track of open parantheses
    stack<int> stack;              // stack to keep track of parantheses type
    
    void incrementAndPush(int type){
        type_counts[type]++;
        stack.push(type);
    }
    
    // checks if invalid case occurs
    bool decrementAndPop(int type){
        if(stack.empty() or type != stack.top() or type_counts[type] == 0){
            return false;
        }
        type_counts[type]--;
        stack.pop();
        return true;
    }
    
    bool isValid(string s) {
        // parse through string
        for(int i = 0; i < s.length(); ++i){
            switch(s[i]){
                case '(':
                    incrementAndPush(0);
                    break;
                case '{':
                    incrementAndPush(1);
                    break;
                case '[':
                    incrementAndPush(2);
                    break;
                case ')':
                    if(!decrementAndPop(0)){
                        return false;
                    }
                    break;
                case '}':
                    if(!decrementAndPop(1)){
                        return false;
                    }
                    break;
                case ']':
                    if(!decrementAndPop(2)){
                        return false;
                    }
                    break;
            }
        }
        
        // check if any remaining open parantheses exist
        if(type_counts[0] + type_counts[1] + type_counts[2] == 0){
            return true;
        }
        return false;
    }
};