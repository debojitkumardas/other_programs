package main

import (
	"context"
	"fmt"
	"mongo_golang/controllers"
	"net/http"
	"time"

	"github.com/julienschmidt/httprouter"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

func main() {
    r := httprouter.New()
    uc := controllers.NewUserController(GetSession())
    fmt.Println("Reached here")
    r.GET("/user/:id", uc.GetUser)
    r.POST("/user", uc.CreateUser)
    r.DELETE("/user/:id", uc.DeleteUser)
    http.ListenAndServe("localhost:8080", r)
}

func GetSession() *mongo.Client {
    ctx, cancel := context.WithTimeout(context.Background(), 10 * time.Second)
    defer cancel()
    client, err := mongo.Connect(ctx, options.Client().ApplyURI("mongodb://localhost:27017"))
    if err != nil {
        panic(err)
    }
    return client
}
