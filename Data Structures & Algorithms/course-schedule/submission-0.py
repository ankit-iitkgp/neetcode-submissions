class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        indegree = [0] * numCourses
        for preq in prerequisites:
            adj[preq[0]].append(preq[1])
            indegree[preq[1]] += 1

        nodes = deque()
        count = 0
        for i in range(numCourses):
            if indegree[i] == 0:
                nodes.append(i)
                count += 1

        while nodes:
            i = nodes.popleft()
            for j in adj[i]:
                indegree[j] -= 1
                if indegree[j] == 0:
                    nodes.append(j)
                    count += 1
        return count == numCourses


