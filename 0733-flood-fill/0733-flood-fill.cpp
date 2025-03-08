void dfs(vector<vector<int>> &image, int sr, int sc, int initialColor, int color){
    if(sr<0 || sc<0 || sr>= image.size() || sc>=image[0].size() || image[sr][sc]!=initialColor){
        return;
    }

    image[sr][sc]=color;
    dfs(image, sr+1, sc, initialColor, color);
    dfs(image, sr, sc+1, initialColor, color);
    dfs(image, sr-1, sc, initialColor, color);
    dfs(image, sr, sc-1, initialColor, color);


}



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor= image[sr][sc];
        if(image[sr][sc]==color) return image;
        dfs(image, sr, sc, initialColor, color);
        return image;
    }
};