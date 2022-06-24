make

echo 
echo 1 arg
./minirt
echo 
echo 3 args
./minirt scenes/1.rt scenes/2.rt
echo
echo scenes/
./minirt scenes/
echo
echo scenes/lala.rt
./minirt scenes/lala.rt
echo
echo scenes/err.rrt
./minirt scenes/err.rrt
echo
echo scenes/err1.txt
./minirt scenes/err1.txt
echo
echo scenes/2.rt
./minirt scenes/2.rt
echo
echo correct file:
./minirt scenes/1.rt