class Node:
    def __init__(self):
        self.value = None
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.__root = None
        self.__value_found = None

    def __insert(self,value, tree):
            if value < tree.value:
                if tree.left is None:
                    tree.left = Node()
                    tree.left.value = value
                else:
                    self.__insert(value,tree.left)
            if value >= tree.value:
                if tree.right is None:
                    tree.right = Node()
                    tree.right.value = value
                else:
                    self.__insert(value,tree.right)


    def insert(self, value):
        if self.__root is None:
            self.__root = Node()
            self.__root.value = value
        else:
            self.__insert(value,self.__root)


    def __bfs(self,value,tree):
        queue = []
        leaf = Node()
        queue.append(tree)

        while (queue != []):
            leaf = queue.pop(0)
            if leaf.value == value:
                self.__value_found = True
                return

            if leaf.left != None:
                queue.append(leaf.left)
            if leaf.right != None:
                queue.append(leaf.right)

        return

    def bfs(self, value):
        if self.__root.value == value:
            return True
        else:
            self.__value_found = False
            self.__bfs(value, self.__root)
            return self.__value_found

    def __show(self, tree):
        leaf = Node()
        queue = []
        queue.append(tree)

        while(queue != []):
            leaf = queue.pop(0)
            print leaf.value
            
            if leaf.left is not None:
                queue.append(leaf.left)
            if leaf.right is not None:
                queue.append(leaf.right)

    def show(self):
        self.__show(self.__root)

    def __dfs(self,value,tree, found = False):
        if self.__value_found == True:
            return
        if tree == None:
            return
        if tree.value == value:
            self.__value_found = True
            return
        else:
            self.__dfs(value,tree.left)
            self.__dfs(value,tree.right)
        return

    def dfs(self, value):
        if self.__root.value == value:
            return True
        else:
            self.__value_found = False
            self.__dfs(value, self.__root)
            return self.__value_found
        

def main():
    A = BinaryTree()
    A.insert(4)
    A.insert(5)
    A.insert(3)
    A.insert(6)
    A.insert(2)
    A.show()
    print A.bfs(9)
    print A.bfs(3)
    print A.dfs(3)
    print A.dfs(7)

if __name__ == "__main__":
    main()
