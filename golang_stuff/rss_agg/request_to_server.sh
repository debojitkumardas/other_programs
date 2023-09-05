# For more details regarding the curl -w refer to: https://stackoverflow.com/questions/18215389/how-do-i-measure-request-and-response-times-at-once-using-curl

LOCALHOST="http://localhost"
PORT=":8080/"
VERSION="v1/"
ROUTES_HEALTHZ="healthz"
ROUTES_ERR="err"

get_request() {
    (curl -i -w "\\ntime: %{time_total} s\\nsize: %{size_download} bytes \\n" -G $LOCALHOST$PORT$VERSION$ROUTES_HEALTHZ)
}

post_request() {
    (curl -i -w "\\ntime: %{time_total} s\\nsize: %{size_download} bytes \\n" -d postthis $LOCALHOST$PORT$VERSION$ROUTES_HEALTHZ)
}

err_request() {
    (curl -i -w "\\ntime: %{time_total} s\\nsize: %{size_download} bytes \\n" -G $LOCALHOST$PORT$VERSION$ROUTES_ERR)
}

if [ $1 == "get" ] ; then
    get_request
elif [ $1 == "post" ] ; then
    post_request
elif [ $1 == "err" ] ; then
    err_request
else
    echo "Provide relevant command line argument"
fi
