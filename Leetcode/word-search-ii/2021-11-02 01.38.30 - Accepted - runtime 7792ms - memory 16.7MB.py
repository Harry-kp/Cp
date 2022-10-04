class Node:
    def __init__(self):
        self.child = [None]*26
        self.terminal = False

class Trie:
    def __init__(self):
        self.root = Node()
    
    def insert(self,s):
        p = self.root
        for i in s:
            if p.child[ord(i)-ord('a')] is None:
                p.child[ord(i)-ord('a')] = Node()
            p = p.child[ord(i)-ord('a')]
        p.terminal = True
    
            
class Solution:        
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        
        for s in words:
            trie.insert(s)
        n,m = len(board),len(board[0])
        ans = []
        
        def dfs(i,j,node,so_far):
            if i<0 or j<0 or i>=n or j>=m:
                return
            c = board[i][j]
            
            if c == '$':
                return 
            
            node = node.child[ord(c)-ord('a')]
            if node is None:
                return 
            so_far += c
            if(node.terminal):
                ans.append(so_far)
                node.terminal = False
                
            board[i][j] = '$' #visited
            
            dfs(i+1,j,node,so_far)
            dfs(i,j+1,node,so_far)
            dfs(i-1,j,node,so_far)
            dfs(i,j-1,node,so_far)
            board[i][j] = c
            
        for i in range(n):
            for j in range(m):
                dfs(i,j,trie.root,'')
        # print(*trie.root.child)
        return ans
            
            
            
            
        
        
        