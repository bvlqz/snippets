from collections import deque


class MatrixTraversal:
    def __init__(self, matrix):
        self.matrix = matrix

    def bfs(self, startRow, startCol):
        rowCount = len(self.matrix)
        colCount = len(self.matrix[0])

        visited = set()
        
        queue = deque([(startRow, startCol)])
        visited.add((startRow, startCol))

        while queue:
            row, col = queue.popleft()

            print(self.matrix[row][col], end=" ")

            #               right   down    left      up
            directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
            
            for rowDir, colDir in directions:
                newRow, newCol = row + rowDir, col + colDir

                if 0 <= newRow < rowCount and 0 <= newCol < colCount:
                    if (newRow, newCol) in visited:
                        continue
                    queue.append((newRow, newCol))
                    visited.add((newRow, newCol))

    def dfs(self, row, col, visited):
        rowCount = len(self.matrix)
        colCount = len(self.matrix[0])

        # Base case: If out of bounds or visited
        if (
                row < 0
                or row >= rowCount 
                or col < 0 
                or col >= colCount 
                or (row, col) in visited
        ):
            return

        visited.add((row, col))
        
        print(self.matrix[row][col], end=" ")


        #                up      down    left     right
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        for rowDir, colDir in directions:
            newRow, newCol = row + rowDir, col + colDir
            self.dfs(newRow, newCol, visited)

def main():
    matrix = [
        ['A', 'B', 'C', 'D', 'E'],
        ['F', 'G', 'H', 'I', 'J'],
        ['K', 'L', 'M', 'N', 'O'],
        ['P', 'Q', 'R', 'S', 'T'],
        ['U', 'V', 'W', 'X', 'Y']
    ]
   
    print("Original matrix:")
    for row in range(len(matrix)):
        print()
        for col in range(len(matrix[0])):
            print(matrix[row][col], end=" ")

    print("\n")

    traversal = MatrixTraversal(matrix)
    print("Matrix BFS")
    traversal.bfs(0, 0)
    print("\n\n Matrix DFS")
    traversal.dfs(0, 0, set())

if __name__ == "__main__":
    main()
