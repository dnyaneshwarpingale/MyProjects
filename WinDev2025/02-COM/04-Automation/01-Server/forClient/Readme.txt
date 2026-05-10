1) the exprted functionality is provided via interface IMymath which is given in the automationservr.h and required iid and clsid provided in automationserver.h use it accordingly.

2) copy both the dlls(automationserver.dll , automationproxystub.dll) and type library .tlb to c:Windows\system32.

3) Now double click on automationserver.reg file to register automationserver.dll and automationservertypelib.tlb.

4)Now open Administrator command prompt or elevited command in the directory C:\windows\system32 and register automationproxystub.dll by givining the comand :

-> regsvr32.exe AutomationProxyStub.dll

5) Now build and run Your client program.