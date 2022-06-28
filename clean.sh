#!/bin/bash
#cleans all files without any extension
filestodelete=$(ls | grep -v "\.")
echo $filestodelete
if [ -z "$filestodelete" ]; then echo "No files have been deleted."
else
    echo "Warning. These files are going to be deleted:"
    echo "$filestodelete"
    read -p "Proceed? " -n 1 -r
    if [[ $REPLY =~ ^[Yy] ]]; then
        echo
        rm $filestodelete && echo "Deleted."
    fi
fi
