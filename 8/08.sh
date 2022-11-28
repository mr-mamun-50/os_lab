TIMEFORMAT=%R

echo "C Program: "
time gcc -o hello hello.c | ./hello

echo ''
echo "Shell script: "
time sh hello.sh


