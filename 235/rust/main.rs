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
    pub fn lowest_common_ancestor(root: Option<Rc<RefCell<TreeNode>>>, p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let a = p.unwrap().borrow().val;
        let b = q.unwrap().borrow().val;

        let mut node = root;        
        while let Some(n) = node.clone() {
            let c = n.borrow().val;
            if ((c >= a && c <= b) || (c <= a && c >= b)) {
                return node;
            }
            if (c < a && c < b) {
                node = n.borrow().right.clone();
            }
            if (c > a && c > b) {
                node = n.borrow().left.clone();
            }
        }
        return None;
    }
}
