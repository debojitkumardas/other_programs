package main

import (
	"fmt"
	"log"
	"net/http"
	"os"

	"github.com/go-chi/chi"
	"github.com/go-chi/cors"
	"github.com/joho/godotenv"
)

func main() {
    godotenv.Load(".env")

    port_string := os.Getenv("PORT")
    if port_string == "" {
        log.Fatal("PORT is not found in the environment")
    }

    fmt.Println("PORT:", port_string)

    router := chi.NewRouter()

    router.Use(cors.Handler(cors.Options{
	AllowedOrigins: []string{"https://*", "http://*"},
	AllowedMethods: []string{"GET", "POST", "PUT", "DELETE", "OPTIONS"},
	AllowedHeaders: []string{"*"},
	ExposedHeaders: []string{"Link"},
	AllowCredentials: false,
	MaxAge: 300,
    }))

    v1_router := chi.NewRouter()
    v1_router.Get("/healthz", HandlerReadiness)
    v1_router.Get("/err", HandlerErr)

    router.Mount("/v1", v1_router)

    srv := &http.Server {
	Handler: router,
	Addr: ":" + port_string,
    }

    log.Printf("Sever starting on port %v", port_string)
    err := srv.ListenAndServe()
    if err != nil {
	log.Fatal(err)
    }
}
