@ECHO OFF
if %1==release (
    .\build\release\Game.exe
) else (
    .\build\debug\Game.exe
)

@ECHO ON