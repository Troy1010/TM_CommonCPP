##region Settings
bPause = True
##endregion
import os, sys
import TM_CommonPy as TM

try:
    TM.Run("conan create conanfile.py Troy1010/beta -pr conanprofile_OBSEPlugin")
    TM.Run("conan create conanfile_Source.py Troy1010/beta_source -pr conanprofile_OBSEPlugin")
except Exception as e:
    TM.DisplayException(e)
    sys.exit(1)
if bPause:
    TM.DisplayDone()
