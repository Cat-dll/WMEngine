@ECHO OFF

set install=

if "%2"=="install" (
    set install=-DCMAKE_INSTALL=True
)

if "%1"=="release" (
    if not exist release (mkdir release)

    cmake .. -DCMAKE_BUILD_TYPE="Release" %install% -G "Ninja" -B release
    cd release
) else (
    if not exist debug (mkdir debug)
    
    cmake .. -DCMAKE_BUILD_TYPE="Debug" %install% -G "Ninja" -B debug
    cd debug
)

if "%2"=="install" (
    ninja install
) else (
    ninja
)

cd ..

@ECHO ON