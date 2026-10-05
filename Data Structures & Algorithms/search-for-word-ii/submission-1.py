class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.isEnd = False


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = Trie()
        m,n = len(board), len(board[0])
        def insertWord(word: str):
            curr = root
            for c in word:
                ind = ord(c) - ord('a')
                if curr.children[ind] is None:
                    curr.children[ind] = Trie()
                curr = curr.children[ind]
            curr.isEnd = True

        for word in words:
            insertWord(word)
        
        res = set()
        
        def dfs(i, j, node, word):
            c = board[i][j]
            node = node.children[ord(c)-ord('a')]
            if node.isEnd:
                res.add(word+c)
            board[i][j] = '#'
            dirs = [(0,1), (0,-1), (1,0), (-1,0)]
            for dir in dirs:
                x, y = i+dir[0], j+dir[1]
                if x>=0 and x<m and y>=0 and y<n and board[x][y] != '#' and node.children[ord(board[x][y]) - ord('a')] is not None:
                    dfs(x,y,node,word+c)
            board[i][j] = c

        for i in range(m):
            for j in range(n):
                if root.children[ord(board[i][j])-ord('a')] is not None:
                    dfs(i,j,root,"")

        return list(res)         