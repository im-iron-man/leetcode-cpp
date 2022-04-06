struct Stack {
    vec: Vec<i32>,
}

impl Stack {
    
    fn new() -> Self {
        Stack {
            vec: Vec::new(),
        }
    }
    
    fn push(&mut self, x: i32) {
        self.vec.push(x);
    }
    
    fn pop(&mut self) -> i32 {
        return self.vec.pop().unwrap();
    }
    
    fn peek(&self) -> i32 {
        return self.vec[self.vec.len() - 1];
    }

    
    fn empty(&self) -> bool {
        return self.len() == 0;
    }
    
    fn len(&self) -> usize {
        return self.vec.len();
    }
}

struct MyQueue {
    vec1: Stack,
    vec2: Stack,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {

    fn new() -> Self {
        MyQueue {
            vec1: Stack::new(),
            vec2: Stack::new(),
        }
    }
    
    fn push(&mut self, x: i32) {
        self.vec1.push(x);
    }
    
    fn pop(&mut self) -> i32 {
        while self.vec1.len() > 1 {
            self.vec2.push(self.vec1.pop());
        }
        let t = self.vec1.pop();
        while !self.vec2.empty() {
            self.vec1.push(self.vec2.pop());
        }
        return t;
    }
    
    fn peek(&mut self) -> i32 {
        while self.vec1.len() > 1 {
            self.vec2.push(self.vec1.pop());
        }
        let t = self.vec1.peek();
        while !self.vec2.empty() {
            self.vec1.push(self.vec2.pop());
        }
        return t;
    }
    
    fn empty(&self) -> bool {
        return self.vec1.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */
