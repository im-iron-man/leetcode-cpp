import "strings"

func wordPattern(pattern string, s string) bool {
    ss := strings.Split(s, " ")
    if len(pattern) != len(ss) {
        return false
    }
    
    m1 := make(map[string]string)
    for i := range pattern {
        if v, ok := m1[pattern[i:i+1]]; ok {
            if v != ss[i] {
                return false
            }
        } else {
            m1[pattern[i:i+1]] = ss[i]
        }
    }
    
    m2 := make(map[string]string)
    for i := range ss {
        if v, ok := m2[ss[i]]; ok {
            if v != pattern[i:i+1] {
                return false
            }
        } else {
            m2[ss[i]] = pattern[i:i+1]
        }
    }
    
    return true
}
