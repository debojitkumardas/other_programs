#!/bin/bash
# author: Whizzzkid (me@nishantarora.in)
# this file is the work of Whizzkid (https://github.com/whizzzkid/bing-wallpapers-for-linux/blob/master/bingwallpaper)
# added some modifications as it was not working in fedora linux

# Base URL.
bing="http://www.bing.com"

# API end point.
api="/HPImageArchive.aspx?"

# Response Format (json|xml).
format="&format=js"

# For day (0=current; 1=yesterday... so on).
day="&idx=0"

# Market for image.
market="&mkt=en-US"

# API Constant (fetch how many).
const="&n=1"

# Image extension.
extn=".jpg"

# Size.
size="1920x1200"

# Collection img_path.
img_path="$HOME/Pictures/Bing_Wallpaper/"
copyright_path=$img_path"copyright/"

background_path="$HOME/.local/share/backgrounds/"

# Required Image Uri.
reqImg=$bing$api$format$day$market$const

if [ ! -d $img_path ]; then
  mkdir -p $img_path
fi

if [ ! -d $copyright_path ]; then
  echo "Directory doesn't exist!! Creating $copyright_path"
  mkdir -p $copyright_path
fi

download_img() {
  # Logging.
  echo "Pinging Bing API..."

  # Fetching API response.
  apiResp=$(curl -s $reqImg)
  if [ $? -gt 0 ]; then
    echo "Ping failed!"
    exit 1
  fi

  # Default image URL in case the required is not available.
  defImgURL=$bing$(echo $apiResp | grep -oP "url\":\"[^\"]*" | cut -d "\"" -f 3)

  # Req image url (raw).
  reqImgURL=$bing$(echo $apiResp | grep -oP "urlbase\":\"[^\"]*" | cut -d "\"" -f 3)"_"$size$extn

  # Image copyright.
  copyright=$(echo $apiResp | grep -oP "copyright\":\"[^\"]*" | cut -d "\"" -f 3)

  # Checking if reqImgURL exists.
  if ! wget --quiet --spider --max-redirect 0 $reqImgURL; then
    reqImgURL=$defImgURL
  fi

  # Logging.
  echo "Bing Image of the day: $reqImgURL"

  # Getting Image Name.
  imgName=${reqImgURL##*/}

  # Saving Image to collection.
  curl -L -s -o $img_path$imgName $reqImgURL

  # for the background dir
  alt_name="bing_photo_of_the_day.jpg"
  rm -rf $background_path$alt_name
  curl -L -s -o $background_path$alt_name $reqImgURL

  # Logging.
  echo "Saving image to $img_path$imgName"
  echo "Saving image to $background_path$alt_name"

  # Writing copyright.
  echo "$copyright" > $copyright_path${imgName/%.jpg/.txt}

  echo "New wallpaper downloaded successfully for $XDG_CURRENT_DESKTOP."
}

download_img
