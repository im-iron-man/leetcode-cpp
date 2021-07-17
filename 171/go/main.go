func titleToNumber(columnTitle string) int {
    r := 0
    for _, t := range columnTitle {
        r *= 26
        r += int(t - 64)
    }
    return r
}
