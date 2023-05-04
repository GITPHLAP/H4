package main

import (
	"fmt"
	"math/rand"
	"time"
)

var arrLen = 16

func main() {
	inputArr := generateRandomIntArr()
	start := time.Now()
	mergeSort(inputArr)
	duration := time.Since(start)
	fmt.Println("elapsed time ", duration)
	// fmt.Printf("%+v\n", inputArr)

	// inputArr = generateSortedIntArr()
	// start = time.Now()
	// mergeSort(sortedArray)
	// fmt.Printf("SORTED elapsed time %s\n", time.Since(start))
}

func merge(first []int, last []int) []int {
	final := []int{}

	i := 0
	j := 0

	for i < len(first) && j < len(last) {

		if first[i] < last[j] {
			final = append(final, first[i])
			i++
		} else {
			final = append(final, last[j])
			j++
		}
	}

	for ; i < len(first); i++ {
		final = append(final, first[i])
	}
	for ; j < len(last); j++ {
		final = append(final, last[j])
	}
	return final
}

func mergeSort(arr []int) []int {
	if len(arr) < 2 {
		return arr
	}
	first := mergeSort(arr[:len(arr)/2])
	last := mergeSort(arr[len(arr)/2:])
	return merge(first, last)
}

func generateRandomIntArr() []int {
	result := make([]int, arrLen)
	for i := 0; i < arrLen; i++ {
		result[i] = rand.Intn(9999)
	}
	return result
}
func generateSortedIntArr() []int {
	result := make([]int, arrLen)
	for i := 0; i < arrLen; i++ {
		result[i] = i
	}
	return result
}
