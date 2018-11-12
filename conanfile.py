from conans import ConanFile, MSBuild
import os
import TM_CommonPy  as TM

class TM_CommonCPP_Conan(ConanFile):
    name = "TM_CommonCPP"
    version = "0.1"
    license = "MIT"
    url = "https://github.com/Troy1010/TM_CommonCPP"
    description = "TMinus1010's common C++ library."
    requires= "Plog/0.1@Troy1010/channel"
    generators="visual_studio"
    exports = "RecommendedIntegration.py"
    settings = "os", "compiler", "build_type", "arch" #MSBuild is nonfunctional without this line
    options = {"source_code": [False,True]}
    default_options = {"source_code": False}

    def source(self):
        self.run("git clone -b beta https://github.com/Troy1010/TM_CommonCPP.git")

    def build(self):
        if not self.options.source_code:
            vMSBuild = MSBuild(self)
            vMSBuild.build("TM_CommonCPP/TM_CommonCPP.sln")

    def package(self):
        self.copy("*.h", dst="include", src="TM_CommonCPP/TM_CommonCPP/include")
        if not self.options.source_code:
            self.copy("*.lib", dst="lib", src="TM_CommonCPP", keep_path=False)
        else:
            self.copy("RecommendedIntegration.py")
            self.copy("*", dst="TM_CommonCPP", src="TM_CommonCPP")

    def package_info(self):
        self.cpp_info.includedirs = ['include']
        if not self.options.source_code:
            self.cpp_info.libdirs = ['lib']
            self.cpp_info.libs = ['TM_CommonCPP_Lib.lib']
