cls

del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc MyMathOne.c


link.exe MyMathOne.obj user32.lib /DLL /DEF:MyMathOne.def /subsystem:windows

