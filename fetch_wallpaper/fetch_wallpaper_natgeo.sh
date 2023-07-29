#!/bin/bash
# clear cache
PICS="$HOME/Pictures/NatGeo_Wallpaper/"

# download photo-of-the-day page
wget https://nationalgeographic.com/photo-of-the-day -O ${PICS}/photo-of-the-day

# parse the url out from the file
# url=`cat ${PICS}/photo-of-the-day | grep 'images.nationalgeographic.com.*cache.*990x742.jpg' | cut -d '"' -f 2`

# download the photo
# wget https:$url -O ${PICS}/wall${RAND}.jpg

# set the desktop background
# URI="file://${PICS}/wall${RAND}.jpg"
# echo ${URI}
# gsettings set org.gnome.desktop.background picture-options 'centered'
# gsettings set org.gnome.desktop.background picture-uri "${URI}"
