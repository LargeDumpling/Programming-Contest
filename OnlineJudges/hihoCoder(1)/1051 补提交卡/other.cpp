#include <iostream>  
#include <vector>  
  
int main()  
{  
    int T;  
    std::cin >> T;  
      
    int N, M;  
      
    for(int i = 0; i < T; ++i)  
    {  
        std::cin >> N >> M;  
        std::vector<int> nums(N + 1, 0);  
        for(int j = 0; j < N; ++j)  
        {  
            std::cin >> nums[j];  
        }  
        nums[N] = 100;  
          
        if(M >= N)  
        {  
            std::cout << 100 << std::endl;  
            continue;  
        }  
          
         int maxVal = nums[M] - 1;  
        for(int j = 0; j < N - M; ++j)  
        {  
            maxVal = std::max(maxVal, nums[j + M + 1] - nums[j] - 1);  
        }  
          
        std::cout << maxVal << std::endl;  
    }  
      
    return 0;  
}  

