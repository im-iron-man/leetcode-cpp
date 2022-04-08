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
    pub fn binary_tree_paths(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<String> {
        if let Some(n) = root {
            let val = n.borrow().val;
            
            if n.borrow().left.is_none() && n.borrow().right.is_none() {
                return vec![val.to_string()];
            }
            
            let left = Solution::binary_tree_paths(n.borrow().left.clone());
            let right = Solution::binary_tree_paths(n.borrow().right.clone());
            
            let mut result = Vec::new();
            for e in left {
                result.push(format!("{}->{}", val, e));
            }
            for e in right {
                result.push(format!("{}->{}", val, e));
            }
            return result;
        }
        return Vec::new();
    }
}
