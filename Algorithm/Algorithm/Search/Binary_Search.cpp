#pragma once
#include <vector>

// 이상하게 자꼬 에러뜸...뭐 잘못했나바..ㅜㅜㅜ
//int Bi(vector<int> arr, int target)
//{
//	int low = 0;
//	int high = arr.size() - 1;
//	int idx = arr.size() / 2;
//
//	while (low <= high)
//	{
//		if (target > arr[idx])
//		{
//			low = idx + 1;
//			idx = (high + low) / 2;
//		}
//		else if (target < arr[idx])
//		{
//			high = idx - 1;
//			idx = (high + low) / 2;
//		}
//		else
//		{
//			return idx;
//		}
//	}
//
//	return -1;
//}