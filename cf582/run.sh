g++ -o exec/$1.out $1.cpp

echo "Compile Done"
if [ -z "$2" ]
then
./exec/$1.out
else
./exec/$1.out < $2
fi