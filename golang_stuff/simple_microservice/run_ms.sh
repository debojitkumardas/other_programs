create_token() {
    curl http://localhost:$1 > token.txt
}

get_token() {
    input="./token.txt"
    while read p || [ -n "$p" ]
    do
        curl http://localhost:$1 --header "Token: $p"
    done < "$input"
    printf '\n'
}

if [ $1 == 1 ] ; then
    create_token "$2"
elif [ $1 == 2 ] ; then
    get_token "$2"
fi
