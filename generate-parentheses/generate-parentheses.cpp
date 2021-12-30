class Solution {
public:
    
    // return structure
    vector<string> outVector;
    
    // add either a '(' or ')' recursively to current parantheses string
    void myfunc(int open_count, int close_count, int target_count, string parantheses){
        
        // stop if paranthesis are complete and numerous enough
        if((open_count == close_count) && (open_count == target_count)){
            // push answer to return structure
            outVector.push_back(parantheses);
            return;
        }
        
        // add ')' to parantheses string if legal
        if(close_count < open_count){
            myfunc(open_count, close_count+1, target_count, parantheses + ")");
        }
        // add '(' to parantheses string if legal
        if(open_count < target_count){
            myfunc(open_count+1, close_count, target_count, parantheses + "(");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        // do the thing starting with an open paranthese and return answer
        myfunc(1, 0, n, "(");
        return outVector;
    }
};