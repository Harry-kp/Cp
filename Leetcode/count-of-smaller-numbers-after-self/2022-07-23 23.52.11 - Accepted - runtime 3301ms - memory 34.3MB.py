from sortedcontainers import SortedList
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        memo = SortedList()
        res = []
        for val in reversed(nums):
            smaller_count = memo.bisect_left(val)
            res.append(smaller_count)
            memo.add(val)
        res.reverse()
        return res