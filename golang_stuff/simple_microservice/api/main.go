package main

import (
	"fmt"
	"go/token"
	"log"
	"net/http"
	"os"

	"github.com/dgrijalva/jwt-go"
)

var MySigninKey = []byte(os.Getenv("SECRET_KEY"))

func HomePage(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Super Secret Info")
}

func IsAuthorized(endpoint func(http.ResponseWriter, *http.Request)) http.Handler {
	return http.HandleFunc(func(w http.ResponseWriter, r *http.Request){
		if r.Header["Token"] != nil {
			jwt.Parse(r.Header["Token"][0], func(token *jwt.Token) (interface{}, error) {
				if _, ok := token.Method.(*jwt.SigningMethodHMAC); !ok {
					return nil, fmt.Errorf("Invalid signin method")
				}
				aud := "billing.jwtgo.io"
				check_audience := token.Claims.(jwt.MapClaims).VerifyAudience(aud, false)
				if !check_audience {
					return nil, fmt.Errorf("Invalid aud")
				}

				iss := "jwtgo.io"
				check_iss := token.Claims.(jwt.MapClaims).VerifyIssuer(iss, false)
				if !check_iss {
					return nil, fmt.Errorf("Invalid iss")
				}

				return MySigninKey, nil
			})

			if error != nil {
				fmt.Printf(w, error.Error())
			}

			if token.Valid {
				endpoint(w, r)
			} else {
				fmt.Println("")
			}
		}
	})
}

func HandleRequests() {
	http.Handle("/", IsAuthorized(HomePage))
	log.Fatal(http.ListenAndServe(":9001", nil))
}

func main() {
	fmt.Println("server")
	HandleRequests()
}
