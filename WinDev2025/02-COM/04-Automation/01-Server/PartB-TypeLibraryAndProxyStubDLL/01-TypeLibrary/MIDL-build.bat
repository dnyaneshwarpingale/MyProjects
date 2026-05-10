cls
del *.tlb
del *.c
del *.h

midl.exe /h AutomationProxyStubHeader.h /iid AutomationProxyStubGuids.c /dlldata AutomationProxyStubDLLData.c /proxy AutomationProxyStub.c AutomationServerTypeLib.idl

