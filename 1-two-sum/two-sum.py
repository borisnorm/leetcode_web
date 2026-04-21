class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
      mp = {}

      for i, x in enumerate(nums):
        need = target - x
      
        if need in mp:
          return [mp[need], i]
        
        mp[x] = i
        