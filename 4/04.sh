#delete the 1st & last character in each line of a file

echo "Output of 'sed' command"
echo "======================="
sed 's/^.//;s/.$//' checkFile
echo ''
echo ''


#grep command to find how many lines of a file contain a given word
echo "Output of 'grep' command"
echo "========================"
echo -n "Enter word: "
read kword
echo -n "Enter the filename for search: "
read fname
echo ''
echo "Searching for '$kword'..."
echo ''
echo -n "The selected records are: "
echo ''
grep "$kword" $fname
echo ''
echo -n "Number of lines containes the word '$kword': "
grep -c "$kword" $fname


: 'Awk is a scripting language used for manipulating data and generating reports. The awk command programming language requires no compiling and allows the user to use variables, numeric functions, string functions, and logical operators. 

Awk is a utility that enables a programmer to write tiny but effective programs in the form of statements that define text patterns that are to be searched for in each line of a document and the action that is to be taken when a match is found within a line. Awk is mostly used for pattern scanning and processing. It searches one or more files to see if they contain lines that matches with the specified patterns and then perform the associated actions.'
