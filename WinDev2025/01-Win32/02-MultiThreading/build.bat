cls

del *.exe 

del *.res

del *.obj

cl.exe /c /EHsc /D UNICODE window.c

rc.exe Window.rc

link.exe window.obj Window.res user32.lib gdi32.lib kernel32.lib /subsystem:windows
