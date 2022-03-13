# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def bfs(self, node):
        if node == None: 
            return
        
        stack = [node]

        while len(stack) > 0:
            current = stack.pop(0)
            print(current.val)

            if current.left != None:
                stack.append(current.left)

            if current.right != None:
                stack.append(current.right)

    def dfs(self, node):
        if node:
            self.dfs(node.left)
            print(node.val)
            self.dfs(node.right)

    def solve(self, root):
        print("BFS")
        self.bfs(root)
        print("DFS")
        self.dfs(root)
