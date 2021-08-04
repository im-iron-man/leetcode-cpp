use std::collections::VecDeque;

struct Queue<T> {
    q: VecDeque<T>,
}

impl<T> Queue<T> {
    fn new() -> Queue<T> {
        return Queue::<T> {
            q: VecDeque::<T>::new(),
        };
    }
    
    fn push(&mut self, value: T) {
        self.q.push_back(value);
    }
    
    fn pop(&mut self) -> T {
        return self.q.pop_front().unwrap();
    }
    
    fn peek(&self) -> &T {
        return self.q.get(0).unwrap();
    }
    
    fn size(&self) -> usize {
        return self.q.len();
    }
    
    fn is_empty(&self) -> bool {
        return self.q.is_empty();
    }
}

struct MyStack {
    q1: Queue<i32>,
    q2: Queue<i32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {

    /** Initialize your data structure here. */
    fn new() -> Self {
        return MyStack {
            q1: Queue::<i32>::new(),
            q2: Queue::<i32>::new(),
        }
    }
    
    /** Push element x onto stack. */
    fn push(&mut self, x: i32) {
        while !self.q1.is_empty() {
            self.q2.push(self.q1.pop());
        }
        self.q1.push(x);
        while !self.q2.is_empty() {
            self.q1.push(self.q2.pop());
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    fn pop(&mut self) -> i32 {
        return self.q1.pop();
    }
    
    /** Get the top element. */
    fn top(&self) -> i32 {
        return *self.q1.peek();
    }
    
    /** Returns whether the stack is empty. */
    fn empty(&self) -> bool {
        return self.q1.is_empty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: bool = obj.empty();
 */
