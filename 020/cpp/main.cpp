class Tokenizer {
private:
    int i;
    string s;

public:
    Tokenizer(string s) : i(0), s(s) {}
    
    char get() {
        if (i > s.size()) {
            return '\0';
        }
        return s[i];
    }
    
    void consume() {
        i++;
    }
};

class Parser {
private:
    Tokenizer tokenizer;
    map<char, char> m = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    
public:
    Parser(Tokenizer tokenizer) : tokenizer(tokenizer) {}
    
    bool consumeExpr0() {
        char c;
        while ((c = tokenizer.get()) != '\0') {
            if (!consumeExpr1()) {
                return false;
            }
        }
        return true;
    }
    
    bool consumeExpr1() {
        char c1, c2;
        
        c1 = tokenizer.get();
        tokenizer.consume();
        
        if (c1 == ')' || c1 == ']' || c1 == '}') {
            return false;
        }
        
        while ((c2 = tokenizer.get()) != m[c1]) {            
            if (c2 == '\0') {
                return false;
            }
            
            if (!consumeExpr1()) {
                return false;
            }
        }
        
        tokenizer.consume();
        return true;
    }
};

class Solution {
public:
    bool isValid(string s) {
        Tokenizer tokenizer(s);
        Parser parser(tokenizer);
        return parser.consumeExpr0();
    }
};
