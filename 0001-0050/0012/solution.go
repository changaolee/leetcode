package main

import (
    "fmt"
    "reflect"
)

func intToRoman(num int) string {
    thousands := []string{"", "M", "MM", "MMM"}
    hundreds := []string{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
    tens := []string{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
    ones := []string{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
    return thousands[num/1000] + hundreds[num%1000/100] + tens[num%100/10] + ones[num%10]
}

type Example struct {
    num int
    ans string
}

func main() {
    examples := []Example{
        {3, "III"},
        {58, "LVIII"},
        {1994, "MCMXCIV"},
    }
    for i, example := range examples {
        ans := intToRoman(example.num)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
