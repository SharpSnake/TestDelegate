# Run the following cmds before use of g++ each time

export VCPKG_ROOT=$PWD/vcpkg
export LIBRARY_PATH=$VCPKG_ROOT/installed/x64-linux/lib:\$LIBRARY_PATH
export LD_LIBRARY_PATH=$VCPKG_ROOT/installed/x64-linux/lib:\$LD_LIBRARY_PATH
export C_INCLUDE_PATH=$VCPKG_ROOT/installed/x64-linux/include:\$C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH=$VCPKG_ROOT/installed/x64-linux/include:\$CPLUS_INCLUDE_PATH
echo | g++ -v -x c++ -E -