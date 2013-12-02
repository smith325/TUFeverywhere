# -*- mode: python -*-



def Datafiles(*filenames, **kw):

    import os    



    def datafile(path, strip_path=True):

        parts = path.split('/')

        path = name = os.path.join(*parts)

        if strip_path:

            name = os.path.basename(path)

        else:

            name = name.replace("../Project/","")

        print name+" "+path+" "+ 'DATA'

        return name, path, 'DATA'



    strip_path = kw.get('strip_path', True)

    return TOC(

        datafile(filename, strip_path=strip_path)

        for filename in filenames

        if os.path.isfile(filename))





docfiles = Datafiles('../Project/DynamicUpdate.py')

dbfile1 = Datafiles('../Project/metadata/current/release.txt',strip_path=False)

dbfile2 = Datafiles('../Project/metadata/current/root.txt', strip_path=False)

dbfile3 = Datafiles('../Project/metadata/current/targets.txt', strip_path=False)

dbfile4 = Datafiles('../Project/metadata/current/timestamp.txt', strip_path=False)



dbfile5 = Datafiles('../Project/metadata/previous/release.txt', strip_path=False)

dbfile6 = Datafiles('../Project/metadata/previous/root.txt', strip_path=False)

dbfile7 = Datafiles('../Project/metadata/previous/targets.txt', strip_path=False)

dbfile8 = Datafiles('../Project/metadata/previous/timestamp.txt', strip_path=False)



a = Analysis(['../Project/example_client.py'],

             pathex=['example_client'],

             hiddenimports=['json','pkg_resources'],

             hookspath=None,

             runtime_hooks=None)

pyz = PYZ(a.pure)

exe = EXE(pyz,

          a.scripts,

          exclude_binaries=True,

          name='example_client',

          debug=False,

          strip=None,

          upx=True,

          console=True )

coll = COLLECT(exe,

               a.binaries,

               a.zipfiles,

               a.datas,

               docfiles,

               dbfile1,

               dbfile2,

               dbfile3,

               dbfile4,

               dbfile5,

               dbfile6,

               dbfile7,

               dbfile8,

               strip=None,

               upx=True,

               name='example_client')
