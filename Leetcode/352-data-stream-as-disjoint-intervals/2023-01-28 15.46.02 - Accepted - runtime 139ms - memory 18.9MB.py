class SummaryRanges:

    def __init__(self):
        self.intervals = []
        self.seen = set()

    def addNum(self, value: int) -> None:
        if value in self.seen:
            return
        self.seen.add(value)
        idx = bisect.bisect_right(self.intervals, [value,value])
        prev = idx-1
        pos = idx

        # [1,1],[2,2],[3,3] => [1,3]
        # [1,1], 3,3 , 5,5 => [1,1][3,3][5,5]
        #[1,1][2,2],[4,4] => [1,2][4,4]
        #[1,1][3,3][4,4] => [1,1][3,4]
        
        if prev>-1 and pos< len(self.intervals) and self.intervals[prev][1]+1 == value and self.intervals[pos][0] == value+1:
            self.intervals[prev][1] = self.intervals[pos][1]
            self.intervals.pop(pos)
        elif prev>-1 and self.intervals[prev][1]+1 == value:
            self.intervals[prev][1] = value
        elif pos< len(self.intervals) and self.intervals[pos][0] == value+1:
            self.intervals[pos][0] = value
        else:
            self.intervals.insert(pos,[value,value])              

    def getIntervals(self) -> List[List[int]]:
        return self.intervals
        


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()