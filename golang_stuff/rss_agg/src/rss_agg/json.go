package main

import (
	"encoding/json"
	"log"
	"net/http"
)

func RespondWithError(w http.ResponseWriter, code int, msg string) {
    if code > 499 {
	log.Println("Responding with 5xx error:", msg)
    }

    type ErrResponse struct {
	error string `json:"error"`
    }

    RespondWithJSON(w, code, ErrResponse{
	error: msg,
    })
}

func RespondWithJSON(w http.ResponseWriter, code int, Payload interface{}) {
    dat, err := json.Marshal(Payload)

    if err != nil {
	log.Printf("Failed to marshall JSON response: %v", Payload)
	w.WriteHeader(500)
	return
    }

    w.Header().Add("Content-Type", "application/json")
    w.WriteHeader(code)
    w.Write(dat)
}
