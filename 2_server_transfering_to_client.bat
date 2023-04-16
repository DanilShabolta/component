xcopy .\server\build\server.o .\client\build\lib /Y
xcopy .\server\build\DMF.o .\client\build\lib /Y

xcopy .\server\source\IDMF.h .\client\source\lib /Y
xcopy .\server\source\ICF.h .\client\source\lib /Y
xcopy .\server\source\iDefaultMatrix.h .\client\source\lib /Y
xcopy .\server\source\iProMatrix.h .\client\source\lib /Y
xcopy .\server\source\iunknown_.h .\client\source\lib /Y

pause