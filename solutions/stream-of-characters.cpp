//Stream of Characters -> 08/24/2020 11:55
typedef struct _tireNode{
    struct _tireNode* m[26] = {};
    int end;
}tireNode;

class StreamChecker {
public:
    
    tireNode* dummy;
    string q = "";
    
    StreamChecker(vector<string>& words) {
        dummy = new tireNode();
        dummy->end = 0;
        for(int i=0; i<words.size(); i++){
            string tmp = words[i];
            tireNode* run = dummy;
            for(int j=tmp.size()-1; j>=0; j--){
                if(run->m[tmp[j] - 'a'] == nullptr){
                    run->m[tmp[j] - 'a'] = new tireNode();
                    run->m[tmp[j] - 'a']->end = 0;
                }
                run = run->m[tmp[j] - 'a'];
            }
            run->end = 1;
        }
    }
    
    bool query(char letter) {
        q += letter;
        tireNode* run = dummy;
        for(int i=q.size()-1; i>=0; i--){
            if(run->end)return true;
            else if(run->m[q[i] - 'a'] != nullptr)run = run->m[q[i] - 'a'];
            else return false;
        }
        if(run->end)return true;
        return false;
    }
};
