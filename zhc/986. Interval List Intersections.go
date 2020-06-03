func intervalIntersection(A [][]int, B [][]int) [][]int {
    l1,l2 := len(A),len(B)
    i,j:= 0,0
    res := make([][]int,0)
    
    for i<l1 && j<l2 {
        if A[i][1]<B[j][0] {
            i++
        } else if B[j][1] < A[i][0] {
            j++
        }else {
            l := max(A[i][0],B[j][0])
            r := min(A[i][1],B[j][1])
            list := []int{l,r}
            res = append(res,list)
            if A[i][1]>B[j][1] {
                j++
            }else {
                i++
            }
        }
    }
    return res
}

func min(a,b int) int {
    if a<b {
        return a
    }
    return b
}

func max(a,b int) int {
    if a>b {
        return a
    }
    return b
}