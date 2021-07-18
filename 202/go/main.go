func generate(n int) int {
    r := 0
    for n > 0 {
        t := n % 10
        r += t * t
        n /= 10
    }
    return r
}

func isHappy(n int) bool {
    cache := make(map[int]struct{})
    for n != 1 {
        if _, ok := cache[n]; ok {
            return false
        } else {
            cache[n] = struct{}{}
        }
        n = generate(n)
    }
    return true
}
