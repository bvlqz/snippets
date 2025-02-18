class Heap:
    def __init__(self):
        self.heap = []

    def push(self, value):
        print("\n[ PUSH ]")
        self.heap.append(value) # We always append, a heap is a complete binary tree

        # Get the index of the value we just pushed
        index = len(self.heap) - 1
        print(f"Pushed {value} to heap, starting bubble up on index {index}")
        self._percolateUp(index)

    # AKA Bubble Up 
    def _percolateUp(self, index):
        parentIndex = (index - 1) // 2
        print(f"Parent index: {parentIndex}")
        
        # parentIndex of 0 will evaluate to -1
        # HEAP PROPERTY: parent < child (min heap)
        
        parentValue = self.heap[parentIndex]
        childValue = self.heap[index]
        if index > 0 and childValue < parentValue:
            # Swap parent if smaller than child
            print(f"\nChild node at {index} going up")
            print(self.heap)
            print(f"[{index}]:{childValue} <-> [{parentIndex}]:{parentValue}") 
            self.heap[index], self.heap[parentIndex] = self.heap[parentIndex], self.heap[index]
            print(self.heap)

            # Continue Recursively
            self._percolateUp(parentIndex)

    # AKA Get Min
    def pop(self):
        print("\n[ POP ]")
        
        if not self.heap:
            print("Cannot pop() heap is empty")
            return None
        
        if len(self.heap) == 1:
            print(f"POP: {self.heap[0]} (Last heap item)")
            return self.heap.pop()

        print()
        print(self.heap)
        print(f"[{0}]:{self.heap[0]} <-> [-1]:{self.heap[-1]}")
        self.heap[0], self.heap[-1] = self.heap[-1], self.heap[0]
        print(self.heap)
        
        minValue = self.heap.pop()
        
        # Restore Heap Property from the new root
        print("Heapify Down Start")
        self._percolateDown(0)
        print(f"POP: {minValue}")
        return minValue

    # AKA Heapify Down
    def _percolateDown(self, index):
        # While index has a left child
        # A left child will not exist if we’re at a leaf node or beyond
        while 2 * index + 1 < len(self.heap):
            
            leftChildIndex = 2 * index + 1
            rightChildIndex = 2 * index + 2
            
            # Get the smallest child index
            rightChildExists = rightChildIndex < len(self.heap) 
            if not rightChildExists:
                smallestChildIndex = leftChildIndex
            elif self.heap[rightChildIndex] < self.heap[leftChildIndex]:
                smallestChildIndex = rightChildIndex
            else:
                smallestChildIndex = leftChildIndex

            # HEAP PROPERTY: parent < child (min heap)
            if self.heap[index] > self.heap[smallestChildIndex]:
                # Swap to restore heap property
                print(self.heap)
                print(f"[{index}]:{self.heap[index]} <-> [{smallestChildIndex}]:{self.heap[smallestChildIndex]}") 
                self.heap[index], self.heap[smallestChildIndex] = self.heap[smallestChildIndex], self.heap[index]
                print(self.heap)
                
                # Move Down
                index = smallestChildIndex 
            else:
                break
    
    def sort(self, array):
        self.heap = array
        
        # Any list can be converted into a heap by 
        # running heapify on the last non-leaf node
          
        lastNonLeafNodeIdx = len(array) // 2 - 1
        self._percolateDown(lastNonLeafNodeIdx)

        # Retrieve
        result = []

        while self.heap:
            result.append(self.pop())

        return result


def main():
    print("Heap Sort")

    heap = Heap()
    print(heap.sort([10, 20, 15, 30, 40, 50, 100, 90, 70, 60]))


"""
    heap = Heap()
    heap.push(15)
    heap.push(8)
    heap.push(12)
    heap.push(10)
    heap.push(7)
    heap.push(5)
    heap.push(3)

 
    heap.pop()
    heap.pop()
    heap.pop()
    heap.pop()
    heap.pop()
    heap.pop()
    heap.pop()
    heap.pop()
"""

if __name__ == "__main__":
    main()


