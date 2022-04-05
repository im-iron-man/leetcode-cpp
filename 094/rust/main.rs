// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn inorder_traversal0(root: Option<Rc<RefCell<TreeNode>>>, r: &mut Vec<i32>) {
        match root {
            Some(root) => {
                Solution::inorder_traversal0(root.borrow().left.clone(), r);
                r.push(root.borrow().val);
                Solution::inorder_traversal0(root.borrow().right.clone(), r);
            },
            None => (),
        }
    }
    
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut r = Vec::new();
        Solution::inorder_traversal0(root, &mut r);
        r
    }
}
