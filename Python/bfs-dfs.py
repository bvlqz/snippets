from collections import deque

class TreeNode:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None


class NodeTraversal:

    def bfsWList(self, node):
        if node == None: 
            return
        
        stack = [node]

        while len(stack) > 0:
            current = stack.pop(0)
            print(current.val, end=" ")

            if current.left != None:
                stack.append(current.left)

            if current.right != None:
                stack.append(current.right)
    
    # BFS with Queue
    def bfs(self, root):
        if not root:
            return 
        
        queue = deque([root])
        while queue:
            node = queue.popleft()
            print(node.val, end=" ")

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

    # Recursive dfs
    def dfs(self, root):

        # Preorder Traversal: Root -> Left -> Right
        # Tree Cloning / Serialization / Dir Traversal
        # 1 2 4 8 9 5 10 3 6 7
        #
        # Inorder Traversal: Left -> Root -> Right
        # Retreve Sorted Data in a Binary Search Tree
        # Finding Kth Smallest Elements
        # Largest Element in BST
        # 8 4 9 2 5 10 1 6 3 7
        #
        # Postorder Traversal: Left -> Right -> Root
        # Shortest Path Problems
        # 8 9 4 10 5 2 6 7 3 1

        if root:
            # Inorder Traversal
            self.dfs(root.left)
            print(root.val, end=" ")
            self.dfs(root.right)

    # DFS with Stack - Preorder Traversal
    def dfsWStack(self, root):
        if not root:
            return
        
        stack = [root]
        while stack:
            node = stack.pop()
            
            print(node.val, end=" ")
            
            # Push right first, so left is processed first
            # (preorder: root -> left -> right)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

def main():
    # Simple Binary Tree
    # 
    #        1
    #      /   \
    #     2     3
    #    / \   / \
    #   4   5 6   7
    #  / \   \
    # 8   9   10
    
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)
    root.left.left.left = TreeNode(8)
    root.left.left.right = TreeNode(9)
    root.left.right.right = TreeNode(10)


    traversal = NodeTraversal()
    print("Traversal: BFS (List)")
    traversal.bfsWList(root)
    print("\nTraversal: BFS (Queue)")
    traversal.bfs(root)
    print("\nTraversal: DFS (Recursive)")
    traversal.dfs(root)
    print("\nTraversal: DFS (Stack)")
    traversal.dfsWStack(root)
    print("\nDone.")

if __name__ == "__main__":
    main()
