/*
桶排序思想
*/

func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
	if t < 0 {
		return false
	}
	if t == 0 {
		magic := make(map[int]int)
		for i := 0; i < len(nums); i++ {
			if j, exist := magic[nums[i]]; exist {
				if i-j <= k {
					return true
				}
			}
			magic[nums[i]] = i
		}
		return false
	}

	magic := make(map[int][2]int)
	for index, num := range nums {
		if num < 0 {
			num -= t-1
		}
		if v, exist := magic[num/t]; exist && index-v[0] <= k {
			return true
		}
		if v, exist := magic[num/t+1]; exist && index-v[0] <= k && v[1]-num <= t {
			return true
		}
		if v, exist := magic[num/t-1]; exist && index-v[0] <= k && num-v[1] <= t {
			return true
		}
		magic[num/t] = [2]int{index, num}
	}
	return false
}