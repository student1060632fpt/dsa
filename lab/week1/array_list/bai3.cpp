#include <iostream>
#include <algorithm>
using namespace std;

int buyCar(int *nums, int length, int k)
{
  if (length == 0)
    return 0;
  sort(nums, nums + length);
  int i = 0, things = 0, sum = 0;
  for (int i = 0; i < length; i++)
  {

    if (sum + nums[i] <= k)
    {
      things++;
      sum = sum + nums[i];
    }
  }
  return things;
}

int main()
{
  int nums[] = {90, 30, 40, 90, 20};
  // int nums[] = {10, 30, 40, 90, 20};
  int length = sizeof(nums) / sizeof(nums[0]);
  cout << buyCar(nums, length, 90) << "\n";
  // 3

  return 0;
}
