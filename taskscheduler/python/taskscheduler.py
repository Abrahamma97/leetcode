class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        time = 0
        count = Counter(tasks)
        maxheap = [-i for i in count.values()]
        heapq.heapify(maxheap)
        q = deque()

        while(maxheap or q):
            time = time+1
            if not maxheap:
                time = q[0][1]
            else:
                cnt = 1 + heapq.heappop(maxheap)
                if(cnt):
                    q.append([cnt,time+n])
            if(q and q[0][1] == time):
                heapq.heappush(maxheap, q.popleft()[0])

        return time
