python ..\..\pyinstaller\pyinstaller.py example_client.spec -y

#copy our output into the c project
cp -path dist\example_client\* -destination ..\PyCpp\PyCpp\ -recurse -force
cp ..\PyCpp\PyCpp\inprocsrvr_d.lib .
cp ..\PyCpp\PyCpp\inprocsrvr_d.pdb .
