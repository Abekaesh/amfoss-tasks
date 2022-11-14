package main

import (
	"syscall/js"
	"fmt"
)

var Count int = 0

// Implement the functions here

func increment(this js.Value, inputs []js.Value) interface{}{
	if len(inputs)==0 {
		Count = Count + 1
		return Count
	}
	return nil
}

func decrement(this js.Value, inputs []js.Value) interface{}{
	if len(inputs)==0 {
		Count = Count - 1
		return Count
	}
	return nil
}

func reset(this js.Value, inputs []js.Value) interface{}{
	if len(inputs)==0 {
		Count = 0
		return Count
	}
	return nil
}


	
func main() {
	c := make(chan int, 0)

    fmt.Println("WASM Go Initialized ")
	// register functions
	js.Global().Set("increment",js.FuncOf(increment))
	js.Global().Set("decrement",js.FuncOf(decrement))
	js.Global().Set("reset",js.FuncOf(reset))
	<-c
}
