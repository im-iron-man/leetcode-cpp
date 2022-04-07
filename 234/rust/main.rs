// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        let mut s = Vec::new();
        let mut next = &head;
        while let Some(t) = next {
            s.push(t.val);
            next = &t.next;
        }
        
        let mut next = &head;
        while let Some(t) = next {
            if t.val != s.pop().unwrap() {
                return false;
            }
            next = &t.next;
        }
        return true;
    }
}
