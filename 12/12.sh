echo -n "Enter the input file name: "
read fName

echo -n "Starting line: "
read sLine

echo -n "Ending line: "
read eLine

if [ -f $fName ] & [ $sLine -lt $eLine ]
then sed -n ''$sLine','$eLine' 'p'' $fName

else 
echo "The file '$fName' does not exist or you entered an invalid range!"

fi
