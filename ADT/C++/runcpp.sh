if test -e ./$1.cpp
then
	echo g++ -std=c++14 -O2 $1.cpp -lm -o $1
	g++ -std=c++14 -O2 $1.cpp -lm -o $1
	if [ $? -eq 0 ]
	then
		echo running $1
		./$1
		echo delete output file
		rm $1
	fi
else
	echo Error: illegal source file name
	echo Usage: ./runcpp.sh file_name_without_.cpp
fi
