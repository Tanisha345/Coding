int differ(string a, string b){
    if(a.length()!=b.length()) return 0;
int diffword=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i])
        diffword++;
    }

    return diffword==1;
}


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int haveEndWord=0;
        vector<int> visited(wordList.size(), 0);
        for(auto it: wordList){
            if(it==endWord){
              haveEndWord=1;
            }
        }

        if(haveEndWord==0) return 0;

        queue< pair<string, int>> q;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==beginWord)
            visited[i]=1;
            
        }
q.push( {beginWord, 1});


        while(!q.empty()){
            auto [word, dist]= q.front();
            if(word==endWord) return dist;
            q.pop();

            for(int i=0;i<wordList.size();i++){
                if(visited[i]==0 && differ(word, wordList[i])==1){
                    visited[i]=1;
                    q.push({wordList[i], dist+1});
                }
            }


        }

return 0;


    }
};