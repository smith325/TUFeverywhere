python ..\..\pyinstaller\pyinstaller.py example_client.spec -y

#copy our output into the c project
cp -path dist\example_client\* -destination ..\PyCpp\PyCpp\ -recurse -force
cp ..\..\pyinstaller\bootloader\build\debug\inprocsrvr_d.lib ..\PyCpp\PyCpp\inprocsrvr_d.lib
cp ..\..\pyinstaller\bootloader\windows\dllmain.h ..\PyCpp\PyCpp\dllmain.h
