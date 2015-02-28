g++ -g -fPIC -c ale_c_wrapper.cpp -o ale_c_wrapper.o -lale
g++ -g ale_c_wrapper.o -shared -o ale_c_wrapper.so -lale
