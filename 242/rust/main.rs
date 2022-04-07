use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut s_m = HashMap::new();
        for c in s.chars() {
            *s_m.entry(c).or_insert(0) += 1;
        }
        
        let mut t_m = HashMap::new();
        for c in t.chars() {
            *t_m.entry(c).or_insert(0) += 1;
        }
        
        if s_m.len() != t_m.len() {
            return false;
        }
        for (c, n) in &s_m {
            match t_m.get(c) {
                Some(m) => {
                    if n != m {
                        return false;
                    }
                },
                None => {
                    return false;
                }
            }
        }
        return true;
    }
}
