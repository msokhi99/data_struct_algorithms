from bst_class import BinarySearchTree

tree=BinarySearchTree()

tree.insert(10)
tree.insert(2)
tree.insert(15)

print(tree.root.value)
print(tree.root.left.value)
print(tree.root.right.value)

print(tree.contains(25))
