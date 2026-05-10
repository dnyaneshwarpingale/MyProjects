cls

del *.exe 

del *.res

del *.obj

cl.exe /c /EHsc About1.c

rc.exe About1.rc

link.exe About1.obj About1.res user32.lib gdi32.lib /subsystem:windows

