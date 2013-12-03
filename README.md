README
=======

Start Server:
- python -m SimpleHTTPServer

STEPs to Update:
- Edit DynamicUpdate.py
- run: signercli.py --maketargets ../keystore
- run: signercli.py --makerelease ../keystore
- run: signercli.py --maketimestamp ../keystore
- start client (will d/l updated files)