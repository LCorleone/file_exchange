#include <string.h>
#include <vector>
#include <iostream>

std::vector<std::vector<float> > transpose(std::vector<std::vector<float> > mat)
{
    int row = mat.size();
    int col =  mat[0].size();
    std::vector<std::vector<float> > ret;
    std::vector<float> temp;
    for(int i = 0; i < col; i++) {
        temp.clear();
        for (int j = 0; j < row; j++) {
            temp.push_back(mat[j][i]);
        }
        ret.push_back(temp);
    }
    return ret;
}


std::vector<std::vector<float>> mul_mat(std::vector<std::vector<float>> &mat_1, std::vector<std::vector<float>> &mat_2) {
    std::vector<std::vector<float>> ret;
    int row1 = mat_1.size();
    int col1 =  mat_1[0].size();
    int col2 = mat_2[0].size();
    std::vector<float> temp;
    float score = 0.0;
    for(int i = 0; i < row1; i++) {
        temp.clear();
        for(int j = 0; j < col2; j++) {
            score = 0.0;
            for(int k = 0; k < col1; k++) {
                score += mat_1[i][k] * mat_2[k][j];
            }
            temp.push_back(score);
        }
        ret.push_back(temp);
    }
    return ret;
}


std::vector<std::vector<float>> add(std::vector<std::vector<float>> &mat_1, std::vector<std::vector<float>> &mat_2) {
    std::vector<std::vector<float>> ret;
    int row1 = mat_1.size();
    int col1 =  mat_1[0].size();
    std::vector<float> temp;
    for(int i = 0; i < row1; i++) {
        temp.clear();
        for(int j = 0; j < col1; j++) {
            temp.push_back(mat_1[i][j] + mat_2[i][j]);
        }
        ret.push_back(temp);
    }
    return ret;
}

int main() 
{
	std::vector<std::vector<float> > weight_1 = {{1,2,3,4}, {0,0,1,2}};
    std::vector<std::vector<float>> bias_1 = {{5}, {6}};
    std::vector<std::vector<float>> embedding = {{1,1,2,2}};
    // std::vector<float> b = {1,2,3};
    // a.push_back(b);
    // b = {4,5,6};
    // a.push_back(b);
    std::vector<std::vector<float> > weight_1t = transpose(weight_1);
    std::vector<std::vector<float>> bias_1t = transpose(bias_1);
    std::vector<std::vector<float>> multi = mul_mat(embedding, weight_1t);
    std::vector<std::vector<float>> res = add(multi, bias_1t);
    int row1 = res.size();
    int col1 = res[0].size();
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col1; j++) {
            std::cout << res[i][j] << ' ';
        }
    }

	return 0;
}
