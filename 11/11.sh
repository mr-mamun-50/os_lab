echo -n "Username: "
read userName

if id -u "$userName" > /dev/null 2>&1
then last $userName

else 
echo "$userName does not exist!"

fi
