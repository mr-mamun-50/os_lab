echo -n "Enter the keyword: "
read word

for i in $*
	do
		if [ ! -f $file_name ]
			then echo "File \"$file_name\" does not exist!"
			exit 1
		fi
		
		echo $i
		echo "======================"
		grep -v $word $i
done
