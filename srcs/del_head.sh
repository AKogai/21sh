#!/bin/bash

while read PaTH; do sed -i -e '1,11d' $PaTH; done < temp.txt
 
