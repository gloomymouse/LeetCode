// G家面试题...

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void pixFill(int** image, int oldColor, int newColor, int sr, int sc, int row, int col) {
    if (image[sr][sc] != oldColor) {
        return;
    } else {
        image[sr][sc] = newColor;
    }
    if (sr > 0) {
        pixFill(image, oldColor, newColor, sr - 1, sc, row, col);
    }
    if (sr < row - 1) {
        pixFill(image, oldColor, newColor, sr + 1, sc, row, col);
    }
    if (sc > 0) {
        pixFill(image, oldColor, newColor, sr, sc - 1, row, col);
    }
    if (sc < col - 1) {
        pixFill(image, oldColor, newColor, sr, sc + 1, row, col);
    }
    return;
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    int** newImage = (int**)malloc(sizeof(int*) * imageSize);
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        newImage[i] = (int*)malloc(sizeof(int)*imageColSize[0]);
        (*returnColumnSizes)[i] = imageColSize[0];
        for (int j = 0; j < imageColSize[0]; j++) {
            newImage[i][j] = image[i][j];
        }
    }
    
    if (newColor != image[sr][sc]) {
        pixFill(newImage, image[sr][sc], newColor, sr, sc, imageSize, imageColSize[0]);
    }   
    return newImage;
}
