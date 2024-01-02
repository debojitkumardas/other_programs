package main

import "net/http"

func HandlerReadiness(w http.ResponseWriter, _ *http.Request) {
    RespondWithJSON(w, 200, struct{}{})
}
