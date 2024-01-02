package main

import (
	"fmt"
	"log"
	"net/http"
	"os"
	"time"

	"github.com/dgrijalva/jwt-go"
)

var MySigninKey = []byte(os.Getenv("SECRET_KEY"))

func GetJWT() (string, error) {
    token := jwt.New(jwt.SigningMethodHS256)
    claims := token.Claims.(jwt.MapClaims)

    claims["authorized"] = true
    claims["client"] = "johndoe"
    claims["aud"] = "billing.jwtgo.io"
    claims["iss"] = "jwtgo.io"
    claims["exp"] = time.Now().Add(time.Minute*1).Unix()

    token_string, err := token.SignedString(MySigninKey)

    if err != nil {
	_ = fmt.Errorf("Something went wrong: %s\n", err.Error())
	return "", err
    }

    return token_string, err
}

func Index(w http.ResponseWriter, _ *http.Request) {
    valid_token, err := GetJWT()
    fmt.Println(valid_token)
    if err != nil {
	fmt.Println("Failed to generate token")
    }
    fmt.Fprintf(w, string(valid_token))

}

func HandleRequests() {
    http.HandleFunc("/", Index)
    log.Fatal(http.ListenAndServe(":8080", nil))
}

func main() {
    HandleRequests()
}
