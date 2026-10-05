from heapq import heappush, heappop

class MedianFinder:

    def __init__(self):
        self.min_heap = []
        self.max_heap = []
        self.n = 0

    def addNum(self, num: int) -> None:
        if self.n%2==0:
            heappush(self.min_heap, num)
        else:
            heappush(self.max_heap, -num)
        if self.n>0 and self.min_heap[0] < -self.max_heap[0]:
            min_heap_pop = heappop(self.min_heap)
            max_heap_pop = heappop(self.max_heap)
            heappush(self.min_heap, -max_heap_pop)
            heappush(self.max_heap, -min_heap_pop)
        self.n += 1
        

    def findMedian(self) -> float:
        median = self.min_heap[0]
        if self.n%2 == 1:
            return median
        else:
            median2 = self.max_heap[0] * (-1)
            return (median+median2)/2
        