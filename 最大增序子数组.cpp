#include <iostream>
using namespace std;

int main() 
{
    int arr[100];  // 假设数组最大长度100
    int n;
    
    // 输入数组
    cout << "请输入数组长度: ";
    cin >> n;
    cout << "请输入" << n << "个数字: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 寻找最长增序子数组
    int start = 0;  // 最长子数组的起始位置
    int maxLength = 1;  // 最长子数组的长度
    int currentStart = 0;  // 当前子数组的起始位置
    int currentLength = 1;  // 当前子数组的长度
    
    for (int i = 1; i < n; i ++ ) 
	{
        if (arr[i] >= arr[i - 1]) 
		{
            // 如果当前数字 >= 前一个数字，继续当前子数组
            currentLength ++ ;
        } 
		else 
		{
            // 否则开始新的子数组
            currentStart = i;
            currentLength = 1;
        }
        
        // 如果找到更长的子数组，更新记录
        if (currentLength > maxLength) 
		{
            maxLength = currentLength;
            start = currentStart;
        }
    }
    
    // 输出结果
    cout << "最长增序子数组: ";
    for (int i = start; i < start + maxLength; i++) 
	{
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "长度: " << maxLength << endl;
    
    return 0;
}
