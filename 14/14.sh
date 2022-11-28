echo -n "Enter a string: "
read str

echo ''

echo -n "Enter the start index of string: "
read sInd;

echo -n "Enter the last index of string: "
read eInd;

echo ''

if [ $sInd -lt $eInd ]
	then echo -n "The new substring is: "
	echo ${str:$sInd:$eInd}

else
	echo "Invalid! Start index is greater than end index"
	
fi

echo "The length of original string is: ${#str}"


