echo -n "Enter the File/Folder name: "
read fName
if test -d $fName
then echo "It's a directory"
elif test -f $fName
then echo "File exists and it's an ordinary file"
elif test -c $fName
then echo "Character device file"
else 
echo "Not exist"
fi

