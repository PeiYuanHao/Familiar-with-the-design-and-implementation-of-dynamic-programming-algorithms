#include <iostream>
#include <string>
using namespace std;

// 递归构建括号表达式
string makeBrackets(int s[][100], int i, int j) 
{
    if (i == j) 
	{
        return "A" + to_string(i);
    }
    
    int k = s[i][j];
    string left = makeBrackets(s, i, k);
    string right = makeBrackets(s, k + 1, j);
    
    return "(" + left + "*" + right + ")";
}

int main() 
{
    // 定义数组
    int p[100];      // 存储矩阵的维度
    int m[100][100]; // 存储最小计算量
    int s[100][100]; // 存储分割位置
    
    int n; // 矩阵个数
    
    // 输入矩阵个数
    cout << "请输入矩阵个数: ";
    cin >> n;
    
    // 输入矩阵维度
    cout << "请输入" << n + 1 << "个维度数字: ";
    for (int i = 0; i <= n; i ++ ) 
	{
        cin >> p[i];
    }
    
    // 初始化：单个矩阵不需要计算
    for (int i = 1; i <= n; i ++ ) 
	{
        m[i][i] = 0;
    }
    
    // 动态规划计算最小计算量
    for (int len = 2; len <= n; len ++ ) 
	{        // 矩阵链的长度
        for (int i = 1; i <= n - len + 1; i ++ ) // 遍历所有可能的起始位置 
		{ // 起始位置
            int j = i + len - 1;                 // 结束位置
            m[i][j] = 1e9 + 10;                // 设一个很大的数
            
            // 尝试所有可能的分割位置
            for (int k = i; k < j; k ++ ) 
			{
                // 计算当前分割方式的代价
                int cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                // 算代价 = 左半部分代价 + 右半部分代价 + 合并代价 
            
                // 如果找到更小的代价，就更新
                if (cost < m[i][j]) 
				{
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    // 输出结果
    cout << "最小计算量: " << m[1][n] << endl;
    cout << "最优计算顺序: " << makeBrackets(s, 1, n) << endl;
    
    return 0;
}
