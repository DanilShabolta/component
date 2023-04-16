g++ -c ./server/source/server.cpp -o ./server/build/server.o
g++ -c ./server/source/DMF.cpp -o ./server/build/DMF.o

g++ -shared ./server/build/server.o ./server/build/DMF.o -o ./dll/lib/server.dll -Wl,--kill-at

pause

