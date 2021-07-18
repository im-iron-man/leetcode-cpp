var globalCache = make(map[int]bool)

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
    isHappy := false
    cache := make(map[int]struct{})
    for {
        if n == 1 {
            isHappy = true
            break
        }
        if v, ok := globalCache[n]; ok {
            isHappy = v
            break
        }
        if _, ok := cache[n]; ok {
            break
        } else {
            cache[n] = struct{}{}
        }
        n = generate(n)
    }
    for k := range cache {
        globalCache[k] = isHappy
    }
    return isHappy
}
