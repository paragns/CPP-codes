class Solution {
    
public:
    vector<vector<vector<int>>> memo;
    int maxPoints(vector<int> &boxes, int i, int j, int k){
        if(i > j)  return 0;
        if(i == j) return k * k;
        if(memo[i][j][k] != -1) return memo[i][j][k];
        
        int removeBoxes = maxPoints(boxes, i + 1, j, 1) + (k * k);
        
        for(int index = i + 1; index <= j; index++){
            if(boxes[i] == boxes[index])
                removeBoxes = max(removeBoxes, maxPoints(boxes, i + 1, index - 1, 1) + maxPoints(boxes, index, j, k + 1));
        }
        return memo[i][j][k] = removeBoxes;
    }
    int removeBoxes(vector<int>& boxes){
        memo = vector(boxes.size(), vector<vector<int>>(boxes.size(), vector<int>(boxes.size(), -1)));
        return maxPoints(boxes, 0, boxes.size() - 1, 1); 
    }
};
