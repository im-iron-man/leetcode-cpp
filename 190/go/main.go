func reverseBits(num uint32) uint32 {
    t := uint32(0)
    for i := 0; i < 32; i++ {
        t *= 2
        t += num & 1
        num >>= 1
    }
    return t
}
