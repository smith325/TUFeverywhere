# -*- mode: python -*-
a = Analysis(['..\\Project'],
             pathex=['C:\\Users\\Sarah\\Documents\\GitHub\\TUFeverywhere\\PyInstall\\Project'],
             hiddenimports=[],
             hookspath=None,
             runtime_hooks=None)
pyz = PYZ(a.pure)
exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          name='Project.exe',
          debug=False,
          strip=None,
          upx=True,
          console=True )
