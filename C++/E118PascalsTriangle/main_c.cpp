class Solution {
public:
    int** generate(int numRows, int** columnSizes, int* returnSize) {
        if(!columnSizes) return 0;
        if(!returnSize || numRows == 0) return 0;
        int **returnArray = (int **)malloc(numRows*sizeof(int *));
        int *columnSizeArray = malloc(sizeof(int)*numRows);

        *returnSize = 0;
        int i = 0;
        int j = 0;
        for(i=0; i<numRows; i++) {
            returnArray[i] = (int *)malloc(sizeof(int)*(i+1));
            columnSizeArray[i]=i+1;
            for(j=0;j<i+1;j++){
                if(j==0){
                    returnArray[i][j] = 1;
                } else if(j==i) {
                    returnArray[i][j] = 1;
                } else {
                    returnArray[i][j] = returnArray[i-1][j-1] + returnArray[i-1][j];
                }
            }
            (*returnSize)++;
        }
        *columnSizes = columnSizeArray;
        return returnArray;
    }
}

int main() {
    Solution().generate(5, cs, rs)
}
