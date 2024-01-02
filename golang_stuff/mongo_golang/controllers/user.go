package controllers

import (
	"context"
	"encoding/json"
	"fmt"
	"mongo_golang/models"
	"net/http"

	"github.com/julienschmidt/httprouter"
	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo"
)

type UserController struct {
    session *mongo.Client
}

func (uc UserController) GetUser(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
    id := p.ByName("id")
    oid, err := primitive.ObjectIDFromHex(id)
    if err != nil {
        fmt.Println("Error converting object id string:", err)
        return
    }

    u := models.User{}

    if err := uc.session.Database("mongo-golang").Collection("users").FindOne(context.TODO(), bson.M{"_id": oid}).Decode(&u); err != nil {
        w.WriteHeader(http.StatusNotFound)
        return
    }

    uj, err := json.Marshal(u)
    if err != nil {
        fmt.Println(err)
    }

    w.Header().Set("Content-Type", "application/json")
    w.WriteHeader(http.StatusOK)
    fmt.Fprintf(w, "%s\n", uj)
}

func (uc UserController) CreateUser(w http.ResponseWriter, r *http.Request, _ httprouter.Params) {
    u := models.User{}

    json.NewDecoder(r.Body).Decode(&u)

    u.ID = primitive.NewObjectID()
    if _, err := uc.session.Database("mongo-golang").Collection("users").InsertOne(context.TODO(), u); err != nil {
        w.WriteHeader(http.StatusInternalServerError)
        return
    }

    uj, err := json.Marshal(u)
    if err != nil {
        fmt.Println(err)
    }

    w.Header().Set("Content-Type", "application/json")
    w.WriteHeader(http.StatusCreated)
    fmt.Fprintf(w, "%s\n", uj)
}

func (uc UserController) DeleteUser(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
    id := p.ByName("id")

    oid, err := primitive.ObjectIDFromHex(id)
    if err != nil {
        w.WriteHeader(http.StatusNotFound)
        return
    }

    if _, err := uc.session.Database("mongo-golang").Collection("users").DeleteOne(context.TODO(), oid); err != nil {
        w.WriteHeader(http.StatusNotFound)
        return
    }

    w.WriteHeader(http.StatusOK)
    fmt.Fprint(w, "Delete user ", oid, "\n")
}

func NewUserController(s *mongo.Client) *UserController {
    return &UserController{s}
}
