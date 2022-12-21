#!/bin/bash

isbn=$1

title=$(curl --no-progress-meter "https://iss.ndl.go.jp/api/sru?operation=searchRetrieve&query=isbn=${isbn}&recordPacking=xml" | grep title | sed "s/<[^>]*>//g" | sort | uniq)

echo -e "title is ${title}"
