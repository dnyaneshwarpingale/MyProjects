cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc MyMathTwo.c


link.exe MyMathTwo.obj user32.lib /DLL /subsystem:windows

