package main

import (
	"fmt"
	"log"
	"net/http"
)

func FormHandler(w http.ResponseWriter, r *http.Request) {
    if err := r.ParseForm(); err != nil {
        fmt.Fprintf(w, "ParserForm() error: %v", err)
        return
    }

    fmt.Fprintf(w, "POST request successful")
    name := r.FormValue("name")
    address := r.FormValue("address")
    fmt.Fprintf(w, "Name: %s\n", name)
    fmt.Fprintf(w, "Address: %s\n", address)
}

func HelloHandler(w http.ResponseWriter, r *http.Request) {
    if r.URL.Path != "/hello" {
        http.Error(w, "404 not found", http.StatusNotFound)
        return
    }

    if r.Method != "GET" {
        http.Error(w, "Method is not supported", http.StatusNotFound)
        return
    }

    fmt.Fprintf(w, "hello!")
}

func main() {
    port := 8080

    file_server := http.FileServer(http.Dir("./static"))
    http.Handle("/", file_server)
    http.HandleFunc("/form", FormHandler)
    http.HandleFunc("/hello", HelloHandler)

    fmt.Printf("Starting server at port: %d \n", port)

    if err := http.ListenAndServe(":8080", nil); err != nil {
        log.Fatal(err)
    }
}
