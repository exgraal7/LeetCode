class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n_dict = {}
        for i in range(len(nums)):
            f_num = target - nums[i]
            if n_dict.get(f_num) != None:
                return [n_dict[f_num], i]
            n_dict[nums[i]] = i
        return []
