echo Compiling source code
gcc -g $1.c -o $1
echo Run $1
./$1
echo delete output file : $1
rm -f $1
