g++ -c ./dll/manager.cpp -o ./dll/build/manager.o

g++ -shared ./dll/build/manager.o -o ./client/source/lib/manager.dll -Wl,--kill-at

pause