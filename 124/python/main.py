# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:   
    path = 0
    
    def f(self, root: TreeNode) -> List[int]:
        leftVal = root.val
        if root.left is not None:
            leftVal0, rightVal0 = self.f(root.left)
            leftVal += max(0, leftVal0, rightVal0)

        rightVal = root.val
        if root.right is not None:
            leftVal0, rightVal0 = self.f(root.right)
            rightVal += max(0, leftVal0, rightVal0)

        self.path = max(self.path, leftVal + rightVal - root.val)

        return [leftVal, rightVal]
    
    def maxPathSum(self, root: TreeNode) -> int:
        self.path = root.val
        self.f(root)
        return self.path

