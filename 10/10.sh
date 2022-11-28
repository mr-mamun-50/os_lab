echo -n "Enter the filename: "
read fName

cName=${fName^^}
	
if test -f $fName
	then mv $fName $cName
	echo ''
	echo "Updated name: $cName"

else 
	echo "Filename '$fName' does not exists!"

fi
