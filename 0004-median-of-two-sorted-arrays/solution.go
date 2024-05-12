func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    aL, bL := len(nums1), len(nums2)
    cL := aL + bL
    arr := []int{}
    
    i, j := 0, 0
    for ; i < aL && j < bL; {
        a, b := nums1[i], nums2[j]
        if a <= b{
            arr = append(arr, a)
            i++
        }
        if b < a{
            arr = append(arr, b)
            j++
        }
    }
    for ; i < aL; i++ {
        arr = append(arr, nums1[i])
    }
    for ; j < bL; j++{
        arr = append(arr, nums2[j])
    }
    if cL % 2 == 0 {
        return float64(arr[cL / 2 - 1] + arr[cL / 2]) /2
    }
    return float64(arr[cL / 2])
}
