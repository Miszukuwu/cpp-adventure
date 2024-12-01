@echo off
echo Kompilowanie...
echo g++ .\main.cpp .\Player.cpp .\Enemy.cpp .\Functions.cpp .\ReadEnemy.cpp .\Item.cpp -o main
g++ .\main.cpp .\Player.cpp .\Enemy.cpp .\Functions.cpp .\ReadEnemy.cpp .\Item.cpp -o main
echo "Kompilowanie zakonczone"
pause