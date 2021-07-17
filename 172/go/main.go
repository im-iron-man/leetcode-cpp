func trailingZeroes(n int) int {
    r1, c1 := 2, 0
    for r1 <= n {
        c1 += n / r1
        r1 *= 2
    }

    r2, c2 := 5, 0
    for r2 <= n {
        c2 += n / r2
        r2 *= 5
    }

    if c1 < c2 {
        return c1
    } else {
        return c2
    }
}
